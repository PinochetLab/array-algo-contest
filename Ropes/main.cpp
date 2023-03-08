#include <iostream>
#include <algorithm>

size_t n, k;
size_t rs[10002];

bool check(size_t len) {
	size_t r = 0;
	for (size_t i = 0; i < n; i++) {
		r += rs[i] / len;
		if (r >= k) {
			return false;
		}
	}
	return true;
}

size_t binarySearch(size_t left, size_t right) {
	while (left < right - 1) {
		size_t center = (right + left) / 2;
		if (check(center)) {
			right = center;
		}
		else {
			left = center;
		}
	}
	return left;
}

int main() {
	std::cin >> n >> k;
	for (size_t i = 0; i < n; i++) {
		std::cin >> rs[i];
	}
	std::cout << binarySearch(0, 10000001);
	return 0;
}



