// @file      NARF_ICP.cpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#include <ros/ros.h>

#include <memory>

#include <dloam_ros/common/registration.hpp>
#include <dloam_ros/registration/narf_icp.hpp>

int main(int argc, char** argv) {
  // Set up ROS.
  ros::init(argc, argv, "ICP");

  // Create ROS node and launch dloam ICP
  ros::NodeHandle pnh("~");
  dloam_ros::RegistrationNode icp_node(pnh,
                                       std::make_unique<dloam_ros::NARF_ICP>());

  // Let ROS handle all callbacks.
  ros::spin();

  return 0;
}
