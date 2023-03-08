#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

int64_t min(int64_t a, int64_t b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

int64_t max(int64_t a, int64_t b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

struct Rect {
public:
	int64_t x1;
	int64_t y1;
	int64_t x2;
	int64_t y2;

	Rect(int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}

	int64_t area() {
		return (x2 - x1) * (y2 - y1);
	}

	std::string str() {
		return std::to_string(x1) + " " + std::to_string(y1) + " " + std::to_string(x2) + " " + std::to_string(y2);
	}

	static bool int64_tersect(Rect* r1, Rect* r2) {
		return !(r1->x1 > r2->x2 || r1->x2 < r2->x1 || r1->y1 > r2->y2 || r1->y2 < r2->y1);
	}

	static Rect* int64_tersection(Rect* r1, Rect* r2) {
		int64_t x1 = max(r1->x1, r2->x1);
		int64_t y1 = max(r1->y1, r2->y1);
		int64_t x2 = min(r1->x2, r2->x2);
		int64_t y2 = min(r1->y2, r2->y2);
		return new Rect(x1, y1, x2, y2);
	}
};

int main() {
	size_t n = 0;
	std::cin >> n;
	if (n == 0) {
		std::cout << 0 << std::endl;
		return 0;
	}

	Rect* int64_tersection = NULL;

	for (size_t i = 0; i < n; i++)
	{
		int64_t x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		Rect* r = new Rect(x1, y1, x2, y2);
		if (i == 0) {
			int64_tersection = r;
		}
		else {
			if (r->area() <= 0) {
				std::cout << 0 << std::endl;
				return 0;
			}
			if (Rect::int64_tersect(int64_tersection, r)) {
				int64_tersection = Rect::int64_tersection(int64_tersection, r);
			}
			else {
				std::cout << 0 << std::endl;
				return 0;
			}
		}
	}

	std::cout << int64_tersection->area() << std::endl;
	
	return 0;
}