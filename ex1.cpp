#include <algorithm>
#include <cstddef>
#include <iostream>
#include <limits>
#include <memory>

void calculate_data(std::istream& in, std::ostream& out) {
	std::size_t n;
	in >> n;
	std::unique_ptr<unsigned[]> heights = new unsigned[2 * n];
	
	auto men_begin = heights.get();
	auto men_end = men_begin + n;
	auto women_begin = men_end;
	auto women_end = women_begin + n;
	
	for(auto m = men_begin, w = women_begin; m != men_end; ++m, ++w) {
		in >> *m >> *w;
	}
	
	unsigned max_diff = (*men_begin < *women_begin) ? *women_begin - *men_begin : *men_begin - *women_begin;
	std::size_t max_diff_index = 0;
	
	unsigned min_m = *men_begin, max_m = *men_begin;
	unsigned min_w = *women_begin, max_w = *women_begin;
	
	for(std::size_t i = 1; i < n; ++i) {
		auto& m = men_begin[i];
		auto& w = women_begin[i];
		
		//find max difference
		auto diff = (m < w) ? w - m : m - w;
		if(diff > max_diff) {
			max_diff = diff;
			max_diff_index = i;
		}
		
		//find smallest and tallest men
		if(m < min_m) {
			min_m = m;
		}
		else if(m > max_m) {
			max_m = m;
		}
		//find smallest and tallest men
		if(w < min_w) {
			min_w = w;
		}
		else if(w > max_w) {
			max_w = w;
		}
	}
	
	unsigned m_diff = max_m - min_m;
	unsigned w_diff = max_w - min_w;
	
	out << "didziausias skirtumas " << max_diff_index + 1 << " seimoje.\n";
	if(m_diff == w_diff) {
		out << "vyru ir moteru ugiu intervalu dydziai vienodi.\n";
	}
	else if(m_diff > w_diff) {
		out << "vyru ugiu intervalas didesnis nei moteru.\n";
	}
	else {
		out << "moteru ugiu intervalas didesnis nei vyru.\n";
	}
}


int main() {
	calculate_data(std::cin, std::cout);
}
