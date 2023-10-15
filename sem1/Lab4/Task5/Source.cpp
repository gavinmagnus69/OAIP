#include <iostream>
int main() {
	long long m, n;
	std::cin >> m >> n;
	long double** a = new long double* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new long double[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> a[i][j];
		}
	}
	

	long double min = a[0][0], max = a[0][0];
	long double** b = new long double* [m];
	for (int i = 0; i < m; i++) {
		b[i] = new long double[n];
	}
		for (int i = 0; i < m; i++) {
		     for (int j = 0; j < n; j++) {
				 max = a[0][0];
				 for (int g = 0; g <= i; g++) {
					 
					 for (int k = 0; k <= j; k++) {
						 
						 if (max <= a[g][k]) {
							 max = a[g][k];
						 }
					 
					 }
				 
				 }
				 b[i][j] = max;


		     }
	    } 
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << b[i][j] << " ";

			}
			std::cout << "\n";
		}
}