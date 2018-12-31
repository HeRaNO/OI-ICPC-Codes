#include <cstdio>
#include <climits>
#define MAXN 310
using namespace std;

int n, a;
int w[MAXN];
int dp[MAXN][MAXN], p[MAXN][MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		w[i] = w[i - 1] + a;
		p[i][i] = i;
	}
	for (int l = 1; l <= n; l++)
		for (int s = 1; s <= n - l; s++)
		{
			int j = s + l, k, res = INT_MAX;
			for (int t = p[s][j - 1]; t <= p[s + 1][j]; t++)
				if (dp[s][t] + dp[t + 1][j] + w[j] - w[s - 1] < res)
				{
					res = dp[s][t] + dp[t + 1][j] + w[j] - w[s - 1];
					k = t;
				}
			dp[s][j] = res;
			p[s][j] = k;
		}
	printf("%d\n", dp[1][n]);
	return 0;
}
