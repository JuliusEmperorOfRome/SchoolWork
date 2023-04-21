#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

void execute(std::istream& in, std::ostream& out) {
	unsigned counts[12]{};
	using iter = std::istream_iterator<unsigned>;
	for(auto begin = iter{in}, end = iter{};;) {
		if(begin == end) break;
		begin++; //skip year;
		if(begin == end) break;
		counts[*begin++ - 1]++;
		if(begin == end) break;
		begin++; //skip day;
	}
	
	auto max_idx = std::max_element(std::begin(counts), std::end(counts)) - std::begin(counts);
	out << max_idx + 1;
}

int main() {
	std::string filename;
	std::cin >> filename;
	std::ifstream in{filename};
	
	execute(in, std::cout);
}
