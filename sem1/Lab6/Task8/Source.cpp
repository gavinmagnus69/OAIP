#include <iostream>
#include <string>
#include <algorithm>
bool check(std::string s,std::string s2) {
	bool tr = 0;
	bool chk[255];
	for (int i = 0; i < 255; i++) {
		chk[i] = 0;
	}
	for (int i = 0; i < s.length(); i++) {
		chk[s[i]] = 1;
	}
	for (int i = 0; i < s2.length(); i++) {
		for (int j = 0; j < 255; j++) {
			if ((int)s2[i] == chk[j]) {
				tr = 1;
			}
			
		}
		if (tr == 0) {
			return 0;
		}
		tr = 0;

	}
	return 1;
}
int main() {
	int count;
	std::cin >> count;
	
	for (int i = 0; i < count;i++) {
		std::string s1, s2, stmp;
		std::cin >> s1 >> s2;
		//if (!check(s1, s2)) {
			//std::cout << "case NO\n";
			//continue;
		//}
		if (s1 == s2) {
			std::cout << "YES\n";
			continue;
		}
		int len;
		len = s1.length();
		stmp = s1;
		stmp.erase(stmp.end() - 1);
		reverse(stmp.begin(),stmp.end());
		s1 += stmp;
		
		while (s1.length() > 1) {
			if (s1.find(s2)!=std::string::npos) {
				std::cout << "YES";
				break;
			}
			s1.erase(((s1.length() - 1) / 2) - 1 , 2);
		}
		if (s1.length() == 1) {
			std::cout << "NO";
			continue;
		}
			std::cout << "\n";
	}
	
}