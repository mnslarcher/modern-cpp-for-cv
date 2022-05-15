// @file       sifts_internal.h
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved
#ifndef SIFTS_INTERNAL_HPP_
#define SIFTS_INTERNAL_HPP_

#include <opencv2/core/mat.hpp>
#include <string>
#include <tuple>

std::tuple<cv::Mat, cv::Mat> ComputeSifts(const std::string& fileName);

#endif  // SIFTS_INTERNAL_HPP_
