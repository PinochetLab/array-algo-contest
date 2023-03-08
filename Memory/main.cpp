#include <iostream>
#include <string>
#include <queue>

int64_t times[30001];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t t;
	std::priority_queue<size_t, std::vector<size_t>, std::greater<size_t>> numbers = {};
	std::priority_queue<std::pair<size_t, size_t>, std::vector<std::pair<size_t, size_t>>, std::greater<std::pair<size_t, size_t>>> d = {};

	for (size_t i = 1; i < 30001; i++) {
		times[i] = -1;
		numbers.push(i);
	}

	while (std::cin >> t) {
		char c;
		std::cin >> c;
		if (c == '+') {
			while (!d.empty() && d.top().first + 600 <= t) {
				if (d.top().first != times[d.top().second]) {
					auto p = d.top();
					d.pop();
					p.first = times[p.second];
					d.push(p);
					continue;
				}
				times[d.top().second] = -1;
				numbers.push(d.top().second);
				d.pop();
			}

			size_t number = numbers.top();
			numbers.pop();
			d.push({t, number});
			times[number] = t;
			std::cout << number << '\n';
		}
		else {
			size_t n;
			std::cin >> n;
			if (times[n] == -1 || times[n] + 600 <= t) {
				std::cout << '-' << '\n';
			}
			else {
				std::cout << '+' << '\n';
				times[n] = t;
			}
		}
	}
	return 0;
}