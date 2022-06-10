// @file      narf_icp.hpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#ifndef DLOAM_ROS_REGISTRATION_NARF_ICP_HPP_
#define DLOAM_ROS_REGISTRATION_NARF_ICP_HPP_
#include <memory>
#include <string>

#include <dloam/aligner.hpp>
#include <dloam/keypoint_detector.hpp>
#include <dloam/keypoints.hpp>

#include <dloam_ros/registration/icp_strategy.hpp>

namespace dloam_ros {

class NARF_ICP : public ICPStrategy {
 public:
  explicit NARF_ICP(bool has_keypoints = false, bool has_depth = true,
                    bool has_correspon = true);
  ~NARF_ICP() = default;

  inline std::string Strategy() const override { return "NARF_ICP"; }
  void ProcessFirstCloud(const PointCloud::ConstPtr& first_cloud) override;
  void RegisterNewCloud(const PointCloud::ConstPtr& input_cloud) override;
  const Correspondences GetCorrespondences() const override;
  const cv::Mat_<float> GetDepthImage() const override;
  // We are taking the input keypoints as input_cloud, so there is no real need
  // to publish this again through the data flow const CornerKeypoints
  // GetKeypoints() const override;

 private:
  dloam::Keypoints::SharedPtr DetectKeypoints(
      const PointCloud::ConstPtr& keypoints);

  // DLOAM aligner
  dloam::Aligner aligner_;
  dloam::Keypoints::SharedPtr static_keypoints_;
  dloam::Keypoints::SharedPtr moving_keypoints_;

  // Local storage
  PointCloud::Ptr target_keypoints_;
  PointCloud::Ptr current_keypoints_;
};

}  // namespace dloam_ros

#endif  // DLOAM_ROS_REGISTRATION_NARF_ICP_HPP_
