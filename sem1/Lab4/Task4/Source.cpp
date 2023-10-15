#include <iostream>

int main() {
	long long m, n;
	std::cin >> m >> n;
	long double ** array = new long double * [m+2];
	for (int i = 0; i < m+2; i++) {
		array[i] = new long double[n+2];
	
	}
	for (int i = 0; i < m + 2; i++) {
		for (int j = 0; j < n+2; j++) {
			array[i][j] = INFINITY;
		}
	}
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			std::cin >> array[i][j];
		}
	}
	long long amount = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i != 0 && i != m - 1 && j != 0 && j != n - 1) {
				if (array[i][j] < array[i][j - 1] && array[i][j] < array[i][j + 1] && array[i][j] < array[i + 1][j] && array[i][j] < array[i - 1][j]&& array[i][j] <array[i-1][j-1]&& array[i][j] < array[i-1][j+1]&& array[i][j] <array[i+1][j-1]&& array[i][j] < array[i+1][j+1]) {
					amount++;
				}
			
			}
		}
	
	}
	std::cout<< amount;
	for (int i = 0; i < m; i++) {
		delete[] array[i];
	
	}
}