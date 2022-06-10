// @file      narf_icp.cpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#include <pcl/conversions.h>

#include <Eigen/Core>
#include <utility>

#include <dloam/aligner.hpp>
#include <dloam/keypoints.hpp>

#include <dloam_ros/registration/icp_strategy.hpp>
#include <dloam_ros/registration/narf_icp.hpp>

#include <ipb_kitti/pcl_conversions.hpp>

#include <opencv2/core.hpp>

namespace dloam_ros {

NARF_ICP::NARF_ICP(bool has_keypoints, bool has_depth, bool has_correspon)
    : ICPStrategy(has_keypoints, has_depth, has_correspon) {}

void NARF_ICP::ProcessFirstCloud(const PointCloud::ConstPtr& first_keypoints) {
  if (!initialized_) {
    initial_guess_.setIdentity();
    deltas_.emplace_back(Eigen::Isometry3f::Identity());
    poses_.emplace_back(Eigen::Matrix4f::Identity());
    current_keypoints_.reset(new PointCloud(*first_keypoints));
    initialized_ = true;
  }
}

void NARF_ICP::RegisterNewCloud(const PointCloud::ConstPtr& input_keypoints) {
  // Explain and refactor
  Initialize();

  // Use the last scan as target scan
  target_keypoints_ = current_keypoints_;
  current_keypoints_.reset(new PointCloud(*input_keypoints));

  moving_keypoints_ = DetectKeypoints(current_keypoints_);
  static_keypoints_ = DetectKeypoints(target_keypoints_);

  // Store current transformation and Perform the ICP
  deltas_.emplace_back(aligner_.RegisterClouds(
      moving_keypoints_, static_keypoints_, initial_guess_));

  // Update current pose and poses vector
  tx_absolute_pose_ = tx_absolute_pose_ * last_delta();
  poses_.emplace_back(tx_absolute_pose_.matrix());
}

dloam::Keypoints::SharedPtr NARF_ICP::DetectKeypoints(
    const PointCloud::ConstPtr& keypoints) {
  auto dloam_keypoints =
      std::make_shared<dloam::Keypoints>(keypoints->height, keypoints->width);
  for (auto& corner : ipb::pcl_conversions::ConvertKeypoints(keypoints)) {
    dloam_keypoints->Add(corner);
  }
  return dloam_keypoints;
}

const cv::Mat_<float> NARF_ICP::GetDepthImage() const {
  // Obtain the depth_image from the current_keypoints
  if (current_keypoints_ != nullptr || !initialized_) {
    return ipb::pcl_conversions::GetDepthImage(current_keypoints_).cv_image();
  }
}

const NARF_ICP::Correspondences NARF_ICP::GetCorrespondences() const {
  return aligner_.latest_correspondences();
}

}  // namespace dloam_ros
