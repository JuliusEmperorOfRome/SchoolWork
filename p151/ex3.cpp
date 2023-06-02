#include<iostream>


void process(std::istream& in, std::ostream& out) {
  using iter = std::istreambuf_iterator<char>;
  std::string str{iter{in}, iter{}};
  using int_t = std::string::size_type;

  int_t start = 0;
  while(start != str.size()) {
    int_t dot = str.find('.', start);
	if(dot == str.npos) break;
	
    unsigned space_count = 0;
    for(;start != dot; ++start) {
      if(str[start] == ' ') ++space_count;
    }
    out << (space_count + 1) << '\n';

    //skip .[space][space]...[space]
    while(start != str.size() && str[++start] == ' ');
  }
}

int main() {
  process(std::cin, std::cout);
}
