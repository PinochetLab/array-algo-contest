#include <iostream>
#include <algorithm>
#include <set>

struct Bracket {
	int64_t x;
	size_t time;
	size_t color;
	bool open;
	int64_t other;

	friend bool operator < (const Bracket& b1, const Bracket& b2) {
		return b1.time > b2.time;
	}
};

size_t si;
size_t n;
size_t c_n;
Bracket bs[100001];
size_t colors[50001] = {0};

int main() {
	std::cin >> si >> c_n >> n;

	for (size_t i = 0; i < n; i++) {
		int64_t l, r; size_t k;
		std::cin >> k >> l >> r;
		k--; l; r;
		bs[2 * i] = { l - 1, i, k, true, r};
		bs[2 * i + 1] = { r, i, k, false, l - 1};
	}
	auto rule = [](Bracket b1, Bracket b2) -> bool { return b1.x < b2.x; };
	std::sort(bs, bs + 2 * n, rule);

	std::set<Bracket> s = {};
	int64_t li = 0;

	for (size_t i = 0; i < 2 * n; i++) {
		Bracket b = bs[i];

		if (s.empty()) {
			if (b.open) {
				s.insert(b);
			}
		}
		else {
			colors[s.begin()->color] += b.x - li;
			if (b.open) {
				s.insert(b);
			}
			else {
				s.erase(Bracket{ b.other, b.time, b.color, !b.open, b.x });
			}
		}
		li = b.x;
	}

	for (size_t i = 0; i < c_n; i++) {
		std::cout << colors[i] << ' ';
	}

	return 0;
}