#include <cstdio>
#define MAXN 1010

int n, a[MAXN], b[MAXN], dp[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), read(b[i]);
	for (int i = 1; i <= n; i++)
		for (int j = n; j >= a[i]; j--)
			dp[j] = mymax(dp[j], dp[j - a[i]] + b[i]);
	printf("%d\n", dp[n]);
	return 0;
}