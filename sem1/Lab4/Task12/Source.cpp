#include <iostream>
#include <cmath>
int main() {
		long long n; 
		std::cin >> n;
		long long u, d, m, x;
		x = sqrt(n);
		d = x * x + 1;
		u = (x + 1) * (x + 1);
		m = (d + u) / 2;
		if (n == x * x) {
			std::cout << x-1 << " " << 0 << "\n";
			return 0;
		}
		else if (n <= m)
		{
			std::cout  << x  - (m - n) << " " << x  << "\n";
			return 0;
		}
		else {
			std::cout << x  << " " << x - (n - m) << "\n";
			return 0;
		}
	return 0;
}

