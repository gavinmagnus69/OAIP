#include <iostream>
#include <cstdio>
int main() {
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
		i++;//length of string

	}
	char* c = new char[i];
	for (int q = 0; q < i; q++) {
		c[q] = a[q];
	}
	int d = ++am;
	char** b = new char* [d];
	for (int i = 0; i < d; i++) {
		b[i] = new char[81];
	}
	int j = 0;
	int s = 0;
	for (int y = 0; y < d; y++) {
		for (int x = 0; x < 81; x++) {
			b[y][x] = '?';
		}
	}
	for (int l = 0; l < i; l++) {
		if (c[l] == 32) {
			s++;
			j = 0;
			continue;
		}
		b[s][j] = c[l];
		j++;
	}
	std::cout << "matrix\n";
	for (int g = 0; g < d; g++) {
		for (int gg = 0; b[g][gg] != '?'; gg++) {
			std::cout << b[g][gg];
		}
		std::cout << "\n";
	}
	int sumofem = 0;
	bool* ev = new bool[d];
	for (int qwe = 0; qwe < d; qwe++) {
		ev[qwe] = 0;
	}
	int zxc = 0;
	for (int g = 0; g < d; g++) {
		for (int gg = 0; b[g][gg] != '?'; gg++) {
			if (b[g][gg] == '?') {
				continue;
			}
			sumofem += (int)b[g][gg];
		}
		if (sumofem % 2 == 0) {
			ev[zxc] = true;
			zxc++;
		}
		//std::cout << sumofem << "\n";
		sumofem = 0;
	}
	/*for (int zxc = 0; zxc < d; zxc++) {
		std::cout << ev[zxc]<<"\n";

	}*/
	std::cout << "/////////////////////\n";
	std::cout << "new matrix\n";
	for (int g = 0; g < d; g++) {
		if (ev[g]) {
			int  gg = 80;
			for (gg; gg >= 0; gg--) {
				if (b[g][gg] == '?') {
					continue;
				}
				std::cout << b[g][gg];
			}
		}
		else {
			for (int gg = 0; b[g][gg] != '?'; gg++) {
				std::cout << b[g][gg];
			}

		}
		std::cout << "\n";
	}
}