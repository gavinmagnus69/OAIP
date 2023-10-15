#include <iostream>
#include <cstdio>
void chklong(long long* a) {
	while (true) {
		std::cin >> *a;
		std::cin.ignore(111111, '\n');
		if (std::cin.fail() || (std::cin.peek() != '\n' && std::cin.peek() != ' ')) {
			std::cin.clear();
			std::cin.ignore(111111, '\n');
			std::cerr << "Incorrect input,try again\n";
		}
		else
			return;
	}
}
int zxc() {
	char* a = new char[81];
	int i = 0, tmp = 0;
	int am = 0;
	while (tmp != '\n') {
		tmp = 0;
		tmp = getchar();
		if (tmp == 32) {
			am++;
		}
		a[i] = tmp;
		i++;

	}
	int ans = ++am;
	return ans;
}
int main() {
	int am = zxc();
	int ans;
	long long price;
	std::cout << "\nalright,enter price of 1 word:\n";
	chklong(&price);
	ans = price * am;
	std::cout << "the total price of telegram is " << ans<<" shekels";
}