#include <cstdio>
#define MAXH 45010

int dp[MAXH], V, n, x;

inline void max(int &a, int b)
{
	if (a < b) a = b;
	return ;
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
	read(V);
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(x);
		for (int j = V; j >= x; j--) max(dp[j], dp[j - x] + x);
	}
	printf("%d\n", dp[V]);
	return 0;
}