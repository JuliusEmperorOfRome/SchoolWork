#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

/*
10 7 2
5 6 -2 6 1 2 10 15 9 3
5 3 7 7 -1 -1 6 -2 2 2
*/

struct Point {
	int x, y;
	friend std::ostream& operator<<(std::ostream& out, Point p) {
		out << '(' << p.x << "; " << p.y << ')';
	}
};

int dist(Point a, Point b) noexcept {
	auto x_d = a.x - b.x;
	auto y_d = a.y - b.y;
	return x_d * x_d + y_d * y_d;
}

struct input {
	Point o;
	std::vector<Point> ps;
};

input read_input(std::istream& in) {
	input ret{};
	std::size_t len;
	in >> len;
	in >> ret.o.x >> ret.o.y;
	
	auto& ps = ret.ps;
	ps.resize(len);
	for(auto& p : ps) {
		in >> p.x >> p.y;
	}
	
	return ret;
}

struct result {
	Point ps[3]; //nuo arciausio
};

result find_closest_3(const input& in) {
	int ds[3] = {
		std::numeric_limits<int>::max(),
		std::numeric_limits<int>::max(),
		std::numeric_limits<int>::max()
	};
	Point ps[3]{};
	for(auto& p : in.ps) {
		auto d = dist(p, in.o);
		if(d < ds[2]) {
			ds[2] = d;
			ps[2] = p;
		}
		if(d < ds[1]) {
			std::swap(ds[2], ds[1]);
			std::swap(ps[2], ps[1]);
		}
		if(d < ds[0]) {
			std::swap(ds[1], ds[0]);
			std::swap(ps[1], ps[0]);
		}
	}
	return result{ps[0], ps[1], ps[2]};
}

void execute(std::istream& in, std::ostream& out) try {
	input i = read_input(in);
	result r = find_closest_3(i);
	auto& ps = r.ps;
	out << ps[0] << '\n';
	out << ps[1] << '\n';
	out << ps[2] << '\n';
}
catch(std::exception& e) {
	std::cerr << e.what();
}

int main() {
	execute(std::cin, std::cout);
}
