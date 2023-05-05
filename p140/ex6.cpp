#include <cctype>
#include <fstream>
#include <iostream>
#include <map>


int main() {
	std::map<char, unsigned> counts{};
	std::ifstream in{"text_lt_asci.txt"};
	for(std::istream::int_type ch; (ch = in.get()) != std::istream::traits_type::eof();) {
		unsigned char c = static_cast<unsigned char>(ch);	
		if(std::isalpha(c)) {
			++counts[toupper(c)];
		}
	}
	
	for(auto& key_value : counts) {
		std::cout << key_value.first << ' ' << key_value.second << '\n';
	}
}
