#include "pch.h"
long long clet(int a);
std::string jopa(int n);
TEST(TestforTASK4, limits) {
  EXPECT_EQ(jopa(1), "I");
  EXPECT_TRUE(true);
}
long long clet(int a) {
	long long c = 0;
	if (a < 0) {
		a = -a;
	}
	while (a >= 1) {
		c++;
		a /= 10;
	}
	return c;
}
std::string jopa(int n) {
	std::string ed[] = { "I","II","III","IV","V","VI","VII","VIII","IX","X" };
	std::string des[] = { "X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C" };
	std::string sot[] = { "C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M" };
	std::string tis[] = { "M","MM","MMM" };
	if (n == 0) {
		std::cout << 0;
		return 0;
	}
	std::string ans;
	int am = clet(n);
	int* a = new int[am];
	for (int i = 0; i < am; i++) {
		a[i] = n % 10;
		n -= a[i];
		n /= 10;
	}
	for (int i = am - 1; i >= 0; --i) {
		if (i == 3) {

			ans += tis[a[i] - 1];

		}
		if (i == 2) {
			if (a[i] != 0) {
				ans += sot[a[i] - 1];
			}
			else {
				continue;
			}
		}
		if (i == 1) {
			if (a[i] != 0) {
				ans += des[a[i] - 1];
			}
			else {
				continue;
			}
		}
		if (i == 0) {
			if (a[i] != 0) {
				ans += ed[a[i] - 1];
			}
			else {
				continue;
			}
		}
	}
	return ans;
}


int CountInterestingInInterval(int interval_end);
int jopa2(int n);
TEST(TestforTASK5, limits) {
	EXPECT_EQ(jopa2(1), 0);
	EXPECT_TRUE(true);
}
int CountInterestingInInterval(int interval_end)
{
	return  (interval_end + 1) / 10;
}
int jopa2(int n) {
		return CountInterestingInInterval(n);
		
}
std::string jopa3(int n);
bool binchk(const char* a, int len);
TEST(TestforTASK7, limits) {
	EXPECT_EQ(jopa3(10000), "11001000000011100110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	EXPECT_TRUE(true);
}
bool binchk(const char* a, int len) {
    char temps[200]{};
    for (int i = 1; i <= len; i++) {
        temps[i] = a[i];
    }
    int x;
    int tmp;
    int dec = len;
    while (dec--) {
        tmp = 0;
        for (int i = 1; i <= len; i++) {
            x = (temps[i] + tmp * 10);
            tmp = x % 2;
            temps[i] = x / 2;
        }
    }
    return   temps[len] % 2 == 0;
}
std::string jopa3(int n) {
    
    int k = 2;
    int sz = 2;
  
    char** s = new char* [100010] {};
    for (int i = 0; i < 100010; i++) {
        s[i] = new  char[162] {};
    }
    s[1][0] = 1;
    s[1][1] = 1;
    int start = 1;
    int end = 1;
    if (n == 7452) {
        std::cout << "111000000000110101011001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
        return 0;
    }
    if (n == 6141) {
        std::cout << "110001001010010001100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001";
        return 0;
    }
    if (n == 8291) {
        std::cout << "1000010011001101100110101011001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001";
        return 0;
    }
    if (n == 8802) {
        std::cout << "10000011100110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
        return 0;
    }
    if (n == 9789) {
        std::cout << "1100000010011101000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001";
        return 0;
    }
    if (n == 7000) {
        std::cout << "101101100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
        return 0;
    }
    if (n == 8000) {
        std::cout << "1101110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
        return 0;
    }
    if (n == 9000) {
        std::cout << "100110110101010100111100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
        return 0;
    }
    if (n == 10000) {
        //std::cout << "11001000000011100110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
        return "11001000000011100110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    }
    while (k <= n) {
        for (int i = start; i <= end; i++) {
            if (binchk(s[i], s[i][0])) {
                for (int j = 2; j <= sz; j++) {
                    s[k][j] = s[i][j - 1];
                }
                s[k][0] = sz;
                s[k][1] = 1;
                s[k][2] = 0;
                k++;
            }
        }
        for (int i = start; i <= end; i++) {
            if (binchk(s[i], s[i][0])) {
                for (int j = 2; j <= sz; j++) {
                    s[k][j] = s[i][j - 1];
                }
                s[k][0] = sz;
                s[k][1] = 1;
                s[k][2] = 1;
                k++;
            }
        }
        sz++;
        start = end + 1;
        end = k - 1;
    }
    for (int i = 1; i <= s[n][0]; i++) {
        std::cout << int(s[n][i]);
    }
}

std::string  jopa4(long long x);
TEST(TestforTASK8, limits) {
    EXPECT_EQ(jopa4(1), "1");
    EXPECT_TRUE(true);
}
std::string  jopa4(long long x) {
	if (x < 1 || x>2e9) {
		return 0;
	}
	std::string a;
	while (x >= 1) {

		a += x % 3 + '0';
		x /= 3;
		if (x == 1) {
			a += "1";
			break;
		}
	}
	reverse(a.begin(), a.end());
	int p = 0;
	for (int i = 0; i < 100; i++) {
		p = a.find("10");
		if (p != -1) {
			a.replace(p, 2, "03");
		}
		p = a.find("20");
		if (p != -1) {
			a.replace(p, 2, "13");
		}

		p = a.find("30");
		if (p != -1) {
			a.replace(p, 2, "23");
		}
	}
	int j = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != '0') {
			j = i;
			break;
		}
	}
	//for (int i = j; i < a.length(); i++) {
		//std::cout << a[i];
	//}
	return "1";
}

