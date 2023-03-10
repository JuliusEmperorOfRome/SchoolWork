#include <iostream>
#include <cstddef>


void take_half(std::istream& in, std::ostream& out) {
	std::size_t len;
	in >> len;
	len /= 2;
	
	while(len--) {
		unsigned index, value;
		in >> index >> value;
		out << index << ' ' << value << '\n';
	}
}

int main() {
	take_half(std::cin, std::cout);
}
