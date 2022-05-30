#include <array>
#include <memory>

template <class T, int SIZE>
struct Image {
  using Ptr = std::unique_ptr<Image<T, SIZE>>;
  std::array<T, SIZE> data;
};

template <int SIZE>
using Imagef = Image<float, SIZE>;
int main() {
  using Image3f = Imagef<3>;
  auto image_ptr = Image3f::Ptr(new Image3f);
  return 0;
}