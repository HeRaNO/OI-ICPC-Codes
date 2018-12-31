#include <cstdio>
#include <climits>
#define MAXN 15
using namespace std;

int a[MAXN][MAXN];
int dp[1 << MAXN][MAXN];
int n;
int ans;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	while (~scanf("%d", &n) && n)
	{
		ans = INT_MAX;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				scanf("%d", &a[i][j]);
		for (int k = 0; k <= n; k++)
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= n; j++)
					a[i][j] = mymin(a[i][j], a[i][k] + a[k][j]);
		for (int i = 0; i < (1 << n); i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == (1 << (j - 1))) dp[i][j] = a[0][j];
				else if (i & (1 << (j - 1)))
				{
					dp[i][j] = INT_MAX;
					for (int k = 1; k <= n; k++)
					{
						if (j != k && (i & (1 << (k - 1))))
							dp[i][j] = mymin(dp[i][j], dp[i ^ (1 << j - 1)][k] + a[k][j]);
					}
				}
			}
		for (int i = 1; i <= n; i++)
			ans = mymin(dp[(1 << n) - 1][i] + a[i][0], ans);
		printf("%d\n", ans);
	}
	return 0;
}
