#include <cstdio>
#define MAXN 2510
using namespace std;

int n, a;
int x[MAXN], y[MAXN], dp[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int myabs(int a)
{
	return a > 0 ? a : -a;
}
inline int sqr(int a)
{
	return a * a;
}
inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			read(a);
			x[a] = i;
			y[a] = j;
		}
	for (int i = n * n; i; i--)
		for (int j = i + 1; j <= n * n; j++)
			dp[i] = mymax(dp[i], dp[j] + sqr(myabs(x[i] - x[j]) + myabs(y[i] - y[j])));
	printf("%d\n", dp[1]);
	return 0;
}
