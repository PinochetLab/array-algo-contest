#include <iostream>
#include <string>

int main() {
	std::string s;
	std::getline(std::cin, s);
	std::string r = "";
	bool lp = true;
	for (size_t i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c == ' ') {
			if (!lp) {
				r += c;
			}
			lp = true;
		}
		else {
			r += c;
			lp = false;
		}
	}
	if (r[r.size() - 1] == ' ') {
		r.erase(r.size() - 1);
	}

	std::cout << r << std::endl;

	return 0;
}