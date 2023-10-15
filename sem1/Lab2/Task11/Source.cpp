#include <iostream>
#include <cmath>
int main() {
	setlocale(LC_ALL, "Russian");
	long double PI = 3.141592653589793;
	long double r, p, q;
	std::cout << "������� ������������� �������� ������� �����: ";
	std::cin >> p;
	if (p <= 0) {
		std::cout << "������� �������� ��������";
		return 0;
	
	}
	std::cout << "������� ������������� �������� ������� ����: ";
	std::cin >> r;
	if (r <= 0) {
		std::cout << "������� �������� ��������";
		return 0;
	}
	std::cout << "������� ������ ����: ";
	std::cin >> q;
	if ((q<0) || (q>(PI / (long double)2))) {
		std::cout << "������� �������� �������� ����";
		return 0;
	}
	long double sinq,h,rr;
	sinq = std::sin(q);
	h = p * sinq;
	rr = h / 2;
	if (rr < r) {
		std::cout << "NO";
		return 0;
	
	}
	std::cout << "YES";
	return 0;
}