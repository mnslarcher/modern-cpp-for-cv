// @file      pcl_icp.cpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
// Inspired by https://github.com/koide3/hdl_graph_slam
#include <pcl/conversions.h>

#include <Eigen/Core>
#include <memory>
#include <utility>

#include <dloam_ros/common/pcl_icp_selector.hpp>
#include <dloam_ros/registration/icp_strategy.hpp>
#include <dloam_ros/registration/pcl_icp.hpp>

namespace dloam_ros {

PCL_ICP::PCL_ICP(pcl_icp::RegistrationPtr method, bool has_keypoints,
                 bool has_depth, bool has_correspon)
    : ICPStrategy(has_keypoints, has_depth, has_correspon),
      icp_(std::move(method)) {
  downsample_filter_ = std::make_shared<pcl::VoxelGrid<PointCloud>>();
  downsample_filter_->setLeafSize(leaf_, leaf_, leaf_);
}

PCL_ICP::PointCloud::Ptr PCL_ICP::Downsample(
    const PointCloud::ConstPtr& cloud) const {
  PointCloud::Ptr filtered(new PointCloud());
  downsample_filter_->setInputCloud(cloud);
  downsample_filter_->filter(*filtered);
  return filtered;
}

void PCL_ICP::ProcessFirstCloud(const PointCloud::ConstPtr& first_msg) {
  if (!initialized_) {
    // Convert fromPCLPointCloud2 to pcl::PointCloud<T>
    pcl_icp::PointCloud::Ptr first_cloud(new pcl_icp::PointCloud());
    pcl::fromPCLPointCloud2(*Downsample(first_msg), *first_cloud);

    // Cleanup local storage
    initial_guess_.setIdentity();
    deltas_.emplace_back(Eigen::Isometry3f::Identity());
    poses_.emplace_back(Eigen::Matrix4f::Identity());

    // Initialize ICP
    current_scan_ = first_cloud;
    icp_->setInputTarget(current_scan_);
    initialized_ = true;
  }
}

void PCL_ICP::RegisterNewCloud(const PointCloud::ConstPtr& input_msg) {
  // Explain and Refactor
  Initialize();

  // Convert fromPCLPointCloud2 to pcl::PointCloud<T>
  pcl_icp::PointCloud::Ptr input_cloud(new pcl_icp::PointCloud());
  pcl::fromPCLPointCloud2(*Downsample(input_msg), *input_cloud);

  // Use the last scan as target scan
  target_scan_ = std::move(current_scan_);
  icp_->setInputTarget(target_scan_);

  // Use the input_transformed as the current_scan_ for the alignment
  current_scan_ = input_cloud;
  icp_->setInputSource(current_scan_);

  // Perform the ICP
  pcl_icp::PointCloud::Ptr aligned(new pcl_icp::PointCloud());
  icp_->align(*aligned, initial_guess_.matrix());

  if (!icp_->hasConverged()) {
    ROS_WARN("PCL_ICP::RegisterNewCloud:: scan matching has not converged!!");
    deltas_.emplace_back(tx_absolute_pose_ * initial_guess_);
    return;
  }

  // Store current transformation
  Eigen::Isometry3f current_transformation;
  current_transformation.matrix() = icp_->getFinalTransformation();
  deltas_.emplace_back(current_transformation);

  // Update current pose and poses vector
  tx_absolute_pose_ = tx_absolute_pose_ * last_delta();
  poses_.emplace_back(tx_absolute_pose_.matrix());
}

}  // namespace dloam_ros
