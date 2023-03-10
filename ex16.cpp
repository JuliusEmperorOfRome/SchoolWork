#include <iostream>
#include <algorithm>

void find_most_common(std::istream& in, std::ostream& out) {
	unsigned counts[10]{};
	std::size_t counter;
	in >> counter;
	while(counter--) {
		unsigned grade;
		in >> grade;
		++counts[grade - 1];
	}
	
	auto max = std::max_element(std::begin(counts), std::end(counts));
	out << (max - std::begin(counts) + 1);
}

int main() {
	find_most_common(std::cin, std::cout);
}
