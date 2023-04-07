#include <algorithm>
#include <cstddef>
#include <iostream>

void calculate_ratings(std::istream& in, std::ostream& out) {
  std::size_t len;
  std::cin >> len;

  unsigned min = static_cast<unsigned>(-1);  // max value
  unsigned max{};
  unsigned cummulator{};
  for (auto counter{2 * len}; counter--;) {
    unsigned tmp;
    in >> tmp;

    if (tmp > max) {
      max = tmp;
    }
    if (tmp < min) {
      min = tmp;
    }

    cummulator += tmp;
  }

  cummulator -= (min + max);
  double rating = 0.5 * double(cummulator) / (len - 1);
  out << rating;
}

int main() {
  calculate_ratings(std::cin, std::cout);
}
