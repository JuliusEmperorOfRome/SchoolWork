#include <algorithm>
#include <fstream>
#include <iterator>
#include <iostream>


int main(int argc, char* argv[]) {
	std::ifstream in;
	if(argc == 2) {
		in.open(argv[1]);
		if(!in.is_open()) {
			std::cout << "failed to open '" << argv[1] << '\'';
			return -1;
		}
	}
	else {
		in.open("text.txt");
		if(!in.is_open()) {
			std::cout << "failed to open 'text.txt'";
			return -1;
		}
	}
	
	using iter = std::istreambuf_iterator<char>;
	std::cout << std::count(iter{in}, iter{}, '\n');
}
