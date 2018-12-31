//Code By HeRaNO
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double n, e = 1.0, s = 1.0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		s = s * i;
		e = e + 1.0 / s;
	}
	printf("%.10lf", e);
	return 0;
}