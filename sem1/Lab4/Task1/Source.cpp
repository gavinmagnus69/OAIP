#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iomanip>
void chklong(long long* a) {
    while (true) {
        std::cin >> *a;
        std::cin.ignore(111111, '\n');
        if (std::cin.fail() || (std::cin.peek() != '\n' && std::cin.peek() != ' ')) {
            std::cin.clear();
            std::cin.ignore(111111, '\n');
            std::cerr << "Incorrect input,try again\n";
        }
        else
            return;
    }
}
long double chk() {
    while (true) {
        bool er = 0;
        int e, m;
        bool dot = 0, E = 0;
        std::string str;
        std::cin >> str;
        std::string str1 = str;
        if (str.size() == 1 && str[0] == '-') {
            std::cerr << "\nincorrect input,try again\n";
            std::cin.ignore(111111111, '\n');
            er = 1;
            break;
        }
        for (; str[0] == '0' && str[1] == '0';)
        {
            str.erase(0, 1);
        }
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '.') {
                if (dot == 1) {
                    std::cerr << "\nincorrect input,try again\n";
                    std::cin.ignore(111111111, '\n');
                    er = 1;
                    break;
                }
                m = i;
                dot = 1;
            }
            else if (str[i] == 'E' || str[i] == 'e') {
                if (E == 1) {
                    std::cerr << "\nincorrect input, try again\n";
                    std::cin.ignore(111111111, '\n');
                    er = 1;
                    break;
                }
                e = i;
                E = 1;
            }
            else if (str[i] == 'E' && i != 0 && str[i - 1] != '-' && str[i - 1] != 'e') {
                std::cerr << "\nincorrect input,try again\n";
                std::cin.ignore(111111111, '\n');
                er = 1;
                break;
            }
            else if (str[i] != 'e' && str[i] != '.' && str[i] != 'E' && str[i] != '-' && (str[i] > '9' || str[i] < '0')) {
                std::cerr << "\nincorrect input,try again\n";
                std::cin.ignore(111111111, '\n');
                er = 1;
                break;
            }
        }
        if (er == 1) {
            continue;
        }
        if (dot == 1) {
            if (E == 1) {
                while (str[e - 1] == '0') {
                    str.erase(e - 1, 1);
                    e--;
                    m--;
                }
                while (str[e + 1] == '0') {
                    str.erase(e + 1, 1);
                    e--;
                    m--;
                }
            }
            else {
                while (str[str.size() - 1] == '0') {
                    str.erase(str.size() - 1, 1);
                }
            }
        }
        if (dot && !E) {
            str1[str1.size() - 1]--;
            if (stold(str) == stold(str1)) {
                std::cerr << "\nincorrect input,try again\n";
                std::cin.ignore(111111111, '\n');
                er = 1;
                continue;
            }
        }
        if (dot == 1 && E == 1 && str[e - 1] != '0') {
            str1[e - 1]--;
            if (stold(str) == stold(str1)) {
                std::cerr << "\nincorrect input,try again\n";
                std::cin.ignore(111111111, '\n');
                er = 1;
                continue;
            }
        }

        return stold(str);
    }
}
void task() {
	std::cout << "TASK 1-1\n";
	std::cout << "move all negative elements of the array to the beginning, preserving the original relative position both among the negative and among the remaining elements of the array\n";
	long double  arr[10000];
    long long k;
	std::cout << "enter length of array(only integer positive numbers): \n";
	chklong(&k);
	long long i = 0, b = 0;
	long double e1=0,e2=0;
	std::cout << "enter elements of array(only numbers):\n";
	for (i = 0; i <= k - 1; i++) {
        arr[i] = chk();
	}
   

	long double ab[10000];
	int c = 0;
	for (int i = 0; i < k; i++) {
		if (arr[i] < 0) {
			ab[c] = arr[i];
			c++;
		}
	}
	for (int i = 0; i < k; i++) {
		if (arr[i] >= 0) {
			ab[c] = arr[i];
			c++;
		}
	}
	std::cout << "new array : \n";
	for (int i = 0; i <= k - 1; i++) {
	
		std::cout << ab[i] << " ";
	}

}
int main() {
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