#include <iostream>
#include <string>
#include <algorithm>
int main() {
	long long x;
	std::cin >> x;
	if (x < 1 || x>2e9) {
		return 0;
	}
	std::string a;
	while (x >= 1) {

		a+= x % 3+'0';
		x /= 3;
		if (x == 1) {
			a+= "1";
			break;
		}
	}
	reverse(a.begin(),a.end());
	int p = 0;
	for (int i = 0; i < 100; i++) {
		p = a.find("10");
		if (p != -1) {
			a.replace(p, 2, "03");
		}
		p = a.find("20");
		if (p != -1) {
			a.replace(p, 2, "13");
		}

		p = a.find("30");
		if (p != -1) {
			a.replace(p, 2, "23");
		}
	}
	int j = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != '0') {
			j = i;
			break;
		}
	}
	for (int i = j; i < a.length(); i++) {
		std::cout << a[i];
	}
}