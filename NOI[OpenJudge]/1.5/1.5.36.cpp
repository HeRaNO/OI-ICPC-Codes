//Code By HeRaNO
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double x, n, s = 1.0;
	cin >> x >> n;
	for (int i = 1; i <= n; ++i)
		s = s + pow(x, i);
	printf("%.2lf", s);
	return 0;
}