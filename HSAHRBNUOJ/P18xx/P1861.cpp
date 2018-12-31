#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXM 100010
#define MAXN 100010
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

link e[MAXM];
int edge_num[MAXN];
int n, m, cnt;
int u, v, w;
int p, ans = INT_MAX;
bool vis[MAXN];
int dis[MAXN];
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
	memset(vis, false, sizeof(vis));
	memset(dis, 0x7f, sizeof(dis));
	vis[n] = true;
	dis[n] = 0;
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
	return ;
}

void dfs(int node, int len)
{
	if (len + dis[node] >= ans) return ;
	if (len + dis[node] > dis[1]) ans = len + dis[node];
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		dfs(e[i].to, len + e[i].val);
}

int main()
{
	//freopen("gfdota.in","r",stdin);freopen("gfdota.out","w",stdout);
	memset(edge_num, -1, sizeof(edge_num));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
	scanf("%d", &p);
	spfa();
	memset(vis, false, sizeof(vis));
	if (!p)
	{
		printf("%d\n", dis[1]);
		return 0;
	}
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}
