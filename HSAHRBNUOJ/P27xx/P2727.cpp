#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 210
#define MAXM 400010
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

link e[MAXM];
int n, m, cnt;
int u, v, w;
int edge_num[MAXN];
int dis[MAXN], update[MAXN], ans1[MAXN];
bool vis[MAXN], ans[MAXN];
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

void spfa(int src)
{
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	dis[src] = 0;
	vis[src] = true;
	q.push(src);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
		{
			if (dis[e[i].to] > dis[u] + e[i].val)
			{
				update[e[i].to] = u;
				dis[e[i].to] = dis[u] + e[i].val;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
			else if (dis[e[i].to] == dis[u] + e[i].val) update[e[i].to] = 0;
		}
	}
}

int main()
{
	memset(edge_num, -1, sizeof(edge_num));
	memset(ans, false, sizeof(ans));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(update, 0, sizeof(update));
		spfa(i);
		for (int j = 1; j <= n; j++)
			if (update[j] && update[j] != j && update[j] != i) ans[update[j]] = true;
	}
	for (int i = 1; i <= n; i++) if (ans[i]) ans1[++ans1[0]] = i;
	for (int i = 1; i < ans1[0]; i++) printf("%d ", ans1[i]);
	if (!ans1[0]) printf("No important cities.\n");
	else printf("%d\n", ans1[ans1[0]]);
	return 0;
}
