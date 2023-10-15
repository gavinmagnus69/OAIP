#include <iostream>
#include <cmath>
int main() {
	setlocale(LC_ALL, "Russian");
	long double x, z, y, a,s;
	long long n;
	std::cout << "выберете возможные значения функции:" << "\n";
	std::cout << "1 - 2x" << "\n" << "2 - x^3" << "\n" << "3 - x/3"<<"\n";
	std::cin >> n;
	
	if (n != 1 && n != 2 && n != 3) {
		std::cout << "нет такого варианта";
		return 0;
	}
	
	std::cout << "введите значения a и z"<<"\n";
	std::cin >> a >> z;
	if (z < 1) {
		x = z * z;
	}
	if (z >= 1) {
		x = z + 1;
	}
	switch (n) {
	case 1:
		std::cout << "условие 1 : f(x)=2x " << "\n";
		s = 2 * x;
		y = a * log(1 + powl(x, 1. / 5.)) + cos(s+1) * cos(s + 1);
		std::cout << y;
		break;
	case 2:
		std::cout << "условие 2: f(x)= x^3" << "\n";
		s = powl(x, 3);
		y = a * log(1 + powl(x, 1. / 5.)) + cos(s + 1) * cos(s + 1);
		std::cout << y;
		break;
	case 3:
		std::cout << "условие 3: f(x)=x/3 " << "\n";
		s = x / 3;
		y = a * log(1 + powl(x, 1. / 5.)) + cos(s + 1) * cos(s + 1);
		std::cout << y;
		break;
		



	}
}