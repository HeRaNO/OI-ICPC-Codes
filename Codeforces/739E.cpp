#include <bits/stdc++.h>
#define MAXN 2050
#define MAXM 100000
using namespace std;

struct link
{
	int to, rev, flow; double val;
	link(){}
	link(int _to, int _rev, int _flow, double _val):
		to(_to), rev(_rev), flow(_flow), val(_val){}
};

const double eps = 1e-7;

vector <link> g[MAXN];
int n, a, b, S, S1, S2, T, ptr[MAXN];
double dis[MAXN], p[MAXN], u[MAXN], ans;
bool vis[MAXN];
queue <int> q;

inline void add(int u, int v, double c, int f)
{
	g[u].push_back(link(v, g[v].size(), f, c));
	g[v].push_back(link(u, int(g[u].size()) - 1, 0, -c));
}

inline bool SPFA()
{
	for (int i = S; i <= T; i++) dis[i] = 1e15;
	memset(vis, false, sizeof vis);
	q.push(S); dis[S] = 0;
	while (!q.empty())
	{
		int u = q.front(); q.pop(); vis[u] = false;
		for (auto& e : g[u])
			if (e.flow && dis[e.to] - (dis[u] + e.val) > eps)
			{
				dis[e.to] = dis[u] + e.val;
				if (!vis[e.to])
				{
					vis[e.to] = true;
					q.push(e.to);
				}
			}
	}
	return dis[T] != 1e15;
}

inline int Dinic(int x, int flow)
{
	int left = flow;
	if (x == T) return flow;
	vis[x] = true;
	for (int& i = ptr[x]; i < int(g[x].size()) && left; i++)
	{
		link& e = g[x][i];
		if (fabs(dis[e.to] - (dis[x] + e.val)) < eps && e.flow && !vis[e.to])
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
	scanf("%d %d %d", &n, &a, &b);
	S = 0; S1 = n + 1; S2 = n + 2; T = n + 3;
	for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
	for (int i = 1; i <= n; i++) scanf("%lf", &u[i]);
	add(S, S1, 0, a); add(S, S2, 0, b);
	for (int i = 1; i <= n; i++)
	{
		add(i, T, 0, 1);
		add(i, T, p[i] * u[i], 1);
	}
	for (int i = 1; i <= n; i++)
	{
		add(S1, i, -p[i], 1);
		add(S2, i, -u[i], 1);
	}
	while (SPFA())
	{
		memset(ptr, 0, sizeof ptr);
		int d = Dinic(S, ~(1 << 31));
		ans += d * dis[T];
	}
	printf("%.10lf\n", -ans);
	return 0;
}
