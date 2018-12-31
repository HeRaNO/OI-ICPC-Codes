#include <cstdio>
#include <cstring>
#define MAXN 1010
using namespace std;

int n, x, y, s, Z, mx;
int c[MAXN], dp[MAXN * 10];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
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
	memset(dp, 0x7f, sizeof dp);
	mx = dp[0];
	read(n);
	Z = 5 * n;
	for (int i = 1; i <= n; i++)
	{
		read(x);
		read(y);
		c[i] = x - y;
		s += c[i];
	}
	dp[s + Z] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (c[i] < 0)
		{
			for (int j = Z; j >= -Z; j--)
				if (j + 2 * c[i] + Z >= 0) dp[j + Z] = mymin(dp[j + Z], dp[j + 2 * c[i] + Z] + 1);
				else break;
		}
		else if (c[i] > 0)
		{
			for (int j = -Z; j <= Z; j++)
				if (j + 2 * c[i] + Z >= 0) dp[j + Z] = mymin(dp[j + Z], dp[j + 2 * c[i] + Z] + 1);
				else break;
		}
	}
	for (int i = Z, j = i; j; i++, j--)
		if (dp[i] != mx || dp[j] != mx)
		{
			printf("%d\n", mymin(dp[i], dp[j]));
			return 0;
		}
	return 0;
}
