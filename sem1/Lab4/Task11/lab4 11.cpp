#include <iostream>
#include <stdlib.h>
#include <conio.h>
using std::cin;
using std::endl;
using std::cout;
using std::cerr;
void input(long long* a) {
	while (true) {
		std::cin >> *a;
		if (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ')) {
			cin.clear();
			cin.ignore(111111, '\n');
			
			cerr << "Incorrect input\n";
		}

		else
			return;
	}
}
void task() {
	std::cout << "TASK 11\n";
	std::cout << "The input is a field for playing minesweeper with a size of n * m characters, where character '.' means empty space and '*' means bomb.Required to supplementthis is a field of numbers, as in the original game.\n";
	long long n, m;
	std::cout << "enter n and m of the field(only positive integer numbers)\n";
	input(&n);
	input(&m);
	if (n <= 0 || m <= 0) {
		std::cout << "incorrect input";
		return;
	}
	char** a = NULL;
	a = (char**)malloc((n + 2) * sizeof(char*));

	for (int i = 0; i < n + 2; i++) {
		a[i] = (char*)malloc((m + 2) * sizeof(char));
	}
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			a[i][j] = '.';
		}
	}
	std::cout << "\n enter field\n";
	
	for (int i = 1; i <n+1 ; i++) {
		for (int j = 1; j < n + 1; j++) { 
			std::cin >> a[i][j];
			while (a[i][j] != '.' && a[i][j] != '*') {
				cerr << "\nIncorrect Input\n";
				std::cin >> a[i][j];
			}
		}
	}
	std::cout << "/////////////////////////////\n";
	int cnt = 0;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
		
			if (a[i][j] != '*') {
				cnt = 0;
				if (a[i - 1][j - 1] == '*') {
					cnt++;
				}
				if (a[i - 1][j] == '*') {
					cnt++;
				}
				if (a[i - 1][j + 1] == '*') {
					cnt++;
				}
				if (a[i][j - 1] == '*') {
					cnt++;
				}
				if (a[i][j + 1] == '*') {
					cnt++;
				}
				if (a[i + 1][j - 1] == '*') {
					cnt++;
				}
				if (a[i + 1][j + 1] == '*') {
					cnt++;
				}
				if (a[i + 1][j ] == '*') {
					cnt++;
				}
				a[i][j] = cnt+'0';
				if (cnt == 0) {
					a[i][j] = '.';
				}


			}
			else { continue; }
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			std::cout << a[i][j] << " ";
		}
		std::cout << "\n";
	}
	for (int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
}
int main() {
	while (true) {
		task();
		cout << "\n to exit press ESC, to continue - ENTER\n" << endl;
		int a;
		do {
			a = _getch();
		} while (a != 13 && a != 27);
		if (a == 27)
			return 0;
	}
}