#include <cstdio>
#include <climits>
#define MAXN 210
#define LL_MAX 92233000000000
using namespace std;

long long a[MAXN][MAXN];
long long dp[1 << 13][MAXN];
long long ans = LL_MAX, w;
int n, m, p;
int pp[13];
int u, v;

long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

int main()
{
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
		{
			if (i == j) continue;
			a[i][j] = LL_MAX;
		}
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %lld", &u, &v, &w);
		a[u][v] = a[v][u] = mymin(a[u][v], w);
	}
	scanf("%d", &p);
	for (int i = 1; i <= p; i++) scanf("%d", &pp[i]);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = mymin(a[i][j], a[i][k] + a[k][j]);
	for (int i = 1; i < (1 << p); i++)
		for (int j = 1; j <= p; j++)
		{
			if (i == (1 << (j - 1))) dp[i][j] = a[1][pp[j]];
			else if (i & (1 << (j - 1)))
			{
				dp[i][j] = LL_MAX;
				for (int k = 1; k <= p; k++)
				{
					if (j != k && (i & (1 << (k - 1))))
						dp[i][j] = mymin(dp[i][j], dp[i ^ (1 << j - 1)][k] + a[pp[k]][pp[j]]);
				}
			}
		}
	for (int i = 1; i <= p; i++)
		ans = mymin(dp[(1 << p) - 1][i] + a[pp[i]][n], ans);
	if (ans == LL_MAX) printf("-1\n");
	else printf("%lld\n", ans);
	return 0;
}
