#include <iostream>
#include <cmath>
#include <iomanip>
long double fact(long double a)
{
long double i = 1;
long double sumf = 1;
for (i = 1; i <= a; i++) 
   {
	sumf *= i;
   }
return sumf;
}
long double sum(long long n, long double x)
{
	long double ii = 0;
	long double a;
	a = 0;
	for (ii = 0; ii <= n; ii++)
	{
		a += pow(-1, ii) * pow(x, 2 * ii + 1) / fact(2 * ii + 1);
	}
	return a;
}
int main()
    {
	long double x, i;
	long long n,amount;

	std::cout << "enter n\n";
	std::cin>>n;
	if (n < 0) {
		std::cout << "incorrect input";
		return 0;
	}
	std::cout << std::setprecision(10);
	std::cout << "enter amount of x\n";
	std::cin >> amount;
	if (amount < 0) {
		std::cout << "incorrect input";
		return 0;
	}
	std::cout << "enter x from 0.1 to 1\n";
	for (i = 1; i <= amount; i++) {
		std::cin >> x;
		std::cout <<"my sin = " << sum(n, x) << " || cmath sin = "<< sin(x) << "\n";
		if (i == amount) {
			break;
		}
		std::cout << "and once more\n";
	}
}