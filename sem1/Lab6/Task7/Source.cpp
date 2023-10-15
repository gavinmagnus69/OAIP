#include <iostream>
#include <string>
bool plchk(std::string s) {
	int l = s.length();
	int ind = 0;
	for (int i = 0; i < l; i++) {
		if (s[i] == s[l - 1 - i]) {
			ind = 1;
		}
		else {
			ind = 0;
			return 0;
		}
	}
	return ind;
}
bool samelet(std::string s) {
	int l = s.length();
	int ind = 0;
	for (int i = 0; i < l; i++) {
		if (s[0] == s[l - 1 - i]) {
			 ind = 1;
		}
		else{
			ind = 0;
			return 0;
		}
	
	}
	return ind;

}
int main() {
	std::string s;
	std::cin >> s;
	if (samelet(s)) {
		std::cout <<-1;
		return 0;
	}
	if (!plchk(s)) {
		std::cout << s.length();
		return 0;
	}
	if (plchk(s)) {
		std::cout << s.length() - 1;
		return 0;
	}
}