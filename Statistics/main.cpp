#include <algorithm>
#include <iostream>
std::pair<int, size_t> xs[70000];
size_t n;
size_t k;

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n;
	for (size_t i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		xs[i] = { x, i };
	}
	std::sort(xs, xs + n);
	std::cin >> k;
	for (size_t i = 0; i < k; i++) {
		size_t l, r;
		int x;
		std::cin >> l >> r >> x;
		l--;
		r--;
		size_t li = std::lower_bound(xs, xs + n, std::pair<int, size_t>{ x, l }) - xs;
		size_t ri = std::upper_bound(xs, xs + n, std::pair<int, size_t>{ x, r }) - xs;
		std::cout << (li != ri);
	}

	return 0;
}