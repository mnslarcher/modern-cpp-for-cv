#ifndef PPM_STRATEGY_HPP_
#define PPM_STRATEGY_HPP_

#include "strategy.hpp"

namespace igg {
class PpmIoStrategy : public IoStrategy {
 public:
  ImageData ReadFromDisk(const std::string& file_name) override;
  bool WriteToDisk(const std::string& file_name, const ImageData& data) override;
};
}  // namespace igg

#endif