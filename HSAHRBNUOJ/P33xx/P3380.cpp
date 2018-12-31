#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 60
#define MAXM 50000
#define MAXP 3000
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

link e[MAXM];
int n, m, T, iceT, ans = INT_MAX;
int edge_num[MAXP], cnt;
int con[MAXN][MAXN], ice[MAXN][MAXN];
char g[MAXN][MAXN];
int dis[MAXP][MAXP], dp[1 << 16][20];
bool vis[MAXP];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
}

void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, 1, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, 1, edge_num[v]
	};
	edge_num[v] = cnt++;
}

void dfs(int x, int y)
{
	con[x][y] = T;
	if (x + 1 <= n && g[x + 1][y] == 'X' && !con[x + 1][y]) dfs(x + 1, y);
	if (x - 1 >= 1 && g[x - 1][y] == 'X' && !con[x - 1][y]) dfs(x - 1, y);
	if (y + 1 <= m && g[x][y + 1] == 'X' && !con[x][y + 1]) dfs(x, y + 1);
	if (y - 1 >= 1 && g[x][y - 1] == 'X' && !con[x][y - 1]) dfs(x, y - 1);
	return ;
}

void spfa(int src)
{
	memset(vis, false, sizeof vis);
	q.push(src);
	dis[src][src] = 0;
	vis[src] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
		{
			if (dis[src][e[i].to] > dis[src][u] + e[i].val)
			{
				dis[src][e[i].to] = dis[src][u] + e[i].val;
				if (!vis[e[i].to])
				{
					q.push(e[i].to);
					vis[e[i].to] = true;
				}
			}
		}
	}
	return ;
}

int main()
{
	memset(edge_num, -1, sizeof edge_num);
	memset(dis, 0x7f, sizeof dis);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (g[i][j] == 'X' && !con[i][j])
			{
				T++;
				dfs(i, j);
			}
	iceT = T;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (g[i][j] == 'S') ice[i][j] = ++iceT;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (g[i][j] == 'S')
			{
				if (con[i][j + 1])
				{
					add(ice[i][j], con[i][j + 1], 0);
					add(con[i][j + 1], ice[i][j], 1);
				}
				if (con[i][j - 1])
				{
					add(ice[i][j], con[i][j - 1], 0);
					add(con[i][j - 1], ice[i][j], 1);
				}
				if (con[i - 1][j])
				{
					add(ice[i][j], con[i - 1][j], 0);
					add(con[i - 1][j], ice[i][j], 1);
				}
				if (con[i + 1][j])
				{
					add(ice[i][j], con[i + 1][j], 0);
					add(con[i + 1][j], ice[i][j], 1);
				}
				if (ice[i][j + 1]) add(ice[i][j], ice[i][j + 1]);
				if (ice[i][j - 1]) add(ice[i][j], ice[i][j - 1]);
				if (ice[i - 1][j]) add(ice[i][j], ice[i - 1][j]);
				if (ice[i + 1][j]) add(ice[i][j], ice[i + 1][j]);
			}
	for (int i = 1; i <= T; i++) spfa(i);
	for (int i = 0; i < (1 << T); i++)
		for (int j = 1; j <= T; j++)
		{
			if (i == (1 << (j - 1))) dp[i][j] = 0;
			else if (i & (1 << (j - 1)))
			{
				dp[i][j] = INT_MAX;
				for (int k = 1; k <= T; k++)
					if (j != k && (i & (1 << (k - 1))))
						dp[i][j] = mymin(dp[i][j], dp[i ^ (1 << j - 1)][k] + dis[k][j]);
			}
		}
	for (int i = 1; i <= T; i++) ans = mymin(ans, dp[(1 << T) - 1][i]);
	printf("%d\n", ans);
	return 0;
}
