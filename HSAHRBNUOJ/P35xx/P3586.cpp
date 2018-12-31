#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 110
#define MOD 1000000009LL
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXN * MAXN * MAXN];
int edge_num[MAXN * MAXN], cnt;
int n, t, T;
int a[MAXN][MAXN], mid[MAXN];
int d[MAXN * MAXN], dis[MAXN * MAXN];
long long dp[MAXN * MAXN];
bool vis[MAXN * MAXN];
queue <int> q;

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, edge_num[v]
	};
	edge_num[v] = cnt++;
}

inline void SPFA()
{
	memset(dis, 0x7f, sizeof dis);
	memset(vis, false, sizeof vis);
	q.push(1);
	dis[1] = d[1];
	vis[1] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > dis[u] + d[e[i].to])
			{
				dis[e[i].to] = dis[u] + d[e[i].to];
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	return ;
}

void dfs(int x)
{
	if (vis[x]) return ;
	vis[x] = true;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (dis[e[i].to] + d[x] == dis[x]) dfs(e[i].to);
}

void DP(int x)
{
	if (x == T)
	{
		dp[x] = 1LL;
		return ;
	}
	if (dp[x] != -1) return ;
	dp[x] = 0;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (vis[e[i].to] && dis[e[i].to] == dis[x] + d[e[i].to])
		{
			DP(e[i].to);
			dp[x] = (dp[x] + dp[e[i].to]) % MOD;
		}
	return ;
}

int main()
{
	while (~scanf("%d", &n) && n)
	{
		memset(edge_num, -1, sizeof edge_num);
		t = 1;
		cnt = 0;
		T = (n - 1) * n + 2;
		for (int i = n; i; i--) mid[i] = t++;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);
		for (int i = 1; i <= n; i++)
		{
			int j;
			for (j = 1; j <= n - i; j++)
			{
				a[i][j] += a[mid[j]][j + mid[j] - i];
				d[(i - 1)*n + j] = a[i][j];
			}
			d[(i - 1)*n + j] = a[i][j];
		}
		for (int i = 1; i < n; i++)
			for (int j = 1; j <= n - i; j++)
			{
				add((i - 1)*n + j, (i - 1)*n + j + 1);
				add((i - 1)*n + j, i * n + j);
			}
		for (int i = 1; i < n; i++) add((i - 1)*n + mid[i], i * n + mid[i + 1]);
		for (int i = 1; i <= n; i++) add((i - 1)*n + mid[i], T);
		SPFA();
		memset(vis, false, sizeof vis);
		dfs(T);
		memset(dp, -1, sizeof dp);
		DP(1);
		printf("%lld\n", dp[1]);
	}
	return 0;
}
