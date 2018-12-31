#include <queue>
#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#define MAXN 15000
#define COW 510
using namespace std;

bool vis[MAXN];
int head[MAXN], nex[MAXN], to[MAXN], cnt;
int wei[MAXN];
int farm[COW];
int dis[MAXN];
int n, p, c;
int u, v, w;
int flag;
int i, j;
int ans = INT_MAX;
queue <int> q;

void add(int u, int v, int w)
{
	nex[cnt] = head[u];
	to[cnt] = v;
	wei[cnt] = w;
	head[u] = cnt++;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int spfa(int src)
{
	int tot = 0;
	memset(vis, false, sizeof(vis));
	fill(dis, dis + MAXN, INT_MAX);
	q.push(src);
	vis[src] = true;
	dis[src] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i != -1; i = nex[i])
		{
			int v = to[i];
			if (v == 0) continue;
			if (dis[v] > dis[u] + wei[i])
			{
				dis[v] = dis[u] + wei[i];
				if (!vis[v])
				{
					q.push(v);
					vis[v] = true;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) tot += dis[farm[i]];
	return tot;
}

int main()
{
	memset(head, -1, sizeof(head));
	scanf("%d %d %d", &n, &p, &c);
	for (i = 1; i <= n; i++)
		scanf("%d", &farm[i]);
	for (i = 1; i <= c; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	for (i = 1; i <= p; i++) ans = mymin(ans, spfa(i));
	printf("%d\n", ans);
	return 0;
}
