#include <cmath>
#include <iostream>
int main() {
	long double a, b, c,y;
	long double n;
	std::cin >> a >> b >> c;
	std::cout << "Enter integer n "<<"\n";
	std::cin >> n;
	switch (int(n)) {
		case (int)2:
			y = b * c - a * a;
			std::cout << y;
			break;
		case (int)56:
			y = b * c;
			std::cout << y;
			break;
		case (int)7:
			y = a * a + c;
			std::cout << y;
			break;
		case (int)3:
			y = a - b * c;
			std::cout << y;
			break;
		default :
			y = (a + b) * (a+b) * (a+b);
			std::cout << y;
			break;


	
	
	}


}