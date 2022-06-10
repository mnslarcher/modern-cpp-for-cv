// @file      icp_strategy.hpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#ifndef DLOAM_ROS_REGISTRATION_ICP_STRATEGY_HPP_
#define DLOAM_ROS_REGISTRATION_ICP_STRATEGY_HPP_
#include <glog/logging.h>
#include <ipb_core/utils/types.h>
#include <pcl/PCLPointCloud2.h>

#include <Eigen/Core>
#include <cmath>
#include <memory>
#include <string>
#include <vector>

#include <opencv2/core.hpp>

namespace dloam_ros {

/**
 * @brief ICPStrategy Interface
 *
 */
class ICPStrategy {
 protected:
  using PointCloud = pcl::PCLPointCloud2;
  using Correspondences = ipb::types::Correspondences;
  using CornerKeypoints = ipb::types::CornerKeypoints;

  /**
   * @brief Construct a new ICPStrategy object
   *
   * @param has_keypoints
   * @param has_depth
   * @param has_correspon
   */

  explicit inline ICPStrategy(bool has_keypoints, bool has_depth,
                              bool has_correspon)
      : has_keypoints_(has_keypoints),
        has_depth_map_(has_depth),
        has_correspon_(has_correspon) {}

 public:
  using Ptr = std::unique_ptr<ICPStrategy>;
  using SharedPtr = std::shared_ptr<ICPStrategy>;

  virtual ~ICPStrategy() = default;

  /**
   * @brief
   *
   * @param first_cloud
   */
  virtual void ProcessFirstCloud(const PointCloud::ConstPtr& first_msg) = 0;

  /**
   * @brief
   *
   * @param input_cloud
   */
  virtual void RegisterNewCloud(const PointCloud::ConstPtr& input_msg) = 0;

  /**
   * @brief
   *
   * @return std::string
   */
  virtual std::string Strategy() const = 0;

  /**
   * @brief Get the Correspondences object
   *
   * @return const Correspondences
   */
  virtual const Correspondences GetCorrespondences() const {
    LOG(FATAL) << "ICPStrategy::GetCorrespondences() not yet implemented";
  }

  /**
   * @brief Get the Corner Keypoints object
   *
   * @return const CornerKeypoints
   */
  virtual const CornerKeypoints GetKeypoints() const {
    LOG(FATAL) << "ICPStrategy::GetKeypoints() method not yet implemented";
  }

  /**
   * @brief Get the Depth Image object
   *
   * @return const cv::Mat_<float>
   */
  virtual const cv::Mat_<float> GetDepthImage() const {
    LOG(FATAL) << "ICPStrategy::GetDepthImage() method not yet implemented";
  }

  /**
   * @brief
   *
   */
  virtual void Initialize() {
    if (initialize_identity_) {
      initial_guess_.setIdentity();
    } else {
      const double delta_trans = last_delta().translation().norm();
      // const double delta_angle = std::acos(last_delta().rotation().w());
      // //FIXME: Fix this shit
      if (delta_trans >= delta_trans_th_) {
        initial_guess_.setIdentity();
      } else {
        initial_guess_ = last_delta();
      }
    }
  }

  /// Getters
  void initialize_identity(const bool& value) { initialize_identity_ = value; }

  const std::vector<Eigen::Matrix4f> poses() const { return poses_; }
  const Eigen::Matrix4f current_pose() const { return poses_.back(); }
  const Eigen::Isometry3f tx_absolute_pose() const { return tx_absolute_pose_; }

  const std::vector<Eigen::Isometry3f> deltas() const { return deltas_; }
  const Eigen::Isometry3f last_delta() const { return deltas_.back(); }
  const Eigen::Isometry3f before_last_delta() const {
    return *(deltas_.end() - 2);
  }
  const Eigen::Isometry3f initial_guess() const { return initial_guess_; }

  bool initialized() const { return initialized_; }
  bool has_keypoints() const { return has_keypoints_; }
  bool has_depth_map() const { return has_depth_map_; }
  bool has_correspondences() const { return has_correspon_; }
  bool initialize_identity() const { return initialize_identity_; }

  inline void set_delta_trans_th(double th) { delta_trans_th_ = th; }
  inline void set_delta_angle_th(double th) { delta_angle_th_ = th; }

 protected:
  std::vector<Eigen::Matrix4f> poses_;
  Eigen::Isometry3f tx_absolute_pose_ = Eigen::Isometry3f::Identity();

  // Store all the incremental transformation between consecutive scans.
  std::vector<Eigen::Isometry3f> deltas_;
  Eigen::Isometry3f initial_guess_ = Eigen::Isometry3f().Identity();

  // TODO(Nacho): Tune this parameters
  double delta_trans_th_ = 1.0;
  double delta_angle_th_ = 0.15;

  // Boolean value to know if the ICP is initalized or not, void
  // Initialize(); is responsible for setting this flag after
  // initialization
  bool initialized_ = false;

  // Initialize the ICP with Identity
  bool initialize_identity_ = true;

  /// Explain why we need this
  bool has_keypoints_ = false;
  bool has_depth_map_ = false;
  bool has_correspon_ = false;
};  // namespace dloam_ros

}  // namespace dloam_ros

#endif  // DLOAM_ROS_REGISTRATION_ICP_STRATEGY_HPP_
