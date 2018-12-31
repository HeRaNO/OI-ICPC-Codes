#include <cstdio>
#include <cstring>
#define MAXN 100
#define MAXV 250000
using namespace std;

int n[7], T, V, m, v[MAXN], w[MAXN], dp[MAXV];

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
	read(T);
	while (T--)
	{
		m = 0;
		V = 0;
		memset(dp, -1, sizeof dp);
		dp[0] = 0;
		for (int i = 1; i <= 6; i++) read(n[i]), V += n[i] * i;
		if (V & 1)
		{
			puts("NO");
			continue;
		}
		V >>= 1;
		for (int i = 1, j, sum; i <= 6; i++)
		{
			for (j = 1, sum = 1; sum <= n[i]; j <<= 1, sum += j) v[++m] = i * j, w[m] = j;
			if (sum > n[i])
			{
				sum = (sum + 1) >> 1;
				--sum;
				if (n[i] != sum)
				{
					v[++m] = i * (n[i] - sum);
					w[m] = n[i] - sum;
				}
			}
		}
		for (int i = 1; i <= m; i++)
			for (int j = V; j >= v[i]; j--)
				if (~dp[j - v[i]]) dp[j] = mymax(dp[j], dp[j - v[i]] + w[i]);
		if (~dp[V]) puts("YES");
		else puts("NO");
	}
	return 0;
}