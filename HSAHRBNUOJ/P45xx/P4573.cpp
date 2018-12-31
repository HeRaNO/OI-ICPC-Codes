#include <cstdio>
#define MAXN 1000010
using namespace std;

long long a[MAXN], ans;
int n, k, l, r;

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

inline void read(long long &x)
{
	x = 0LL;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10LL + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(k);
	for (int i = 1; i <= n; i++) read(a[i]);
	l = 1;
	r = k + 1;
	for (int i = 1; i <= n; i++)
	{
		while (r + 1 <= n && a[r + 1] - a[i] < a[i] - a[l]) l++, r++;
		printf("%lld ", a[r] - a[i] > a[i] - a[l] ? a[r] : a[l]);
	}
	return 0;
}