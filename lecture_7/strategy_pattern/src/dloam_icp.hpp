// @file      dloam_icp.hpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#ifndef DLOAM_ROS_REGISTRATION_DLOAM_ICP_HPP_
#define DLOAM_ROS_REGISTRATION_DLOAM_ICP_HPP_

#include <ipb_core/cloud.h>

#include <memory>
#include <string>

#include <dloam/aligner.hpp>
#include <dloam/keypoint_detector.hpp>
#include <dloam/keypoints.hpp>

#include <dloam_ros/registration/icp_strategy.hpp>
#include <opencv2/core.hpp>

namespace dloam_ros {

class DLOAM : public ICPStrategy {
 public:
  explicit DLOAM(bool has_keypoints = true, bool has_depth = true,
                 bool has_correspon = true);
  ~DLOAM() = default;

  inline std::string Strategy() const override { return "DLOAM"; }
  void ProcessFirstCloud(const PointCloud::ConstPtr& first_cloud) override;
  void RegisterNewCloud(const PointCloud::ConstPtr& input_cloud) override;
  const Correspondences GetCorrespondences() const override;
  const CornerKeypoints GetKeypoints() const override;
  const cv::Mat_<float> GetDepthImage() const override;

 private:
  inline dloam::Keypoints::SharedPtr DetectKeypoints(
      const ipb::Cloud::Ptr& scan) {
    return std::make_shared<dloam::Keypoints>(
        detector_.DetectKeypoints(scan->images().point_image));
  }

  // DLOAM aligner
  dloam::Aligner aligner_;
  dloam::KeypointDetector detector_;
  dloam::Keypoints::SharedPtr static_keypoints_;
  dloam::Keypoints::SharedPtr moving_keypoints_;

  // Local storage
  ipb::Cloud::Ptr target_scan_;
  ipb::Cloud::Ptr current_scan_;
};

}  // namespace dloam_ros

#endif  // DLOAM_ROS_REGISTRATION_DLOAM_ICP_HPP_
