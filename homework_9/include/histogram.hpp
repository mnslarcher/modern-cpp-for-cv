#include <vector>

#include "bow_dictionary.hpp"

namespace ipb {
class Histogram {
  Histogram();
  Histogram(data);
  Histogram(descriptors, BowDictionary& dictionary);

  operator<<();
  WriteToCSV();
  Histogram ReadFromCSV();

  operator[]();
  data();
  size();
  empty();
  beign();
  cbegin();
  end();
  cend();

  std::vector<int> data_;
}
}  // namespace ipb