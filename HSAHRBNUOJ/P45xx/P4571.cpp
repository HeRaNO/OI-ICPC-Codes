#include <cstdio>
#define MAXN 2000010
using namespace std;

char ib[20000007], *ip = ib;
inline void read(int &x)
{
	x = 0;
	while (*ip < '0' || *ip > '9') ++ip;
	while (*ip >= '0' && *ip <= '9') x = x * 10 + *ip++ -'0';
	return ;
}

int n, a[MAXN], l[MAXN], r[MAXN];
long long ans;

inline void max(long long &a, long long b)
{
	if (a < b) a = b;
	return ;
}

int main()
{
	fread(ib, 1, sizeof ib, stdin);
	read(n);
	a[0] = a[n + 1] = 1 << 31;
	for (int i = 1; i <= n; i++) read(a[i]), l[i] = r[i] = i;
	for (int i = 1, j = i; i <= n; i++, j = i)
	{
		while (a[j - 1] >= a[i]) j = l[j - 1];
		l[i] = j;
	}
	for (int i = n, j = i; i; i--, j = i)
	{
		while (a[j + 1] >= a[i]) j = r[j + 1];
		r[i] = j;
	}
	for (int i = 1; i <= n; i++) max(ans, 1LL * (r[i] - l[i] + 1)*a[i]);
	printf("%lld\n", ans);
	return 0;
}