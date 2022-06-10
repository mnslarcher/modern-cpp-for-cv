// @file      ICP.cpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#include <dloam.h>  // For dynamic_reconfigure
#include <dynamic_reconfigure/server.h>
#include <ros/ros.h>
#include <memory>

#include <dloam_ros/dloamConfig.h>
#include <dloam_ros/common/registration.hpp>
#include <dloam_ros/registration/dloam_icp.hpp>

namespace dloam_ros {

#define LOG_DLOAM_PARAMETER(param) \
  ROS_DEBUG_STREAM(#param << " = " << ::FLAGS_##param);

#define LOG_DLOAM_BOOL_PARAMETER(param) \
  ROS_DEBUG_STREAM(#param << " = " << std::boolalpha << ::FLAGS_##param);

/// Callback function for dynamic reconfigure server.
void configCallback(const dloam_ros::dloamConfig& config,
                    uint32_t level __attribute__((unused))) {
  ROS_DEBUG("Reconfigure dloam ICP requested");

  // Update all the gflags used for the dloam-ICP
  ::FLAGS_aligner_chi_robust_kernel = config.aligner_chi_robust_kernel;
  ::FLAGS_aligner_iteration_chi_threshold =
      config.aligner_iteration_chi_threshold;
  ::FLAGS_aligner_max_iterations = config.aligner_max_iterations;
  ::FLAGS_matcher_max_dist = config.matcher_max_dist;
  ::FLAGS_matcher_symmetric = config.matcher_symmetric;
  ::FLAGS_matcher_window_rows = config.matcher_window_rows;
  ::FLAGS_matcher_window_cols = config.matcher_window_cols;
  ::FLAGS_corner_line_dist = config.corner_line_dist;
  ::FLAGS_corner_min_point_dist = config.corner_min_point_dist;
  ::FLAGS_corner_max_point_dist = config.corner_max_point_dist;
  ::FLAGS_corner_detector_step = config.corner_detector_step;

  LOG_DLOAM_PARAMETER(aligner_chi_robust_kernel);
  LOG_DLOAM_PARAMETER(aligner_iteration_chi_threshold);
  LOG_DLOAM_PARAMETER(aligner_max_iterations);
  LOG_DLOAM_PARAMETER(matcher_max_dist);
  LOG_DLOAM_BOOL_PARAMETER(matcher_symmetric);
  LOG_DLOAM_PARAMETER(matcher_window_rows);
  LOG_DLOAM_PARAMETER(matcher_window_cols);
  LOG_DLOAM_PARAMETER(corner_line_dist);
  LOG_DLOAM_PARAMETER(corner_min_point_dist);
  LOG_DLOAM_PARAMETER(corner_max_point_dist);
  LOG_DLOAM_PARAMETER(corner_detector_step);
}
}  // namespace dloam_ros

int main(int argc, char** argv) {
  // Set up ROS.
  ros::init(argc, argv, "ICP");

  // Set up a dynamic reconfigure server.
  dynamic_reconfigure::Server<dloam_ros::dloamConfig>::CallbackType cb;
  cb = boost::bind(&dloam_ros::configCallback, _1, _2);

  // Create a dynamic_reconfigure config object
  dynamic_reconfigure::Server<dloam_ros::dloamConfig> dloam_config;
  dloam_config.setCallback(cb);

  // Create ROS node and launch dloam ICP
  ros::NodeHandle pnh("~");
  dloam_ros::RegistrationNode icp_node(pnh,
                                       std::make_unique<dloam_ros::DLOAM>());

  // Let ROS handle all callbacks.
  ros::spin();

  return 0;
}
