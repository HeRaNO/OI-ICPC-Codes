#include <bits/stdc++.h>
using namespace std;

inline int KSM(int a, int b)
{
	int res = 1, base = a;
	while (b)
	{
		if (b & 1) res = res * base % 911;
		base = base * base % 911;
		b >>= 1;
	}
	return res;
}

double pi = acos(-1.0);

long long n = 1463030063184LL, x;

long long f(long long x)
{
	return ((x & -x) + ((x - (x & -x)) & -(x - (x & -x))));
}

int main()
{
	//For Date1.in and Date5.in(in Python)
	//begin
	n = int(raw_input())
		a = raw_input()
			for x in range(1, n + 1) :
					if eval(a)
						print x
						break
						//end
						//For Date2.in
						//begin
						for (int i = 1; i <= 20021231; i++)
			{
				if (KSM(i % 911, i) + (i ^ (i % 1248679)) == 20000000)
				{
					printf("%d\n", i);
					break;
				}
			}
	//end
	//For Date3.in
	//begin
	for (int i = 1e9 - 10; i <= 1e9 + 10; i++)
	{
		if (fabs(sin(pi * ((double)i + 25) / 32)) <= 1e-8)
		{
			printf("%d\n", i);
			break;
		}
	}
	//end
	//For Date4.in
	//begin
	for (int i = 2; i * i <= n; i++)
		if (!(n % i))
		{
			x = n / i;
			if (i * f(i) == n)
			{
				printf("%d\n", i);
				break;
			}
			if (x * f(x) == n)
			{
				printf("%lld\n", x);
				break;
			}
		}
	//end
	return 0;
}