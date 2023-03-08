#include <iostream>
#include <deque>
#include <algorithm>

struct min_queue {
	std::deque<int> q;
	
	int top() {
		return q.front();
	}

	void push(int v) {
		while (!q.empty() && q.back() > v)
			q.pop_back();
		q.push_back(v);
	}

	void pop(int v) {
		if (!q.empty() && q.front() == v)
			q.pop_front();
	}
};

const size_t max = 1000;

int m[max][max];
int m_v[max][max];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t n, k;
	std::cin >> n >> k;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			std::cin >> m[i][j];
		}
	}

	for (size_t j = 0; j < n; j++) {
		min_queue q = min_queue();
		for (size_t i = 0; i < k; i++) {
			q.push(m[i][j]);
		}
		for (size_t i = 0; i < n - k; i++) {
			m_v[i][j] = q.top();
			q.pop(m[i][j]);
			q.push(m[i + k][j]);
		}
		m_v[n - k][j] = q.top();
	}

	for (size_t i = k - 1; i < n; i++) {
		min_queue q = min_queue();
		for (size_t j = 0; j < k; j++) {
			q.push(m_v[i - k + 1][j]);
		}
		for (size_t j = 0; j < n - k; j++) {
			std::cout << q.top() << ' ';
			q.pop(m_v[i - k + 1][j]);
			q.push(m_v[i - k + 1][j + k]);
		}
		std::cout << q.top() << '\n';
	}
	return 0;
}