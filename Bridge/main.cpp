#include <iostream>
#include <algorithm>
#include <cmath>

size_t x, a, y, b, l;
std::pair<size_t, size_t> ps[151][151] = { std::pair<size_t, size_t>{0, 0} };

void add(std::pair<size_t, size_t>& p, size_t v, size_t w) {
	p.second += v;
	if (p.second >= w) {
		p.second = 0;
		p.first++;
	}
}

bool check(size_t w) {
	bool res = false;
	for (size_t i = 0; i < x + 1; i++) {
		for (size_t j = 0; j < y + 1; j++) {
			if (i == 0 && j == 0) {
				ps[i][j] = { 0, 0 };
			}
			else if (j == 0) {
				auto left = ps[i - 1][j];
				add(left, a, w);
				ps[i][j] = left;
			}
			else if (i == 0) {
				auto down = ps[i][j - 1];
				add(down, b, w);
				ps[i][j] = down;
			}
			else {
				auto left = ps[i - 1][j];
				auto down = ps[i][j - 1];
				add(left, a, w);
				add(down, b, w);
				if (left > down) {
					ps[i][j] = left;
				}
				else {
					ps[i][j] = down;
				}
			}
			if (ps[i][j].first >= l) {
				return true;
			}
		}
	}
	return false;
}

size_t binarySearch(size_t left, size_t right) {
	while (right - left > 1) {
		size_t middle = (right + left) / 2;
		if (check(middle)) {
			left = middle;
		}
		else {
			right = middle;
		}
	}
	return left;
}

int main() {
	std::cin >> x >> a >> y >> b >> l;
	std::cout << binarySearch(0, (a * x + b * y) / l + 1);
	return 0;
}