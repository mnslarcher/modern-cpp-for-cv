#ifndef PNG_STRATEGY_HPP_
#define PNG_STRATEGY_HPP_

#include "strategy.hpp"

namespace igg {
class PngIoStrategy : public IoStrategy {
 public:
  ImageData ReadFromDisk(const std::string& file_name) override;
  bool WriteToDisk(const std::string& file_name, const ImageData& data) override;
};
}  // namespace igg

#endif