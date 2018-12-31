#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 500010
#define MAXM 500010
using namespace std;

struct edge
{
	int x, y;
};

struct link
{
	int to, nxt;
};

edge f[MAXM];
link e[MAXM];
int n, m, T, s, p, x, ans, top;
int edge_num[MAXN], cnt;
int a[MAXN], c[MAXN], dis[MAXN];
int dfn[MAXN], low[MAXN], belong[MAXN], sta[MAXN];
bool vis[MAXN];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
}

inline void Tarjan(int x)
{
	dfn[x] = low[x] = ++T;
	sta[++top] = x;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
	{
		if (vis[e[i].to]) continue;
		if (dfn[e[i].to]) low[x] = mymin(low[x], dfn[e[i].to]);
		else
		{
			Tarjan(e[i].to);
			low[x] = mymin(low[x], low[e[i].to]);
		}
	}
	if (dfn[x] == low[x])
	{
		int t;
		cnt++;
		do
		{
			t = sta[top--];
			vis[t] = true;
			belong[t] = cnt;
			c[cnt] += a[t];
		}
		while (t != x);
	}
	return ;
}

inline void SPFA(int S)
{
	memset(vis, false, sizeof vis);
	memset(dis, -1, sizeof dis);
	q.push(S);
	vis[S] = true;
	dis[S] = c[S];
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] < dis[u] + c[e[i].to])
			{
				dis[e[i].to] = dis[u] + c[e[i].to];
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	memset(edge_num, -1, sizeof edge_num);
	read(n);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(f[i].x);
		read(f[i].y);
		add(f[i].x, f[i].y);
	}
	for (int i = 1; i <= n; i++) read(a[i]);
	read(s);
	read(p);
	cnt = 0;
	Tarjan(s);
	memset(edge_num, -1, sizeof edge_num);
	cnt = 0;
	for (int i = 1; i <= m; i++)
		if (belong[f[i].x] != belong[f[i].y])
			add(belong[f[i].x], belong[f[i].y]);
	SPFA(belong[s]);
	for (int i = 1; i <= p; i++)
	{
		read(x);
		ans = mymax(ans, dis[belong[x]]);
	}
	printf("%d\n", ans);
	return 0;
}
