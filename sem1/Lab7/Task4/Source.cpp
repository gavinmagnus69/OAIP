#include <iostream>
#include <string>
long long clet(int a) {
	long long c = 0;
	if (a < 0) {
		a = -a;
	}
	while (a >= 1) {
		c++;
		a /= 10;
	}
	return c;
}
int main() {
	std::string ed[] = { "I","II","III","IV","V","VI","VII","VIII","IX","X" };
	std::string des[] = { "X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C" };
	std::string sot[] = { "C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M" };
	std::string tis[] = { "M","MM","MMM" };
	int n;
	std::cin >> n;
	if (n == 0) {
		std::cout << 0;
		return 0;
	}
	std::string ans;
	int am = clet(n);
	int* a = new int[am];
	for (int i = 0; i < am; i++) {
		a[i] = n % 10;
		n -= a[i];
		n /= 10;
	}
	for (int i = am - 1; i >= 0; --i) {
		if (i == 3) {
			
				ans += tis[a[i ]-1];
			
		}
		if (i == 2) {
			if (a[i]!=0) {
				ans += sot[a[i] - 1];
			}
			else {
				continue;
			}
		}
		if (i == 1) {
			if (a[i] != 0) {
				ans += des[a[i] - 1];
			}
			else {
				continue;
			}
		}
		if (i == 0) {
			if (a[i] != 0) {
				ans += ed[a[i] - 1];
			}
			else {
				continue;
			}
		}
	}
	std::cout << ans;
}