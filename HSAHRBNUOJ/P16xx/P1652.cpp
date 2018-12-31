#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 110
#define MAXM 25
#define MAXE 810
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

link e[MAXE];
int edge_num[MAXM], cnt;
int n, m, k, E, u, v, w, d;
int dis[MAXM];
bool vis[MAXM], ban[MAXN][MAXM], nopass[MAXM];
int cost[MAXN][MAXN], dp[MAXN];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, w, edge_num[v]
	};
	edge_num[v] = cnt++;
}

int SPFA(int a, int b)
{
	memset(dis, 0x7f, sizeof dis);
	memset(vis, false, sizeof vis);
	memset(nopass, false, sizeof nopass);
	dis[1] = 0;
	vis[1] = true;
	q.push(1);
	for (int i = a; i <= b; i++)
		for (int j = 1; j <= m; j++)
			nopass[j] |= ban[i][j];
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > dis[u] + e[i].val && !nopass[e[i].to])
			{
				dis[e[i].to] = dis[u] + e[i].val;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	return dis[m];
}

inline int DP()
{
	memset(dp, 0x7f, sizeof dp);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			if (cost[j + 1][i] != 0x7f7f7f7f)
				dp[i] = mymin(dp[i], dp[j] + cost[j + 1][i] * (i - j) + k);
	return dp[n] - k;
}

int main()
{
	memset(edge_num, -1, sizeof edge_num);
	scanf("%d %d %d %d", &n, &m, &k, &E);
	for (int i = 1; i <= E; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
	scanf("%d", &d);
	for (int i = 1; i <= d; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		for (int j = v; j <= w; j++) ban[j][u] = true;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cost[i][j] = SPFA(i, j);
	printf("%d\n", DP());
	return 0;
}
