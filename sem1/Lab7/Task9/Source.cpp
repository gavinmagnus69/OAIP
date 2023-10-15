#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
int main() {
	int p;
	std::cout << "enter position of poisoned barrel\n";
	std::cin >> p;
	bool* barrels = new bool[241];
	for (int i = 1; i < 241; i++) {
		barrels[i] = 0;
	}
	barrels[p] = 1;
	std::string temp = "00000";
	std::string* a = new std::string[241];
	for (int i = 1; i < 241; i++) {
		int x = i;
		while (x >= 1) {

			a[i] += x % 3 + '0';
			x /= 3;
			if (x == 1) {
				a[i] += "1";
				break;
			}
		}
	}
	for (int i = 1; i < 241; i++) {
		reverse(a[i].begin(), a[i].end());
	}
	for (int i = 1; i < 241; i++) {
		int n = 5 - a[i].length();
		a[i].insert(0, n, '0');
	}
	bool* alivenegros = new bool[6];
	for (int i = 1; i < 6; i++) {
		alivenegros[i] = 1;
	}
	int* medcard = new int[6];
	for (int i = 1; i < 6; i++) {
		medcard[i] = 0;
	}
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 241; j++) {
			if ((a[j][i - 1] == '1') && (barrels[j] == 1)) {
				medcard[i] = 1;
				alivenegros[i] = 0;
			}
		}
	}
	
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 241; j++) {
			if ((a[j][i - 1] == '2') && (barrels[j] == 1)&&alivenegros[i] == 1) {
				medcard[i] = 2;
				alivenegros[i] = 0;
			}
		}
	}
	int ans=0;
	for (int i = 1; i < 6; i++) {
		ans += medcard[6 - i] * pow(3, i - 1);
	}
	std::cout << "Poisoned barrel is barrel number - " << ans;
}