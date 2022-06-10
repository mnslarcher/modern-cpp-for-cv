// @file      dloam_icp.cpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#include <Eigen/Core>
#include <utility>

#include <dloam/aligner.hpp>
#include <dloam/keypoint_detector.hpp>
#include <dloam/keypoints.hpp>

#include <dloam_ros/registration/dloam_icp.hpp>
#include <dloam_ros/registration/icp_strategy.hpp>
#include <ipb_kitti/pcl_conversions.hpp>
#include <opencv2/core.hpp>

namespace dloam_ros {

DLOAM::DLOAM(bool has_keypoints, bool has_depth, bool has_correspon)
    : ICPStrategy(has_keypoints, has_depth, has_correspon) {}

void DLOAM::ProcessFirstCloud(const PointCloud::ConstPtr& first_cloud) {
  if (!initialized_) {
    initial_guess_.setIdentity();
    deltas_.emplace_back(Eigen::Isometry3f::Identity());
    poses_.emplace_back(Eigen::Matrix4f::Identity());
    current_scan_ = ipb::pcl_conversions::Convert2IPB(first_cloud);
    initialized_ = true;
  }
}

void DLOAM::RegisterNewCloud(const PointCloud::ConstPtr& input_cloud) {
  // Explain and refactor
  Initialize();

  // Use the last scan as target scan
  target_scan_ = std::move(current_scan_);
  current_scan_ = ipb::pcl_conversions::Convert2IPB(input_cloud);

  moving_keypoints_ = DetectKeypoints(current_scan_);
  static_keypoints_ = DetectKeypoints(target_scan_);

  // Store current transformation and Perform the ICP
  deltas_.emplace_back(aligner_.RegisterClouds(
      moving_keypoints_, static_keypoints_, initial_guess_));

  // Update current pose and poses vector
  tx_absolute_pose_ = tx_absolute_pose_ * last_delta();
  poses_.emplace_back(tx_absolute_pose_.matrix());
}

const DLOAM::CornerKeypoints DLOAM::GetKeypoints() const {
  return moving_keypoints_->corners();
}

const cv::Mat_<float> DLOAM::GetDepthImage() const {
  // Obtain the depth_image from the ipb_cloud
  if (current_scan_ != nullptr || !initialized_) {
    return (current_scan_->images().depth_image).cv_image();
  }
}

const DLOAM::Correspondences DLOAM::GetCorrespondences() const {
  return aligner_.latest_correspondences();
}

}  // namespace dloam_ros
