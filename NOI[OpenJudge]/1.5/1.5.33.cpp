//Code By HeRaNO
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a;
	double b;
	cin >> a;
	b = 1.0;
	for (int i = 2; i <= a; i++)
	{
		if (i % 2) b = 1.0 / i + b;
		else b = -1.0 / i + b;
	}
	printf("%0.4lf", b);
	return 0;
}