#include <iostream>
#include <cstdio>
#include <string>
long long fact(long long a) {
	long long i = 1;
	long long sumf = 1;
	if (a == 0) {
		return 1;
	}
	if (a == 1) {
		return 1;
	}
	for (i = 1; i <= a; i++) {
		sumf *= i;

	}
	return sumf;


}
int main() {
	/*char* a = new char[20];
	int tmp = 0;
	int l = 0;
	while (tmp != '\n') {
		tmp = 0;
		tmp = getchar();
		a[l] = tmp;
		l++;//length of string
	}*/
	std::string a;
	std::cin >> a;

	int l = a.length();
	//std::cout <<l;
	bool* check = new bool[l + 2];
	for (int i = 0; i < l + 2; i++) {
		check[i] = 0;
	}
	long long* am = new long long[l + 2];
	for (int i = 0; i < l + 2; i++) {
		am[i] = 0;
	}
	for (int i = 0; i <= l; i++) {
		if (check[i] == 0) {
			am[i] += 1;
			check[i] = 1;
			if (i != l - 1) {
				for (int j = i ; j < l; j++) {
					if (a[i] == a[j] && check[j] == 0) {
						am[i] += 1;
						check[j] = 1;
					}
				}
			}

		}
	}
	//std::cout << "\n" << l << "\n";
	//for (int i = 0; i < l; i++) {
	//	std::cout << am[i] << " ";

	//}
	long long ans = fact(l);
	for (int i = 0; i < l; i++) {
		if (am[i] != 0) {
			ans /= fact(am[i]);
		}
	}
	std::cout << ans;


}