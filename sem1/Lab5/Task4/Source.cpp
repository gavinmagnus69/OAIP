#include <iostream>
void solve4() {
	long long m;
	long long k;
	std::cout << "Enter m of array:\n";
	std::cin >> m;
	std::cout << "enter k of array:\n";
	std::cin >> k;
	long double** a = new long double* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new long double[k];
	}
	std::cout << "\nenter elements of array:\n";
	long long cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			std::cin >> a[i][j];
			if (a[i][j] == 0) {
				cnt++;
			}
		}
	}
	long long inc = 0;

	if (cnt != 0) {
		long long ** in = new long long * [cnt];
		for (int i = 0; i < cnt; i++) {
			in[i] = new long long[2];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < k; j++) {
				if (a[i][j] == 0) {
					in[inc][0] = i;
					in[inc][1] = j;
					inc++;
				}
			}
		}
		std::cout << " amount of zeros : " << cnt<<" ";
		std::cout << "\nposition of zeros : \n";
		for (int i = 0; i < cnt; i++) {
			std::cout << in[i][0] << " " << in[i][1]<<" ";
			std::cout << "\n";
		}
		std::cout << "\n";
		for (int i = m - 1; i >= 0; i--) {
			for (int j = k - 1; j >= 0; j--) {
				std::cout << a[i][j] << " ";
			}
			std::cout << "\n";
		}

	}
	else {
		std::cout << "\n";
		for (int i = m - 1; i >= 0; i--) {
			for (int j = k - 1; j >= 0; j--) {
				std::cout << a[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
}
int main() {
	solve4();
}