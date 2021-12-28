#include <bits/stdc++.h>
#define MAXN 405
#define MAXM 15005
using namespace std;

struct link
{
	int to, rev, flow, val;
	link(){}
	link(int _to, int _rev, int _flow, int _val):
		to(_to), rev(_rev), flow(_flow), val(_val){}
};

vector <link> g[MAXN];
int n, m, u, v, s, t, S, T, dis[MAXN], flow, ans, ptr[MAXN];
bool vis[MAXN];
queue <int> q;

inline void add(int u, int v, int c, int f)
{
	g[u].push_back(link(v, g[v].size(), f, c));
	g[v].push_back(link(u, int(g[u].size()) - 1, 0, -c));
}

inline bool SPFA()
{
	memset(dis, 0x7f, sizeof dis);
	memset(vis, false, sizeof vis);
	q.push(S); dis[S] = 0;
	while (!q.empty())
	{
		int u = q.front(); q.pop(); vis[u] = false;
		for (auto& e : g[u])
			if (e.flow && dis[e.to] > dis[u] + e.val)
			{
				dis[e.to] = dis[u] + e.val;
				if (!vis[e.to])
				{
					vis[e.to] = true;
					q.push(e.to);
				}
			}
	}
	return dis[T] != 0x7f7f7f7f;
}

inline int Dinic(int x, int flow)
{
	int left = flow;
	if (x == T) return flow;
	vis[x] = true;
	for (int& i = ptr[x]; i < int(g[x].size()) && left && flow; i++)
	{
		link& e = g[x][i];
		if (dis[e.to] == dis[x] + e.val && e.flow && !vis[e.to])
		{
			int t = Dinic(e.to, min(e.flow, left));
			e.flow -= t; g[e.to][e.rev].flow += t; left -= t;
		}
	}
	if (!left) vis[x] = false;
	return flow - left;
}

int main()
{
	scanf("%d %d",&n,&m); S = 1; T = n;
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d %d %d", &u, &v, &s, &t);
		add(u, v, t, s);
	}
	while (SPFA())
	{
		memset(ptr, 0, sizeof ptr);
		int d = Dinic(S, ~(1 << 31));
		flow += d;
		ans += d * dis[T];
	}
	printf("%d %d\n", flow, ans);
	return 0;
}
