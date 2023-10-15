#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
int main() {
	long long tmp, zeros = 0;
	long long imin = 0, imax = 0;
	long long* a = new long long[1];
	long long inc = 0;
	while (std::cin >> a[inc]) {
		inc++;
		a = (long long*)realloc(a, (inc + 1) * sizeof(long long));
	}
		long long n = inc;
		long long min = a[0], max = a[0];
		for (int i = 0; i < n; i++) {
			if (a[i] <= min) {
				min = a[i];
				imin = i;
			}
			if (a[i] >= max) {
				max = a[i];
				imax = i;
			}
		}
		if (imin >= imax) {
			tmp = imin;
			imin = imax;
			imax = tmp;
		}
		long long min0 = -1, max0 = -1;
		

	long long im = imin,imx=imax;
	for (im + 1; im < imx-1; im++) {
		a[im + 1] = 0;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			zeros++;
		}
	}
	long long g = imax;
	if (zeros >= (n+1) / 2) {
		long long * b = new long long[n - zeros];
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != 0) {
				b[cnt] = a[i];
				cnt++;
			}
		
		}


		for (int i = 0; i < (n) - zeros; i++) {
			std::cout << b[i] << " ";
		}
		return 0;
		//delete [] b;
	}
	for (int i = 0; i < n; i++) {
		std::cout << a[i]<<" ";
	
	}
	//delete []  a;
}