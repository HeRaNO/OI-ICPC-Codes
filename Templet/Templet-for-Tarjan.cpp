#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define MAXM 100010
using namespace std;

struct link
{
	int to, val, nxt;
};

link e[MAXM << 1];
int n, m, T, u, v, w, scc_cnt, cutedge_cnt, top;
int head[MAXN], cnt;
int dfn[MAXN], low[MAXN], belong[MAXN], sta[MAXN];
bool vis[MAXN], cut_vertex[MAXN];
pair <int, int> cut_edge[MAXM];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, head[u]
	};
	head[u] = cnt++;
	e[cnt] = (link)
	{
		u, w, head[v]
	};
	head[v] = cnt++;
}

inline void Tarjan(int x, int father)
{
	dfn[x] = low[x] = ++T;
	sta[++top] = x;
	int c = 0;
	for (int i = head[x]; ~i; i = e[i].nxt)
	{
		if (vis[e[i].to] || e[i].to == father) continue;
		if (dfn[e[i].to]) low[x] = mymin(low[x], dfn[e[i].to]);
		else
		{
			Tarjan(e[i].to, x);
			low[x] = mymin(low[x], low[e[i].to]);
			c++;
			if (x != 1 && dfn[x] <= low[e[i].to]) cut_vertex[x] = true;
			if (low[e[i].to] > dfn[x]) cut_edge[++cutedge_cnt] = make_pair(x, e[i].to);
		}
	}
	if (x == 1 && c > 1) cut_vertex[x] = true;
	if (dfn[x] == low[x])
	{
		int t;
		scc_cnt++;
		do
		{
			t = sta[top--];
			vis[t] = true;
			belong[t] = scc_cnt;
		}
		while (t != x);
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
	memset(head, -1, sizeof head);
	read(n);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		read(w);
		add(u, v, w);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) Tarjan(i, 0);
	return 0;
}
