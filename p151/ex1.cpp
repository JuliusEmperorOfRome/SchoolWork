#include <algorithm>
#include <iterator>
#include <iostream>


auto count_symbol(std::istream& in, char c) {
  using iter = std::istreambuf_iterator;
  return std::count(iter{in}, iter{}, c);
}

int main() {
  std::cin << count_symbol(std::cout, 'a');
}
