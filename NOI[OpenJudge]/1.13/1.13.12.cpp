//Code By HeRaNO
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int x[11], y[11];

int gcd(int a, int b)
{
	if (b == 0)return a;
	else return gcd(b, a % b);
}

void jia(int n, int m)
{
	int k = y[n] * y[m] / gcd(y[n], y[m]);
	x[n] = x[n] * (k / y[n]);
	x[m] = x[m] * (k / y[m]);
	x[n] = x[n] + x[m];
	y[n] = k;
	int ys = gcd(x[n], y[n]);
	x[n] /= ys;
	y[n] /= ys;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)scanf("%d/%d", &x[i], &y[i]);
	for (int i = 2; i <= n; i++)jia(i, i - 1);
	if (y[n] == 1)cout << x[n];
	else cout << x[n] << "/" << y[n];
	return 0;
}
