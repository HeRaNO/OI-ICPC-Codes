#include <cstdio>
#include <queue>
#include <climits>
#include <cstring>
#define MAXN 100010
#define MAXM 500010
using namespace std;

int head[MAXN], nex[MAXM], to[MAXM], cnt = 0;
int n, m;
int i, u, v, flag;
int fee[MAXN];
bool vis[MAXN];
int dist[MAXN][3];
queue<int> q;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int spfa(int src, int goal)
{
	q.push(src);
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++)
		dist[i][0] = dist[i][1] = dist[i][2] = -INT_MAX;
	vis[src] = true;
	dist[src][0] = 0;
	dist[src][1] = -fee[src];
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i ; i = nex[i])
		{
			int v = to[i];
			if (dist[v][0] < dist[u][0])
			{
				dist[v][0] = dist[u][0];
				if (!vis[v])
				{
					vis[v] = true;
					q.push(v);
				}
			}
			if (dist[v][1] < dist[u][0] - fee[v])
			{
				dist[v][1] = dist[u][0] - fee[v];
				if (!vis[v])
				{
					vis[v] = true;
					q.push(v);
				}
			}
			if (dist[v][1] < dist[u][1])
			{
				dist[v][1] = dist[u][1];
				if (!vis[v])
				{
					vis[v] = true;
					q.push(v);
				}
			}
			if (dist[v][2] < dist[u][1] + fee[v])
			{
				dist[v][2] = dist[u][1] + fee[v];
				if (!vis[v])
				{
					vis[v] = true;
					q.push(v);
				}
			}
			if (dist[v][2] < dist[u][2])
			{
				dist[v][2] = dist[u][2];
				if (!vis[v])
				{
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	return mymax(mymax(dist[n][0], dist[n][1]), dist[n][2]);
}

void add(int u, int v)
{
	to[++cnt] = v;
	nex[cnt] = head[u];
	head[u] = cnt;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", &fee[i]);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &u, &v, &flag);
		if (flag == 1)
			add(u, v);
		else
		{
			add(u, v);
			add(v, u);
		}
	}
	printf("%d\n", spfa(1, n));
	return 0;
}
