#include <iostream>
#include <iomanip>
#include <cmath>
int main() {
	long double k, x, y, s;
	std::cin >> k >> x >> y;
	if (k < 0) {
		k *= (long double)-1;
		x *= (long double)-1;
		y *= (long double)-1;
	}
	if (x > 0 && x < k && y>0 && y < k) {
		s = std::min(std::min(x, (k - x)), std::min(y, (k - y)));

	}
	if ((x == 0 && y >= 0 && y <= k) || (x == k && y >= 0 && y <= k) || (y == k && x >= 0 && x <= k) || (y == 0 && x >= 0 && x <= k)) {
		s = 0;

	}
	if (x >= 0 && x <= k && y > k) {
		s = y - k;

	}
	if (x >= 0 && x <= k && y < 0) {
		y = std::abs(y);
		s = y;




	}
	if (x > k && y <= k && y >= 0) {
		s = x - k;


	}
	if (x < 0 && y <= k && y >= 0) {

		x = std::abs(x);
		s = x;

	}
	if (x > k && y > k) {
		s = sqrtl((x - k) * (x - k) + (y - k) * (y - k));

	}
	if (x<0 && y>k) {
		s = sqrtl(std::abs(x) * std::abs(x) + (y - k) * (y - k));

	}
	if (x < 0 && y < 0) {
		s = sqrtl(x * x + y * y);

	}
	if (x > k && y < 0) {
		s = sqrtl((x - k) * (x - k) + y * y);
	}
	std::cout << std::setprecision(22) << s;
	return 0;


}