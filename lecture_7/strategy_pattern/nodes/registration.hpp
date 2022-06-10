// @file      registration.hpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#ifndef DLOAM_ROS_COMMON_REGISTRATION_HPP_
#define DLOAM_ROS_COMMON_REGISTRATION_HPP_
#include <pcl/PCLPointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>

#include <nav_msgs/Path.h>
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

#include <Eigen/Core>
#include <memory>
#include <string>
#include <vector>

#include <dloam_ros/keypoints/correspondences_markers.hpp>
#include <dloam_ros/keypoints/keypoints_publisher.hpp>
#include <dloam_ros/projections/depth_img.hpp>
#include <dloam_ros/registration/icp_strategy.hpp>

namespace dloam_ros {

/**
 * @brief RegistrationNode Interface
 *
 */
class RegistrationNode {
 protected:
  using PointCloud = pcl::PCLPointCloud2;

 public:
  explicit RegistrationNode(const ros::NodeHandle& pnh,
                            ICPStrategy::Ptr icp_strategy);

 private:
  /**
   * @brief TODO(Nacho): Explain that This is the most important Callback in the
   * whole pipeline
   *
   * @param input_cloud
   */
  void CloudCallback(const PointCloud::ConstPtr& input_cloud);

  /**
   * @brief TODO(Nacho): Explain why we need so many layers of initialization
   *
   * @param input_cloud
   */
  void Initialize(const PointCloud::ConstPtr& input_cloud);

 private:
  /**
   * @brief
   *
   * @param odom
   */
  inline void PublishOdometry(const Eigen::Isometry3f& odom);

  /**
   * @brief
   *
   * @param tf
   * @param frame_id
   * @param child_frame_id
   */
  inline void BroadcastFrame(const Eigen::Isometry3f& tf,
                             const std::string& header_frame_id,
                             const std::string& child_frame_id);

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool ReadParameters();

  ros::NodeHandle pnh_;
  ros::Publisher last_scan_pub_;
  ros::Publisher odom_pose_pub_;
  ros::Publisher odom_path_pub_;
  ros::Subscriber input_pcl_sub_;

  // Odometry odom_path, TODO: we could put this on a separate node that builds
  // the path while being subscribed to the odometry msg
  nav_msgs::Path odom_path_;

  /// Latch the message when publishing
  bool latch_;

  /// Queue size for the published message
  uint32_t queue_size_;
  uint32_t current_scan_;
  ros::Time current_timestamp_;

  // Depth publisher and 3D point cloud markers
  dloam_ros::DepthImgPub depth_pub_;
  dloam_ros::CorrespondencesMarkers corr_pub_;
  dloam_ros::KeypointsPublisher keypoints_pub_;

  tf::TransformBroadcaster tfBroadcaster_;

  /// unique_ptr to the ICP Strategy
  ICPStrategy::Ptr ICP = nullptr;

  // Node parameters
  std::string input_cloud_topic_ = "point_cloud/current_scan";
  std::string keypoints_topic_ = "corner_keypoints";
  std::string depth_img_topic_ = "depth_img";
  std::string depth_map_topic_ = "depth_map";
  std::string correspond_topic_ = "correspondences";
  std::string odometry_topic_ = "odometry";
  std::string odom_path_topic_ = "odometry_path";
  std::string velodyne_frame_last_ = "velodyne_frame_last";
  std::string velodyne_frame_ = "velodyne_frame";
  std::string initial_guess_frame_ = "initial_guess";

  bool initialize_identity_ = true;
  double delta_trans_th_ = 0.0;
  double delta_angle_th_ = 0.0;
};

}  // namespace dloam_ros

#endif  // DLOAM_ROS_COMMON_REGISTRATION_HPP_
