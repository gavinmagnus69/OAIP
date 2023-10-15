#include <iostream>
int main() {
	long long m, n;
	std::cin >> m;
	long long** a = new long long* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new long long[m];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}
	std::cin >> n;
	long long** b = new long long* [n];
	for (int i = 0; i < n; i++) {
		b[i] = new long long[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> b[i][j];
		
		}
	}
	long long** c = new long long * [m];
	for (int i = 0; i < m; i++) {
		c[i] = new long long [m];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << c[i][j]<<" ";
		}
		std::cout << "\n";
	}
	for (int count = 0; count < m; count++)
		delete [] a[count];
	for (int count = 0; count < n; count++)
		delete [] b[count];
	for (int count = 0; count < m; count++)
		delete [] c[count];


}