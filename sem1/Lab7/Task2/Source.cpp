#include <iostream>
#include <string>
#include <cmath>
int main() {
	long long x;
	long long y;
	std::cout << "\nenter x and y\n";
	std::cin >> x>>y;
	long long tmp1 = x, tmp2 = y;
	int* a = new int[65];
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
	
	//прямой кид
	std::cout << "primoy x \n";
	for (int i = 63; i >= 0; i--) {
		std::cout << a[i];
	}
	std::cout << "\n";
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
	
	//straight code for y
	std::cout << "primoy y\n";
	for (int i = 63; i >= 0; i--) {
		std::cout << b[i];
	}
	std::cout << "\n";
	//additional code for x
	if (a[63] == 1) {
		for (int i = 0; i < 63; i++) {
			if (a[i] == 1) {
				a[i] = 0;
			}
			else {
				a[i] = 1;
			}
		}
		a[0] += 1;
		for (int i = 0; i < 63; i++) {
			if (a[i] == 2) {
				a[i] = 0;
				a[i + 1] += 1;
			}
		}
	}
	std::cout << "dop kod x\n";
	for (int i = 63; i >= 0; i--) {
		std::cout << a[i];
	}
	std::cout << "\n";
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
	std::cout << "dop kod y\n";
	for (int i = 63; i >= 0; i--) {
		std::cout << b[i];
	}
	std::cout << "\n";
	for (int i = 0; i < 64; i++) {
		a[i] += b[i];
		for (int j = 0; j < 64; j++) {
			if (a[j] == 2) {
				a[j] = 0;
				a[j + 1] += 1;
			}
		}
	
	}
	std::cout << "sum dop kodov\n";
	for (int i = 63; i >= 0; i--) {
		std::cout << a[i];
	}
	std::cout << "\n";
	
	if (a[63]==1) {
		a[0] -= 1;
		for (int i = 0; i < 57; i++) {
			if (a[i] == -1) {
				a[i] = 1;
				a[i + 1] -= 1;
			}
		}
		for (int i = 63; i >= 0; i--) {
			std::cout << a[i];
		}
		std::cout << "\n";
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
	std::cout << "answer is : \n";
	for (int i = 63; i >= 0; i--) {
		std::cout << a[i];
	}
	

}