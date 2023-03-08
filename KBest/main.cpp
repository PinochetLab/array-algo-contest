#include <iostream>
#include <algorithm>

struct Point {
	uint32_t x = 0;
	uint32_t y = 0;
	size_t i = 0;
};

size_t n, k;
Point ps[100000];

bool check(long double m) {
	auto rule = [m](Point a, Point b) -> bool { return a.x - m * a.y > b.x - m * b.y; };
	std::nth_element(ps, ps + k - 1, ps + n, rule);
	uint32_t s1 = 0, s2 = 0;
	for (size_t i = 0; i < k; i++) {
		s1 += ps[i].x;
		s2 += ps[i].y;
	}
	return s1 >= m * s2;
}

void binarySearch(long double left, long double right, long double err) {
	while (right - left > err) {
		long double middle = (right + left) / 2;
		if (check(middle)) {
			left = middle;
		}
		else {
			right = middle;
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> k;
	for (size_t i = 0; i < n; i++) {
		uint32_t x, y;
		std::cin >> x >> y;
		ps[i] = { x, y, i + 1 };
	}

	binarySearch(0, 1e7, 1e-6);

	for (size_t i = 0; i < k; i++) {
		std::cout << ps[i].i << ' ';
	}

	return 0;
}