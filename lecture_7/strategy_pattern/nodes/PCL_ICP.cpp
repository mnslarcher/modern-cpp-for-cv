// @file      ICP.cpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#include <ros/ros.h>

#include <memory>

#include <dloam_ros/common/pcl_icp_selector.hpp>
#include <dloam_ros/common/registration.hpp>
#include <dloam_ros/registration/pcl_icp.hpp>

int main(int argc, char** argv) {
  // Set up ROS.
  ros::init(argc, argv, "ICP");

  // Create ROS node and launch dloam ICP
  ros::NodeHandle pnh("~");

  pcl_icp::PCL_ICP_Selector icp_selector(pnh);
  pcl_icp::RegistrationPtr icp = icp_selector.SelectICPMethod();
  ROS_INFO_STREAM("Selected ICP Method " << icp->getClassName());
  auto icp_strategy = std::make_unique<dloam_ros::PCL_ICP>(icp);

  // With the method already selected launch a new registration node
  dloam_ros::RegistrationNode icp_node(pnh, std::move(icp_strategy));

  // Let ROS handle all callbacks.
  ros::spin();

  return 0;
}
