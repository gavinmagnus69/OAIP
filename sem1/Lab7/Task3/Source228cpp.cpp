#include <iostream>
#include <string>
#include <cmath>
void chk(int * a) {
	while (true) {
		std::cin >> *a;
		if (std::cin.fail() || (std::cin.peek() != '\n' && std::cin.peek() != ' ')) {
			std::cin.clear();
			std::cin.ignore(111111, '\n');
			std::cerr << "Incorrect input,try again\n";
		}
		else
			return;
	}
}
std::string sum(std::string x, std::string y, int osn) {
	std::string alsy = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int mval = osn ;
	int l = 0;
	int s = 0;
	std::string ls;
	std::string ss;
	
		l = x.length();
		s = y.length();
		ls = x;
		ss = y;
	
	
	int inc = 0;
	int t = 0;
	int tmp2;
	for (int i = s - 1; i >= 0; --i) {
		//std::cout << ls[l - 1 - t] << " " << ss[i] << "\n";
		int tmp = 0;
		//std::cout << alsy.find(ls[l - 1 - t]) << " " << alsy.find(ss[i]) << "\n";
		tmp = alsy.find(ls[l - 1 - t]) + alsy.find(ss[i]);
		tmp2 = tmp;
		for (int j = l - 1 - t; j >= 0; j--) {
			if (tmp2 >= mval) {
				inc = 1;
				tmp2 = tmp2 - mval;
				ls[j] = alsy[tmp2];
			}
			else {
				inc = 0;
				ls[j] = alsy[tmp2];
			}
			if (j != 0) {
				tmp2 = alsy.find(ls[j - 1]) + inc;
			}
			//std::cout << ls[j] << "\n";
		}

		t++;

	}

	return ls;
}
std::string vic(std::string x, std::string y, int osn) {
	std::string alsy = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int mval = osn;
	int l = 0;
	int s = 0;
	std::string ls;
	std::string ss;
	
		l = x.length();
		s = y.length();
		ls = x;
		ss = y;
	
	int dec = 0;
	int t = 0;
	int tmp2;
	for (int i = s - 1; i >= 0; --i) {
		//std::cout << ls[l - 1 - t] << " " << ss[i] << "\n";
		int tmp = 0;
		//std::cout << alsy.find(ls[l - 1 - t]) << " " << alsy.find(ss[i]) << "\n";
		tmp = alsy.find(ls[l - 1 - t]) - alsy.find(ss[i]);
		tmp2 = tmp;
		for (int j = l - 1 - t; j >= 0; j--) {
			if (tmp2 <0) {
				dec = -1;
				tmp2 = mval-abs(tmp2);
				ls[j] = alsy[tmp2];
			}
			else {
				dec = 0;
				ls[j] = alsy[tmp2];
			}
			if (j != 0) {
				tmp2 = alsy.find(ls[j - 1]) + dec;
			}
			//std::cout << ls[j] << "\n";
		}

		t++;

	}

	return ls;


}
    int main() {          
	std::string alsy = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int osn = 0;
	std::cout << "enter system otchislen\n";
	while (1) {
		chk(&osn);
		if (osn < 2 || osn>36) {
			std::cout << "wrong input,try again\n";
			continue;
		}
		else {
			break;
		}
	}
	alsy.erase(osn);
	std::string x;
	std::cout << "enter first num\n";
	while (1) {
		bool mist = 0;
		std::cin >> x;
		int ii = 0;
		if (x[0] == '-') {
			ii = 1;
		}
		for (int i = ii; i < x.length(); i++) {
			x[i]=toupper(x[i]);
			if (alsy.find(x[i]) == std::string::npos) {
				std::cout << "wrong input,try again\n";
				mist = 1;
				break;
			}
			else {
				continue;
			}
		}
		if (mist == 0) {
			break;
		}
	}
	std::string y;
	std::cout << "enter second num\n";
	while (1) {
		bool mist = 0;
		std::cin >> y;
		int ii = 0;
		if (y[0] == '-') {
			ii = 1;
		}
		for (int i = ii; i < y.length(); i++) {
			y[i]=toupper(y[i]);
			if (alsy.find(y[i]) == std::string::npos) {
				std::cout << "wrong input,try again\n";
				mist = 1;
				break;
			}
			else {
				continue;
			}
		}
		if (mist == 0) {
			break;
		}
	}
	std::cout << x << " " << y<<"\n";
	bool flagx = 0;
	if (x[0] == '-') {
		flagx = 1;
		x.erase(x.begin(), x.begin() + 1);
	}
	x.insert(0, "0");
	x.insert(0, "0");
	bool flagy = 0;
	if (y[0] == '-') {
		flagy = 1;
		y.erase(y.begin(), y.begin() + 1);
	}
	long long sumx = 0,sumy=0;
	int t = 0;
	sumx = x.length();
	if (flagx == 1) {
		sumx *= -1;
	}
	y.insert(0, "0");
	y.insert(0, "0");
	std::cout << x << " " << y << "\n";
	t = 0;
	sumy = y.length();
	if (flagy == 1) {
		sumy *= -1;
	}
	//std::cout << sumx << " " << sumy << "\n";
	std::cout << "answer is : \n";
	if (sumx > 0 && sumy > 0 && sumx > sumy) {
		std::cout << sum(x, y, osn) << " " << vic(x, y, osn);
		return 0;
	}
	if (sumx > 0 && sumy > 0 && sumx <= sumy) {
		std::cout << sum(y, x, osn) << " " << vic(y, x, osn);
		return 0;
	}
	if (sumx <= 0 && sumy <= 0 && sumx <= sumy) {
		std::cout <<"-"<< sum(x, y, osn) << " -" << vic(x, y, osn);
		return 0;
	}
	if (sumx <= 0 && sumy <= 0 && sumx >= sumy) {
		std::cout << "-" << sum(x, y, osn) << " " << vic(y, x, osn);
		return 0;
	}
	if (sumx >= 0 && sumy <= 0 && sumx <= abs(sumy)) {
		std::cout << "-" << vic(y, x , osn) << " " << sum(x, y, osn);
		return 0;
	}
	if (sumx >= 0 && sumy <= 0 && sumx >= abs(sumy)) {
		std::cout << "" << vic(x , y , osn) << " " << sum(x, y, osn);
		return 0;
	}
	if (sumx <= 0 && sumy >= 0 && abs(sumx) >= abs(sumy)) {
		std::cout << "-" << vic(x, y, osn) << " -" << sum(x, y, osn);
		return 0;
	}
	if (sumx <= 0 && sumy >= 0 && abs(sumx) <= abs(sumy)) {
		std::cout << "" << vic(y, x, osn) << " -" << sum(x, y, osn);
		return 0;
	}

	


}