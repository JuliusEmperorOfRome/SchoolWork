#include <algorithm>
#include <cstddef>
#include <iostream>

template<typename T, std::size_t N>
std::size_t size(const T (&array)[N]) noexcept {
	return N;
}

void count_bolts(std::istream& in, std::ostream& out) {
	unsigned counts[14]{};
	auto add_to_type = [&](unsigned type, unsigned n) { counts[type - 3] += n; };
	
	std::size_t n;
	in >> n;
	
	for(;n--;) {
		unsigned type, count;
		in >> type >> count;
		add_to_type(type, count);
	}
	
	auto max_elem = std::max_element(std::begin(counts), std::end(counts));
	auto max_elem_index = max_elem - std::begin(counts);
	
	out << "daugiausia M" << max_elem_index + 3 << " sriegiu.\n";
	for(std::size_t i = 0; i < size(counts); ++i) {
		out << 'M' << i + 3 << ": " << counts[i] << '\n';
	}
}

int main() {
	count_bolts(std::cin, std::cout);
}
