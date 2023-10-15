#include <iostream>
#include <cmath>
int main() {
	long long i,a,b,sum;
	i = 1;
	sum = 0;
	while (i == 1|| i <= 30) {
		if (i % 2 == 0) {
			a = i/2;

		}
		else { a = i; }
		if (i % 2 == 0) {
			b= i*i*i;

		}
		else { b = i * i; }
		sum =sum + (a - b) * (a - b);
		i++;
	}

	std::cout << sum;

}