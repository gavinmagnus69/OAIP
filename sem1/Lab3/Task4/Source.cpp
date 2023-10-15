#include <iostream>
int main() {
	long long n,a;
	std::cin >> n;
	if (n <= 0) {
		std::cout << "incorrect input";
		return 0;
	}
	if (n % 2 != 0) {
		n -= 1;
	}
	else n = n;
	long long sum = 0,i=0;
	a = 2;
	for (a=2; a <n ; a+=2) {
		sum += a;
	
	}
	std::cout <<" loop " << sum + n << " ";
	long double sum2;
	sum2 = (2 + n) / 2 * (n / 2);
	std::cout << " progression " << sum2;
	return 0;
}