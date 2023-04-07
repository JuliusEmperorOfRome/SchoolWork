#include <cstddef>
#include <iostream>
#include <memory>

std::size_t count_days(int p0, int* ts, int* ps, std::size_t N) {
	std::size_t max_count = 0;
	for(std::size_t i = 0, count = 0; i < N; ++i) {
		if(ts[i] > 0 && ps[i] > p0) {
			if(++count > max_count) {
				max_count = count;
			}
		}
		else {
			count = 0;
		}
	}
	
	return max_count;
}

int main() {
	std::cout << "p0 n t1 p1 t2 p2 ... t[n] p[n]\n";
	
	int p0;
	std::cin >> p0;
	
	std::size_t n;
	std::cin >> n;
	
	std::unique_ptr<int[]> ts{new int[n]}, ps{new int[n]};
	
	//reverse loop works fine
	for(auto i = n; i--;) {
		std::cin >> ts[i] >> ps[i];
	}
	
	std::cout << count_days(p0, ts.get(), ps.get(), n);
}
