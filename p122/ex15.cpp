#include <iostream>
#include <memory>
#include <cstddef>
#include <algorithm>

void max_difference(std::istream& in, std::ostream& out) {
	std::size_t len;
	in >> len;
	std::unique_ptr<unsigned[]> birth_years{new unsigned[len]};
	
	for(auto i = len; i--;) {
		in >> birth_years[i];
	}
	
	const auto begin = birth_years.get(), end = birth_years.get() + len;
	auto min_max = std::minmax_element(begin, end);
	auto& min = *min_max.first;
	auto& max = *min_max.second;
	
	out << max - min;
}

int main() {
	max_difference(std::cin, std::cout);
}
