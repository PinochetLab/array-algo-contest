#include <iostream>
#include <vector>
#include <queue>

int main() {
	int n;
	std::cin >> n;
	int t, e, p;

	std::queue<int> cs = {};
	std::vector<int> ps = {};
	std::queue<int> ts = {};
	std::vector<int> rs = {};

	for (int i = 0; i < n; i++) {
		std::cin >> e >> t >> p;
		if (e == 1) {
			ps.push_back(p);
		}
		else {
			cs.push(p);
			ts.push(t);
		}
		
		int index = 0;
		while (index != -1 && cs.size() > 0) {
			int c = cs.front();
			index = -1;
			for (int j = 0; j < ps.size(); j++) {
				if (ps[j] == c) {
					index = j;
				}
			}
			if (index != -1) {
				ps.erase(ps.begin() + index);
				cs.pop();
				rs.push_back(t - ts.front());
				ts.pop();
			}
		}
	}

	for (int i = 0; i < rs.size(); i++) {
		std::cout << rs[i] << std::endl;
	}

	int s = cs.size();
	for (int i = 0; i < s; i++) {
		std::cout << -1 << std::endl;
	}

	return 0;
}