#ifndef IPB_CONTAINER_H_
#define IPB_CONTAINER_H_

#include <iostream>
#include <string>
#include <vector>

namespace ipb {

template <typename T>
struct named_vector {
  named_vector() : name_(), vector_() {}
  named_vector(std::string s) : name_(s), vector_() {}
  named_vector(std::string s, std::vector<T> v) : name_(s), vector_(v) {}
  std::vector<T>& vector() { return vector_; }
  std::string& name() { return name_; }
  bool empty() { return name_.empty() or vector_.empty(); }
  std::size_t size() { return name_.size() + vector_.size(); }
  void resize(std::size_t count) { vector_.resize(count); }
  void resize(std::size_t count, const T& value) {
    vector_.resize(count, value);
  }
  void reserve(std::size_t n) { vector_.reserve(n); }
  std::size_t capacity() { return vector_.capacity(); }

 private:
  std::string name_;
  std::vector<T> vector_;
};

}  // namespace ipb

#endif  // IPB_CONTAINER_H_