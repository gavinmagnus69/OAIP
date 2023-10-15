#include <iostream>
long long ghoul(long long n) {
	if (n % 10 > 0) {
		return (n % 10);
	}
	if (n == 0) {
		n = 0;
		return n;
	}
	if (n % 10 == 0) {
		return ghoul(n / 10);

	}
}
long long ans(long long p, long long q) {
	long long sum = 0;
	for (long long i = p; i <= q; i++) {
		sum += ghoul(i);
	}
	return sum;
}
int main() {
	while (true) {
		long long p = 0, q = 0, sum = 0;
		std::cin >> p >> q;
		if (p < 0 || q < 0) {
			break;
		}
		else {
			for (int i = p; i <= q; i++) {
				sum += ghoul(i);
			}
			std::cout << sum << "\n";
		}
	}
}