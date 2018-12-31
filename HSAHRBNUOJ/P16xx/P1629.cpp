#include <cstdio>
#include <cstring>
#define MAXN 190
#define INT_MAX 2147483647
using namespace std;

const int d[4][2] =
{
	{1, 0}, {-1, 0},
	{0, 1}, {0, -1}
};
int n, m;
int ans[MAXN][MAXN];
char g[MAXN][MAXN];
bool vis[MAXN][MAXN];

inline int myabs(int a)
{
	return a > 0 ? a : -a;
}
inline int getdis(int x, int y, int x0, int y0)
{
	return myabs(x - x0) + myabs(y - y0);
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

void dfs(int x, int y, int px, int py)
{
	vis[x][y] = true;
	if (x < 1 || x > n || y < 1 || y > m) return ;
	ans[x][y] = mymin(ans[x][y], getdis(x, y, px, py));
	for (int i = 0; i < 4; i++)
	{
		int x0 = x + d[i][0], y0 = y + d[i][1];
		if (g[x0][y0] == '1') continue;
		if (vis[x0][y0]) continue;
		dfs(x0, y0, px, py);
	}
}

int main()
{
	memset(ans, 0x7f, sizeof ans);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (g[i][j] == '1')
			{
				memset(vis, false, sizeof vis);
				dfs(i, j, i, j);
			}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++) printf("%d ", ans[i][j]);
		printf("%d\n", ans[i][m]);
	}
	return 0;
}
/*
    3 4
    0001
    0011
    0110
*/
