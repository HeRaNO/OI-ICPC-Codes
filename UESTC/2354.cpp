#include <bits/stdc++.h>
using namespace std;

long long n;

long long small(long long x)
{
	for (long long i = 2; i * i <= x; i++)
		if (!(x % i)) return i;
	return x;
}

int main()
{
	scanf("%lld", &n);
	if (n & 1)
		printf("%lld\n", (n - small(n)) / 2 + 1);
	else printf("%lld\n", n >> 1);
	return 0;
}
