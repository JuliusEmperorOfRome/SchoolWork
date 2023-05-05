#include <algorithm>
#include <fstream>
#include <iterator>
#include <iostream>


int main(int argc, char* argv[]) {
	if(argc == 2) {
		std::ifstream in{argv[1]};
		if(!in) {
			std::cout << "failed to open '" << argv[1] << '\'';
			return -1;
		}
		using iter = std::istreambuf_iterator<char>;
		std::cout << std::count(iter{in}, iter{}, '\n');
	}
	else {
		std::cout << "expected 2 cmd line args, got " << argc;
		return -1;
	}
}
