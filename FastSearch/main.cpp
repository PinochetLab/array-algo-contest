#include <algorithm>
#include <iostream>
#include <vector>

int numbers[100000];
size_t n;
size_t k;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n;
	for (size_t i = 0; i < n; i++) {
		std::cin >> numbers[i];
	}
	std::sort(numbers, numbers + n);
	std::cin >> k;
	for (size_t i = 0; i < k; i++) {
		int left, right;
		std::cin >> left >> right;
		auto first = std::lower_bound(numbers, numbers + n, left);
		auto second = std::upper_bound(numbers, numbers + n, right);
		std::cout << second - first << ' ';
	}

	return 0;
}