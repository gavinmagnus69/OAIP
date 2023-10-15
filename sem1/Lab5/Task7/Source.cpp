#include <iostream>
#include <cmath>
unsigned long long  stp(unsigned long long k, unsigned long long n, long long t) {
	unsigned long long ans = 1;
	long long s = t;

	while (n > 0) {
		if (n % 2) {
			ans = (ans * k) % s;
		}
		k = (k * k) % s;
		n >>= 1;
	}
	return ans;
}
int main() {
	long long k, n, t, ans;
	int cnt = 1;
	while (1) {
		std::cin >> k >> n >> t;
		if (k == 0 && n == 0 && t == 0) {
			return 0;
		}
		t = pow(10, t);
		k %= t;
		n %= t * 2;
		ans = stp(k, n, t);
		std::cout << "\nCase #" << cnt << ": " << ans;
		cnt++;
	}
}