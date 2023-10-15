#include <iostream>
#include <string>
#include <cmath>
bool samelet(std::string s) {
	int l = s.length();
	int ind = 0;
	for (int i = 0; i < l; i++) {
		if (s[0] == s[l - 1 - i]) {
			ind = 1;
		}
		else {
			ind = 0;
			return 0;
		}

	}
	return ind;

}
unsigned long long  stp(unsigned long long k, unsigned long long n, long long t) {
	unsigned long long ans = 1;
	long long s = t;

	while (n > 0) {
		if (n % 2) {
			ans = (ans * k) % s;
		}
		k = (k * k) % s;
		n >>= 1;
	}
	return ans;
}
int main() {
	int count;
	int l;
	int m;
	int len1, len2;
	int raz;
	int ans;
	std::string s1;
	std::string s2;
	
	std::cin >> count;
	while (count) {
		//std::cout << "circle\n";
		std::cin >>l>>m>> s1 >> s2;
		len1 = s1.length();
		len2 = s2.length();
		if (s1.length() + s2.length() == l) {
			//std::cout << "c1\n";
			if (s2 == s1) {
				std::cout<<1<<"\n";
			
				
			}
			else {
				std::cout << 2<<"\n";
				
			}
		}
		if (s1.length() + s2.length() < l) {
			//std::cout << "c2\n";
			raz = l - s1.length() - s2.length();
			if (s2 == s1) {
				std::cout << stp(26, raz, m) % m<<"\n";
				
			}
			else {
				std::cout << (stp(26, raz, m)*2 )% m<<"\n";
			
			}
		}
		if (len1 + len2 > l) {
			//std::cout << "c3\n";
			raz = len1 + len2 - l;
			bool tr1=0;
			bool tr2=0;
			for (int i = 0 ; i < raz; i++) {
				if (s1[len1 - 1 - i] == s2[raz-1-i]) {
					tr1 = 1;
				}
				else {
					tr1 = 0;
					break;
				}
			}
			for (int i = 0; i < raz; i++) {
				if (s2[len2 - 1 - i] == s1[raz-1-i]) {
					tr2 = 1;
				}
				else {
					tr2 = 0;
					break;
				}
			}
			if (tr1 || tr2) {
				std::cout << 1<<"\n";
				
			}
			else {
				std::cout << 0 << "\n";
				
			}


		
		}

		count--;
	
	
	}


}