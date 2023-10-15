#include <iostream>
#include <cmath>
int main() {
	long double e = 0.001;
	long double sum,d;
	int i;
	sum = 0;
	i = 1;
	do {
		
		d = 1. / (long double)std::pow(2., i) + 1. / std::pow(3., i);
		sum += d;
		i++;

		
	
		
	} while (d > e);
	std::cout << sum << "\n";
	

}