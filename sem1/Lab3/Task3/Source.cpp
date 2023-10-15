#include <iostream>
#include <cmath>
int main()
{
	const long double pi = 3.1415926;
	long double i, a = 0, b = pi/2., m = 20, h,x;
	h = (b - a) / m;
	long double d,y;
	std::cout << "enter step\n";
	std::cin >> d;
	i = 0;
	for (i=0; i <= b; i += d) {
		x = a + i * h;
		y = sin(x) - cos(x);
		std::cout<<y << "\n";
	
	
	}



}