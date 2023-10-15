#include <iostream>
#include <string>
#include <conio.h>

void meintask() {
	std::string s;
	getline(std::cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1' || s[i] == '0') {
			continue;
		}
		std::cout << "\nINCORRECT INPUT!!!!!!!!\n";
		return ;
	}
	for (int i = 1; i < s.length(); i++) {
		if (s[i]=='1') {
			s[i] = '0';
			continue;
		}
		s[i] = '1';
	}
	std::cout << "reverse code : \n";
	std::cout << s;
}
int main() {
	std::cout << "TASK1 lab7\ntranslation from straight to reverse\n";
	std::cout << "2281337/////////////***executed by Roman Akhmetov***///////////////2281337\n";
	while (true) {
		meintask();
		std::cout << "\npress  ESC to exit, press ENTER to continue\n" << std::endl;
		int a;
		do {
			a = _getch();
		} while (a != 13 && a != 27);
		if (a == 27)
			return 0;
	}
}