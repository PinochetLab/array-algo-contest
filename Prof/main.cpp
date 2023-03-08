#include <iostream>
#include <deque>

const size_t p230 = 0x40000000;


int main() {
	size_t n, k;
	std::cin >> n >> k;

	std::deque<uint32_t> vs = {};

	for (size_t i = 0; i < n; i++)
	{
		uint32_t v;
		std::cin >> v;
		vs.push_back(v);
	}

	if (n == 1) {
		std::cout << 0 << std::endl;
		return 0;
	}

	uint32_t x = vs.front();
	uint32_t y = vs.back();;

	for (size_t i = 0; i < k; i++) {
		if (x < y) {
			vs.pop_front();
			y = (x + y) % p230;
			x = vs.front();
			vs.push_back(y);
		}
		else {
			vs.pop_back();
			x = (y - x) % p230;
			y = vs.back();
			vs.push_front(x);
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		std::cout << vs.front() << std::endl;
		vs.pop_front();;
	}

	return 0;
}