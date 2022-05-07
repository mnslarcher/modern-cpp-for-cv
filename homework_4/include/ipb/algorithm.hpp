#ifndef IPB_ALGORITHM_H_
#define IPB_ALGORITHM_H_

#include "named_vector.hpp"

namespace ipb {
using vector = named_vector<int>;
int accumulate(vector& nv);
int count(vector& nv, const int& val);
bool all_even(vector& nv);
void clamp(vector& nv, const int& lo, const int& hi);
void fill(vector& nv, const int& val);
bool find(vector& nv, const int& val);
void print(vector& nv);
void toupper(vector& nv);
void sort(vector& nv);
void rotate(vector& nv, const int& by);
void reverse(vector& nv);
}  // namespace ipb

#endif  // IPB_ALGORITHM_H_