//Code By HeRaNO
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double x, a, b, c, d, y;
	cin >> x >> a >> b >> c >> d;
	y = a * x * x * x + b * x * x + c * x + d;
	printf("%.7lf", y);
	return 0;
}
