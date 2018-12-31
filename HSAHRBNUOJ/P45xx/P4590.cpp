#include <cstdio>
#include <cstring>
#define MAXN 15
using namespace std;

int n, m, u, v, w, g[MAXN][MAXN];
int dp[1 << MAXN], dep[MAXN], ans = ~(1 << 31);

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void dfs(int sta)
{
	for (int i = 1; i <= n; i++)
		if (sta & (1 << (i - 1)))
		{
			for (int j = 1; j <= n; j++)
				if (!(sta & (1 << (j - 1))))
				{
					if (g[i][j] == 0x7f7f7f7f) continue;
					if (dp[sta | (1 << (j - 1))] > dp[sta] + dep[i]*g[i][j])
					{
						int t = dep[j];
						dep[j] = dep[i] + 1;
						dp[sta | (1 << (j - 1))] = dp[sta] + dep[i] * g[i][j];
						dfs(sta | (1 << (j - 1)));
						dep[j] = t;
					}
				}
		}
	return ;
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
	//freopen("treasure.in","r",stdin);freopen("treasure.out","w",stdout);
	read(n);
	read(m);
	memset(g, 0x7f, sizeof g);
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		read(w);
		g[u][v] = g[v][u] = mymin(g[u][v], w);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(dp, 0x7f, sizeof dp);
		dep[i] = 1;
		dp[1 << (i - 1)] = 0;
		dfs(1 << (i - 1));
		ans = mymin(ans, dp[(1 << n) - 1]);
	}
	printf("%d\n", ans);
	return 0;
}