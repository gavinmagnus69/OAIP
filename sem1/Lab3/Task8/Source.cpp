#include <iostream>
#include <cmath>
long long clet(long long a) {
	long long c = 0;
	while (a > 0) {
		c++;
		a /= 10;
	}
	return c;
}
int main() {
	long long a, b, n, i, g, m, sum, mus;
	std::cin >> a;


	i = 1;
	while (i < a) {
		n = clet(i);
		sum = 0;
		mus = i;
		while (mus > 0) {
			sum += std::pow(mus % 10, n);
			mus /= 10;


		}


		if (sum == i) {
			std::cout << sum << "\n";

		}
		i++;
	}




}