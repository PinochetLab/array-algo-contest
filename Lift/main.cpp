#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

struct User {
	int t;
	int s;
	int e;
	int i;

	int dir() {
		if (e > s) {
			return 1;
		}
		else {
			return -1;
		}
	}

	int dir(int v) {
		if (v > s) {
			return 1;
		}
		else {
			return -1;
		}
	}

	int distance(int floor) {
		return std::abs((int)floor - (int)s);
	}

	friend bool operator <(const User& lhs, const User& rhs)
	{
		return lhs.t < rhs.t;
	}

	friend bool operator >(const User& lhs, const User& rhs)
	{
		return lhs.t > rhs.t;
	}
};

int n, k;
int answers[30000];

int main() {
	std::cin >> n >> k;
	std::queue<User> q = {};
	std::set<User> inLift = {};
	for (int i = 0; i < n; i++) {
		int t, s, e;
		std::cin >> t >> s >> e;
		q.push({ t, s, e, i });
	}
	int floor = 0;
	int lastTime = 0;
	while (!q.empty()) {
		User u = q.front();
		if (inLift.empty()) {
			inLift.insert(u);
			answers[u.i] = u.distance(floor) * k;
			q.pop();
		}
		else {
			User f = *inLift.begin();
			if (f.dir() == -1) {
				f = *inLift.rbegin();
			}
			int dt = u.t - lastTime;
			if (f.distance(floor) * k < dt) {
				lastTime += f.dir() * f.distance(floor) * k;
				inLift.erase(f);
				continue;
			}
			floor += f.dir() * dt;
			if (f.dir() == u.dir() && f.dir() * u.dir(floor) == -1) {
				inLift.insert(u);
				answers[u.i] = u.distance(floor) * k;
				q.pop();
			}
			else {
				q.pop();
				q.push(u);
			}
		}
		lastTime = u.t;
	}
	return 0;
}