#include <iostream>
#include <string>
#include <cmath>
int main() {
	long long x;
	std::cout << "enter x \n";
	
	std::cin >> x;
	long long pretemp = x;
	x = abs(x);
	long long m[3] = { -3,-37,-89 };
	
	
	long long y;
	for (int e = 0; e < 3; e++) {
		x = pretemp;
		int * a = new int[65];
		if (x < 0) {
			a[63] = 1;
		}
		for (int i = 0; i < 64; i++) {
			a[i] = 0;
		}
		int l = 0;
		int i = 0;
		if (x < 0) {
			a[63] = 1;
			x = abs(x);

		}
		while (x >= 1) {

			if (x % 2 == 0) {
				a[i] = 0;
				i++;
				x /= 2;
				//std::cout << x << "\n";
				++l;
			}
			else {
				a[i] = 1;
				i++;
				x /= 2;
				//std::cout << x << "\n";
				++l;
			}
		}
		y = m[e];
		std::cout << "delimost na " << y << " : ";
		/*if (abs(pretemp) < abs(y)) {
			std::cout << "NO\n";
			continue;
		}*/
		long long tmp2 = y;
		int* b = new int[65];
		for (int i = 0; i < 64; i++) {
			b[i] = 0;
		}
		if (y < 0) {
			b[63] = 1;
			y = abs(y);
		}
		i = 0;
		int l2 = 0;
		
		
		while (y >= 1) {

			if (y % 2 == 0) {
				b[i] = 0;
				i++;
				y /= 2;
				//std::cout << y << "\n";
				++l2;
			}
			else {
				b[i] = 1;
				i++;
				y /= 2;
				//std::cout << y << "\n";
				++l2;
			}
		}
		//additional code for y
		if (b[63] == 1) {
			for (int i = 0; i < 63; i++) {
				if (b[i] == 1) {
					b[i] = 0;
				}
				else {
					b[i] = 1;
				}
			}
			b[0] += 1;
			for (int i = 0; i < 63; i++) {
				if (b[i] == 2) {
					b[i] = 0;
					b[i + 1] += 1;
				}
			}
		}
		
		bool flag = 0;
		while (1) {
			for (int i = 0; i < 64; i++) {
				a[i] += b[i];
				for (int j = 0; j < 64; j++) {
					if (a[j] == 2) {
						a[j] = 0;
						a[j + 1] += 1;
					}
				}

			}
			if (a[63] == 1) {
				a[0] -= 1;
				for (int i = 0; i < 57; i++) {
					if (a[i] == -1) {
						a[i] = 1;
						a[i + 1] -= 1;
					}
				}
				i = 62;
				while (a[i] != 1) {
					--i;
				}
				for (int j = 0; j < i + 1; j++) {
					if (a[j] == 1) {
						a[j] = 0;
					}
					else {
						a[j] = 1;
					}

				}
			}
			if (a[63] == 1) {
				std::cout << "NO\n";
				
				break;
			}
			for (int i = 63; i >= 0; i--) {
				if (a[i] == 0) {
					flag = 1;
				}
				else {
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				std::cout << "YES\n";
				
				break;
			}
			
		}
	}
}