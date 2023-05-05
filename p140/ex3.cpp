#include <algorithm>
#include <iterator>
#include <iostream>

int main() {
	
	bool prev_ws = false;
	
	auto handler = [&](char c) {
		switch(c) {
			case ' ':
				if(prev_ws) {
					std::cout << ' ';
				}
				prev_ws = true;
				return;
			case '.':
			case ',':
			case ';':
			case '!':
			case '?':
				std::cout << c;
				if(prev_ws) {
					std::cout << ' ';
				}
				break;
			default:
				if(prev_ws) {
					std::cout << ' ';
				}
				std::cout << c;
		}
		prev_ws = false;
	};
	
	for(std::istream::int_type c; (c = std::cin.get()) != std::istream::traits_type::eof();) {
		handler(c);
	}
}
