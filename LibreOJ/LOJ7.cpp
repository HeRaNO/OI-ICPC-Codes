#include <cstdio>

char ib[90000007], *ip = ib;
inline void read(long long &x)
{
	x = 0;
	while (*ip < '0' || *ip > '9') ++ip;
	while (*ip >= '0' && *ip <= '9') x = x * 10LL + *ip++ -'0';
	return ;
}

int n = 3000000;
long long ans, x;

int main()
{
	fread(ib, 1, sizeof ib, stdin);
	for (int i = 1; i <= n; i++) read(x), ans ^= x;
	printf("%lld\n", ans);
}