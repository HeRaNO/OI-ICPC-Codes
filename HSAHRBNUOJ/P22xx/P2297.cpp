#include <cstdio>
#define MAXN 2510
using namespace std;

int n, x, p[MAXN][2], dp[MAXN], ans;

inline int myabs(int a)
{
	return a < 0 ? -a : a;
}
inline int sqr(int a)
{
	return a * a;
}
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
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			read(x);
			p[x][0] = i;
			p[x][1] = j;
		}
	for (int i = 1; i <= n * n; i++)
		for (int j = 1; j < i; j++)
			dp[i] = mymax(dp[i], dp[j] + sqr(myabs(p[i][0] - p[j][0]) + myabs(p[i][1] - p[j][1])));
	printf("%d\n", dp[n * n]);
	return 0;
}