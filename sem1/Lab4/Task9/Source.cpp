#include <iostream>
#include <stdlib.h>
#include <conio.h>
void chk(long long* a) {
	while (true) {
		std::cin >> *a;
		if (std::cin.fail()||(std::cin.peek() != '\n' && std::cin.peek() != ' ')) {
			std::cin.clear();
			std::cin.ignore(111111, '\n');
			std::cerr << "Incorrect input,try again\n";
		}
		else
			return;
	}
}
void task() {
	std::cout << "TASK 9\n";
	std::cout << "Given a three-dimensional dynamic array of size n^3 integers non - negative numbers.It is necessary to determine the diagonal with the largestsum of numbers\n";
	std::cout << "enter positive integer n(only numbers):\n";
	long long n;
	chk(&n);
	long long*** a = NULL;
	a = (long long***)malloc(n * sizeof(long long));
	for (int i = 0; i < n; i++) {
		a[i] = (long long**)malloc(n * sizeof(long long));

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = (long long*)malloc(n * sizeof(long long));
		}
	}
	std::cout << "please, enter elements of array (elements of numbers)\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int g = 0; g < n; g++) {
				chk(&a[i][j][g]);
               
			}
		}
	}
	long long sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	for (int i = 0; i < n; i++) {

		sum1 += a[i][i][i];
		sum2 += a[i][i][n-i-1];
		sum3 += a[n - i - 1][i][i];
		sum4 += a[i][n - i - 1][i];
	}
	std::cout << "diagonales sums  = " << sum1 << " " << sum2 << " " << sum3 << " " << sum4<<"\n";
	std::cout << "max sum diagonale - \n";
	if (std::max(std::max(sum1, sum2), std::max(sum3, sum4)) == sum1) {
		for (int i = 0; i < n; i++) {
			std::cout << a[i][i][i] << " ";
			
		}
	}
	else if (std::max(std::max(sum1, sum2), std::max(sum3, sum4)) == sum2) {
		for (int i = 0; i < n; i++) {
			std::cout << a[i][i][n-i-1] << " ";
		}
	}
	else if (std::max(std::max(sum1, sum2), std::max(sum3, sum4)) == sum3) {
		for (int i = 0; i < n; i++) {
			std::cout << a[n-i-1][i][i] << " ";
		}
	}
	else if (std::max(std::max(sum1, sum2), std::max(sum3, sum4)) == sum4) {
		for (int i = 0; i < n; i++) {
			std::cout << a[i][n-i-1][i] << " ";
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
				free(a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
}
int main() {
	while (true) {
		task();
		std::cout << "\npress  ESC to exit, press ENTER to continue\n" << std::endl;
		int a;
		do {
			a = _getch();
		} while (a != 13 && a != 27);
		if (a == 27)
			return 0;
	}
}