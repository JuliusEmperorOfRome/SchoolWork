#include <cstddef>
#include <iostream>
#include <memory>

struct size_bound_array {
  std::size_t len;
  unsigned bound;
  std::unique_ptr<unsigned[]> hs;
}

size_bound_array
read(std::istream& in) {
  size_bound_array sba{};
  in >> sba.len >> sba.bound;
  sba.hs = new unsigned[sba.len];
  for (std::size_t i = 0; i < sba.len; ++i) {
    in >> sba.hs[i];
  }
}

int main() {
  auto data = read(std::cin);
  for (std::size_t i = 0; i < data.len; ++i) {
    if (data.hs[i] > data.bound) {
        std::cout << data.hs[i] << ' ';
    } else
      break;
  }
}
