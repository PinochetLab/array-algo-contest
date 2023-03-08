#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

size_t n, k;
size_t colors[10][10];
size_t counts[10]{0};

size_t 

size_t maxDifference(size_t ind, size_t s) {
	size_t min = 0;
	size_t max = 0;
	for (size_t i = 0; i < k; i++) {
		size_t v = counts[i];
		if (i == ind) {
			v += s;
		}
		if (v > max) {
			max = v;
		}
		if (v > min) {
			min = v;
		}
	}
	return max - min;
}

int main() {
	std::cin >> n >> k;
	colors[0][0] = 0;
	counts[0]++;
	for (size_t i = 1; i < n; i++) {
		for (size_t j = 0; j < k; j++) {
			colors[0][i][j] = !colors[0][i - 1][j] && counts[j] < n * n / k;
			colors[i][0][j] = !colors[i - 1][0][j] && counts[j] < n * n / k;
		}
	}
	for (size_t i = 1; i < n; i++) {
		for (size_t j = 1; j < n; j++) {
			for (size_t m = 0; m < k; m++) {
				colors[i][j][m] = !colors[i - 1][j][m] && !colors[i][j - 1][m] && counts[m] < n * n / k;
				if (colors[i][j][m]) {
					counts[m]++;
				}
			}
		}
	}
	bool b = true;
	for (size_t m = 0; m < k; m++) {
		if (colors[n - 1][n - 1][m]) {
			std::cout << "Yes";
			b = false;
			break;
		}
	}
	if ( b ) {
		std::cout << "No";
	}
}