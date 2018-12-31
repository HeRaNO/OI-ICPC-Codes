#include <cstdio>
#include <cstring>
#define MAXN 510
using namespace std;

int n, c, u, v, ans;
int g[MAXN][MAXN];
int result[MAXN];
bool vis[MAXN];

bool Hungary(int x)
{
	for (int i = 1; i <= g[x][0]; i++)
	{
		int y = g[x][i];
		if (vis[y]) continue;
		vis[y] = true;
		if (!result[y] || Hungary(result[y]))
		{
			result[y] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	while (~scanf("%d", &n))
	{
		memset(g, 0, sizeof g);
		memset(result, 0, sizeof result);
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d: (%d)", &u, &c);
			for (int j = 1; j <= c; j++)
			{
				scanf("%d", &v);
				g[u][++g[u][0]] = v;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (!g[i][0]) continue;
			memset(vis, false, sizeof vis);
			if (Hungary(i)) ans++;
		}
		printf("%d\n", n - (ans >> 1));
	}
	return 0;
}
