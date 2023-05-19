#include<iostream>

void process(std::istream& in, std::ostream& out) {
	unsigned left;
	unsigned count;
	in >> left >> count;
	while(count--) {
		char ch = in.get();
		if(!in.good()) {
			out << "istream klaida";
		}
		
		
		switch(ch) {
			case 'M':
				if(left <= 2) {
					out << "Mazylis " << left;
					return;
				}
				else left -= 2;
				break;
			case 'F':
				if(left <= 3) {
					out << "Frekenbok " << left;
					return;
				}
				else left -= 3;
				break;
			case 'K':
				if(left <= 5) {
					out << "Karlsonas " << left;
					return;
				}
				else left -= 5;
				break;
		}
	}
	
	out << "liko " << left;
}

int main() {
	process(std::cin, std::cout);
}
