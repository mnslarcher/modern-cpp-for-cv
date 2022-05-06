#ifndef IPB_CONTAINER_H_
#define IPB_CONTAINER_H_

#include <iostream>
#include <string>
#include <vector>

namespace ipb {

template <typename T>
struct named_vector {
  named_vector(std::string s, std::vector<T> v) : name_(s), vector_(v) {}
  std::vector<T> vector() { return vector_; }
  std::string name() { return name_; }
  bool empty() { return name_.empty() or vector_.empty(); }
  std::size_t size() { return name_.size() + vector_.size(); }

 private:
  std::string name_;
  std::vector<T> vector_;
};

}  // namespace ipb

#endif  // IPB_CONTAINER_H_