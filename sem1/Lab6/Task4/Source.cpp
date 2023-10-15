#include <iostream>
#include <string>
#include <conio.h>
void task() {
	std::string s;
	std::string ph = "ph";
	std::string you = "you";
	std::string ee = "ee";
	std::string th = "th";
	std::string qu = "qu";
	std::string c = "c";
	std::string q = "q";
	std::string x = "x";
	std::string w = "w";
	std::string PH = "PH";
	std::string YOU = "YOU";
	std::string EE = "EE";
	std::string TH = "TH";
	std::string QU = "QU";
	std::string C = "C";
	std::string Q = "Q";
	std::string X = "X";
	std::string W = "W";
	//std::cin >> s;
		std::cout << "Enter your text:\n";
		std::getline(std::cin, s, '\n');
		int tmp = 0;
		for (int i = 0; i < s.length(); i++) {
			tmp = s.find("yoU");
			if (tmp != std::string::npos) {
				s.erase(tmp, 3);
				s.insert(tmp, 1, 'u');
			
			}
			tmp = 0;
			tmp = s.find("yOU");
			if (tmp != std::string::npos) {
				s.erase(tmp, 3);
				s.insert(tmp, 1, 'u');

			}
			tmp = 0;
			tmp = s.find("yOu");
			if (tmp != std::string::npos) {
				s.erase(tmp, 3);
				s.insert(tmp, 1, 'u');

			}
			tmp = 0;
			tmp = s.find("You");
			if (tmp != std::string::npos) {
				s.erase(tmp, 3);
				s.insert(tmp, 1, 'U');

			}
			tmp = 0;
			tmp = s.find("YOu");
			if (tmp != std::string::npos) {
				s.erase(tmp, 3);
				s.insert(tmp, 1, 'U');

			}
			tmp = 0;
			tmp = s.find(you);
			if (tmp != std::string::npos) {
				s.erase(tmp, 3);
				s.insert(tmp, 1, 'u');
			}
			tmp = 0;
			tmp = s.find(YOU);
			if (tmp != std::string::npos) {
				s.erase(tmp, 3);
				s.insert(tmp, 1, 'U');
			}
			tmp = 0;
			tmp = s.find(ph);
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'f');
			}
			tmp = 0;
			tmp = s.find(PH);
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'F');
			}
			


			tmp = 0;
			tmp = s.find("Ph");
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'F');
			}
			tmp = 0;
			tmp = s.find("pH");
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'f');
			}
			tmp = 0;
			tmp = s.find(ee);
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'i');
			}
			tmp = 0;
			tmp = s.find(EE);
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'I');
			}
			tmp = 0;
			tmp = s.find("Ee");
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'I');
			}
			tmp = 0;
			tmp = s.find("eE");
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'i');
			}
			tmp = 0;
			tmp = s.find(th);
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'z');
			}
			tmp = s.find("Th");
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'Z');
			}
			tmp = 0;
			tmp = s.find("tH");
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'z');
			}
			tmp = 0;
			tmp = s.find("oo");
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'u');
			}
			tmp = s.find("OO");
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'U');
			}
			tmp = 0;
			tmp = s.find(TH);
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'Z');
			}
			tmp = 0;
			tmp = s.find(qu);
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'k');
				s.insert(tmp + 1, 1, 'v');
			}
			tmp = 0;
			tmp = s.find(QU);
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'K');
				s.insert(tmp + 1, 1, 'V');
			}
			tmp = 0;
			tmp = s.find("qU");
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'k');
				s.insert(tmp + 1, 1, 'V');
			}
			tmp = 0;
			tmp = s.find("Qu");
			if (tmp != std::string::npos) {
				s.erase(tmp, 2);
				s.insert(tmp, 1, 'K');
				s.insert(tmp + 1, 1, 'v');
			}
			tmp = 0;

			tmp = s.find(c);
			if (tmp != std::string::npos) {
				if (s[tmp + 1] == 'e' || s[tmp + 1] == 'i' || s[tmp + 1] == 'y') {
					s.erase(tmp, 1);
					s.insert(tmp, 1, 's');
				}
				else {
					s.erase(tmp, 1);
					s.insert(tmp, 1, 'k');

				}

			}
			tmp = 0;
			tmp = s.find(C);
			if (tmp != std::string::npos) {
				if (s[tmp + 1] == 'E' || s[tmp + 1] == 'I' || s[tmp + 1] == 'Y') {
					s.erase(tmp, 1);
					s.insert(tmp, 1, 'S');
				}
				else {
					s.erase(tmp, 1);
					s.insert(tmp, 1, 'K');

				}
			}
			tmp = 0;
			tmp = s.find(q);
			if (tmp != std::string::npos) {
				s.erase(tmp, 1);
				s.insert(tmp, 1, 'k');
			}
			tmp = 0;
			tmp = s.find(Q);
			if (tmp != std::string::npos) {
				s.erase(tmp, 1);
				s.insert(tmp, 1, 'K');
			}
			tmp = 0;
			tmp = s.find(x);
			if (tmp != std::string::npos) {
				s.erase(tmp, 1);
				s.insert(tmp, 1, 'k');
				s.insert(tmp + 1, 1, 's');
			}
			tmp = 0;
			tmp = s.find(X);
			if (tmp != std::string::npos) {
				s.erase(tmp, 1);
				s.insert(tmp, 1, 'K');
				s.insert(tmp + 1, 1, 'S');
			}
			tmp = 0;
			tmp = s.find(w);
			if (tmp != std::string::npos) {
				s.erase(tmp, 1);
				s.insert(tmp, 1, 'v');
			}
			tmp = 0;
			tmp = s.find(W);
			if (tmp != std::string::npos) {
				s.erase(tmp, 1);
				s.insert(tmp, 1, 'V');
			}
			tmp = 0;
		}
		for (int j = 0; j < s.size(); j++) {
			for (int i = 0; i < s.length(); i++) {
				//if (i == s.length() - 1) {
					//break;
				//}
				int g = 0;
				if (tolower(s[i])!='i'&& tolower(s[i]) != 'a'&& tolower(s[i]) != 'o'&& tolower(s[i]) != 'u'&& tolower(s[i]) == tolower(s[i + 1])) {
					s.erase(i+1, 1);
					i = 0;
				}
			}
		}
		std::cout << s<<"\n";
}
int main() {
	std::cout << "TASK4\nEnglish language reform\n";
	std::cout << "2281337/////////////***executed by Roman Akhmetov***///////////////2281337\n";
	while (true) {
		task();
		std::cout << "\npress  ESC to exit, press ENTER to continue\n" << std::endl;
		int a;
		do {
			a = _getch();
		} while (a != 13 && a != 27);
		if (a == 27)
			return 0;
	}
}