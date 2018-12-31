#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 100010
#define MAXM 300010
using namespace std;

int n, m;
int u, v;
int i, ans;
int d[MAXN];
int dist[MAXN];
int et, head[MAXM], to[MAXM], c[MAXM], nex[MAXM];
queue <int> q;

void add(int u, int v)
{
	et++;
	to[et] = v;
	nex[et] = head[u];
	head[u] = et;
}

void spfa(int src, int goal)
{
	q.push(src);
	bool vis[MAXN];
	memset(vis, false, sizeof(vis));
	vis[src] = true;
	dist[src] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();//vis[u] = false;
		for (int i = head[u]; i != -1; i = nex[i])
		{
			int v = to[i];
			if (v == 0) continue;
			if (!vis[v])
			{
				dist[v] = dist[u] + 1;
				q.push(v);
				vis[v] = true;
			}
		}
	}
}

int main()
{
	memset(head, -1, sizeof(head));
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		add(u, v);
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
		dist[i] = INT_MAX;
	}
	spfa(1, n);
	for (i = 1; i <= n; i++)
		ans += (dist[i] * d[i]);
	printf("%d\n", ans);
	return 0;
}
