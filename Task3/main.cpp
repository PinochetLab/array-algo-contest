#include <iostream>
#include <sstream>
#include <stack>
#include <string>

int main() {
	std::stack<int> st = {};
	std::string line, s;
	std::getline(std::cin, line);
	std::istringstream ss(line);
	while (ss >> s) {
		if (s == "") {
			break;
		}
		if (s == "+" || s == "-" || s == "*") {
			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();
			if (s == "+") {
				st.push(a + b);
			}
			else if (s == "*") {
				st.push(a * b);
			}
			else {
				st.push(a - b);
			}
		}
		else {
			int a = std::stoi(s);
			st.push(a);
		}
	}
	std::cout << st.top() << std::endl;
	return 0;
}