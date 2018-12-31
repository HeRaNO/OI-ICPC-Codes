#include <queue>
#include <cstdio>
#include <climits>
#include <cstring>
#define MAXN 50005
#define MAXM 200005
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

link e[MAXM];
int edge_num[MAXN];
bool vis[MAXN];
int dis[MAXN];
int n, m, cnt;
int u, v, w;
int ans = INT_MAX;
queue <int> q;

void add(int u, int v, int w)
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

void spfa()
{
	for (int i = 0; i <= n; i++) dis[i] = INT_MAX;
	memset(vis, false, sizeof(vis));
	dis[n] = 0;
	vis[n] = true;
	q.push(n);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
		{
			if (dis[e[i].to] > dis[u] + e[i].val)
			{
				dis[e[i].to] = dis[u] + e[i].val;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
		}
	}
}

void dfs(int node, int len)
{
	if (len + dis[node] >= ans) return ;
	if (len + dis[node] > dis[1])
		ans = len + dis[node];
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		dfs(e[i].to, len + e[i].val);
}

int main()
{
	while (~scanf("%d %d", &n, &m))
	{
		memset(edge_num, -1, sizeof(edge_num));
		cnt = 0;
		ans = INT_MAX;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &u, &v, &w);
			add(u, v, w);
		}
		spfa();
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
