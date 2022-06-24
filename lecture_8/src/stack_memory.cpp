#include <stdio.h>

int main(int argc, char const* argv[]) {
  int size = 2;
  int* ptr = nullptr;
  {
    int ar[size];
    ar[0] = 42;
    ar[1] = 13;
    ptr = ar;
  }
  for (int i = 0; i < size; ++i) {
    printf("%d\n", ptr[i]);
  }
  return 0;
}