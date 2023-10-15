#include <iostream>
#include <iomanip>
#include <cmath>
long double abss(long double a)
{
	if (a < 0) {
		a *= -1;
	}
	return a;
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
	long double a, b, c, d;
	a = 0;
	d = 1;
	c = 0;

	for (ii = 0; ii <= 100; ii++)
	{
		c += powl(-1, ii) * powl(x, 2 * ii + 1) / fact(2 * ii + 1);

	}
	return c;
}
long double coss(long double x)
{

	long double ii = 0;
	long double a;
	a = 0;
	for (ii = 0; ii <= 100; ii++)
	{
		a += powl(-1, ii) * powl(x, 2 * ii) / fact(2 * ii);
	}
	return a;
}
long double arctg(long double x) 
{

	long double ii = 0;
	long double a;
	a = 0;
	for (ii = 0; ii <= 100; ii++)
	{
		a += powl(-1, ii) * powl(x, 2 * ii+1) / (2*ii+1);
	}
	return a;

}
int main() {
	long double a,i,n, sum,stp,ans=0;
	i = 0;
	sum = 0;
	std::cout << "enter n \n";
	std::cin >>n;
	stp = 1. / n;
	a = 1000000000000000;
	for (i = 0; i <= 1; i += stp) {
		sum = sinn(i) + coss(i) -2*arctg(i);
		if (abss(sum) <= abs(a)) {
			a = sum;
			ans = i;
		}
	
	}
	std::cout <<" root = " << ans<<" while sum = "<<a;

}