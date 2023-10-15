#include <iostream>
long long sum(long long num) {
	long long sum = 0;
	if (num % 2 != 0) {
		sum = (1 + num) * (num + 1) / 4;
	}
	else {
		sum = num *num  / 4;
	}
	return sum;
}
int main() {
	int tests;
	long long num;
	long long sumf = 0;
	long long tmp;
	std::cin >> tests;
	for (int i = 0; i < tests; i++) {
		std::cin >> num;
		while (num >= 1) {
			sumf += sum(num);
			num /= 2;
		}
		std::cout << sumf<<"\n";
		sumf = 0;
	}
}

