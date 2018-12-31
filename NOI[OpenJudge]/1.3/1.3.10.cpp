//Code By HeRaNO
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	float a, b, c;
	cin >> a >> b;
	c = 1 / (1 / a + 1 / b);
	printf("%.2f", c);
	return 0;
}