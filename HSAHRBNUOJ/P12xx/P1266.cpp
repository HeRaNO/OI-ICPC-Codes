#include <cstdio>
#define MAXM 100000
#define MAXV 510
using namespace std;

int n, V, m, v[MAXM], w[MAXM], x, iv, c, ans, dp[MAXV];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
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
	read(V);
	for (int i = 1, j, sum; i <= n; i++)
	{
		read(x);
		read(iv);
		read(c);
		for (j = 1, sum = 1; sum <= x; j <<= 1, sum += j) v[++m] = iv * j, w[m] = c * j;
		if (sum > x)
		{
			sum = (sum + 1) >> 1;
			--sum;
			if (x != sum)
			{
				v[++m] = iv * (x - sum);
				w[m] = c * (x - sum);
			}
		}
	}
	for (int i = 1; i <= m; i++)
		for (int j = V; j >= v[i]; j--)
			dp[j] = mymax(dp[j], dp[j - v[i]] + w[i]);
	printf("%d\n", dp[V]);
	return 0;
}