#include <algorithm>
#include <iterator>
#include <iostream>


auto count_symbol(std::istream& in, char c) {
  using iter = std::istreambuf_iterator<char>;
  return std::count(iter{in}, iter{}, c);
}

int main() {
  std::cout << count_symbol(std::cin, 'a');
}
