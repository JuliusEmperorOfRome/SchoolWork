#include<iostream>

unsigned longest_line(std::istream& in) {
  unsigned max_count = 0;
  for (std::string line; std::getline(in, line);) {
    if(line.empty())
      continue;

    unsigned count = 0;
    for(const char& c : line) {
      switch(c) {
        case ' ':
        case ',':
        case '.':
        case '(':
        case ')':
        case '\t':
        case '\n':
          continue;
      }
      count += 1;
    }
    if(count > max_count) {
      max_count = count;
    }
  }

  return max_count;
}

int main() {
    std::cout << longest_line(std::cin);
}
