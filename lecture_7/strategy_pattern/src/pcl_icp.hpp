// @file      pcl_icp.hpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#ifndef DLOAM_ROS_REGISTRATION_PCL_ICP_HPP_
#define DLOAM_ROS_REGISTRATION_PCL_ICP_HPP_
#include <pcl/filters/voxel_grid.h>
#include <pcl/point_types.h>
#include <pcl/registration/registration.h>

#include <memory>
#include <string>

#include <dloam_ros/common/pcl_icp_selector.hpp>
#include <dloam_ros/registration/icp_strategy.hpp>

namespace dloam_ros {

class PCL_ICP : public ICPStrategy {
 public:
  explicit PCL_ICP(pcl_icp::RegistrationPtr method, bool has_keypoints = false,
                   bool has_depth = false, bool has_correspon = false);
  ~PCL_ICP() = default;

  inline std::string Strategy() const override { return "PCL Implementation"; }

  /// This 2 methods we MUST override
  void ProcessFirstCloud(const PointCloud::ConstPtr& first_msg) override;
  void RegisterNewCloud(const PointCloud::ConstPtr& input_msg) override;

 private:
  /**
   * @brief
   *
   * @param cloud
   * @return PointCloud::Ptr
   */
  PointCloud::Ptr Downsample(const PointCloud::ConstPtr& cloud) const;

  std::shared_ptr<pcl::VoxelGrid<PointCloud>> downsample_filter_;

  pcl_icp::RegistrationPtr icp_;
  pcl_icp::PointCloud::Ptr current_scan_;
  pcl_icp::PointCloud::Ptr target_scan_;
  float leaf_ = 0.1;
};

}  // namespace dloam_ros

#endif  // DLOAM_ROS_REGISTRATION_PCL_ICP_HPP_
