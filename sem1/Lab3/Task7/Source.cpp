#include <iostream>
#include <iomanip>
#include <cmath>
# define M_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
long double clet(long double a) {
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
long double sinn(long double x)
{
	long double ii = 0;
	long double a,b,c,d;
	
	c = 0;
	
	for (ii = 0; ii <=100; ii++)
	{
		c += powl(-1, ii) * powl(x, 2 * ii + 1) / fact(2 * ii + 1);
		
	}
	return c;
}
long double coss( long double x)
{
	long double ii = 0;
	long double a;
	a = 0;
	for (ii = 0; ii <= 100; ii++)
	{
		a += powl(-1, ii) * powl(x, 2 * ii ) / fact(2 * ii );
	}
	return a;
}
long double ln(long double x)
{
	if (x < 0)
	{
		x *= -1;
	}
	long double g = 0;
	long double y;
	y = x;
	if (x > 2) {
		while (x > 2)
		{
			x = x / 2.71828182845904;
			g++;
		}
	}
	
	if (x < (1e-4)) {
		g = -4;
		while (x < (1e-4)) {
			x *= 2.71828182845904;
			g--;
		}
	}
	long double e = 0;
	long long ii = 0;
	for (ii = 1; ii <= 100; ii++) 
	{
		e += powl(-1, ii + 1) * powl(x - 1, ii) / ii;	
	}
	long double ee;
	ee = 0;
	e += g;
	if (y < 0.00001) {
		ee =e;
		ee *= -1;
		return ee;
	}
	else {
		return e;
	}
}
int main()
{
	std::cout << std::setprecision(20);
	long double i,a,b,c,x,y,tmp;
	std::cout << "enter x\n";
	std::cin >>x;
	
	
	y = x;
	if (x < 0) {
		x *= -1;
	
	}
	long double qua1,qua = clet(x);
	if (x > 30) {
		x -= 3 * M_PI * powl(10, qua - 2);
		qua1 = clet(x);
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		}
		qua = qua1;
		while (qua1 == qua && qua1 >= 2) {
			x -= 3 * M_PI * powl(10, qua - 2);
			qua1 = clet(x);


		};
	}
	std::cout << x << "\n";
	if (x == 0) {

		std::cout << "error";
		return 0;
	}
	if (y < 0) {
	
		a = -sinn(x);
		b = coss(x);
		c = ln(y);
		if (y > 970000) {
			a = sinn(x);

		}
		if (y > 1e7) {
			b = -coss(x);
		}
		std::cout << "sinx = " << a << " cosx = " << b << " ln|x| = " << c << "\n";
		if (c <= b && c <= a) {
			std::cout << "min is ln|x| = " << c;
			return 0;
		}
		else if (b <= a && b <= c) {
			std::cout << "min is cosx =  " << b;
			return 0;
		}
		else {
			std::cout << " min is sinx = " << a;
			return 0;
		}
	}
	a = sinn(x);
	b = coss(x);
	c = ln(y);
	if (y > 990000) {
		a = sinn(x);

	}
	if (y > 1e7) {
		b = coss(x);
	}
	std::cout << "sinx = " << a << " cosx = " << b << " ln|x| = " << c << "\n";
	if (c <= b && c <= a) {
		std::cout << "min is ln|x| = " << c;
		return 0;
	}
	else if (b <= a && b <= c) {
		std::cout << "min is cosx =  " << b;
		return 0;
	}
	else {
		std::cout << " min is sinx = " << a;
		return 0;
	}
	return 0;
}