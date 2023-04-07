#include <iostream>
#include <cstddef>
#include <memory>
#include <algorithm>


void count_max(std::istream& in, std::ostream& out) {
	std::size_t len;
	in >> len;
	std::unique_ptr<unsigned[]> prices(new unsigned[len]);
	
	for(auto i = len; i--;) /*reversed, but data is unordered so no problem*/ {
		unsigned lt, ct;
		in >> lt >> ct;
		prices[i] = lt * 100 + ct;
	}
	
	const auto begin = prices.get(), end = prices.get() + len;
	auto max_it = std::max_element(begin, end);
	out << std::count(begin, end, *max_it);
}

int main() {
	count_max(std::cin, std::cout);
}
