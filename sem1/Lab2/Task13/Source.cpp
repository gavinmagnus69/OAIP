#include <iostream>
int main(){ 
	setlocale(LC_ALL, "RU");

	long long k;
	std::cin >> k;
	if (k % 100 == 11) {
		std::cout << "�� ����� " << k << " ������ � ����";
		return 0;
	}
	if (k < 0) {
		std::cout << "ERROR";
		return 0;
	}
	if (k == 0) {
		std::cout << "�� ����� " << k << " ������ � ����";
		return 0;
	}
	if (k!=11 && k % 10 == 1) {
		std::cout << "�� ����� " << k << " ���� � ����";
		return 0;
	}
	if (k>20&&k % 10 >= 2 && k % 10 <= 4) {
		std::cout << "�� ����� " << k << " ����� � ����";
		return 0;
	}
	if (k >= 2 && k <= 4) {
		std::cout << "�� ����� " << k << " ����� � ����";
		return 0;
	
	}
	
	std::cout << "�� ����� " << k << " ������ � ����";
	return 0;



}