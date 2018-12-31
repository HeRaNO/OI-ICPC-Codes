#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 110
#define MAXM 10000
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXM];
int n, T, u, v, ans;
int edge_num[MAXN], cnt;
int dfn[MAXN], low[MAXN];
bool cut_vertex[MAXN], vis[MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, edge_num[v]
	};
	edge_num[v] = cnt++;
}

inline void Tarjan(int x, int father)
{
	dfn[x] = low[x] = ++T;
	int c = 0;
	vis[x] = true;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
	{
		if (vis[e[i].to]) low[x] = mymin(low[x], dfn[e[i].to]);
		else
		{
			Tarjan(e[i].to, father);
			low[x] = mymin(low[x], low[e[i].to]);
			c++;
			if (x != 1 && dfn[x] <= low[e[i].to]) cut_vertex[x] = true;
		}
	}
	if (x == 1 && c > 1) cut_vertex[x] = true;
	return ;
}

inline void clean()
{
	memset(edge_num, -1, sizeof edge_num);
	cnt = 0;
	ans = 0;
	T = 0;
	memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low);
	memset(cut_vertex, 0, sizeof cut_vertex);
	memset(vis, 0, sizeof vis);
	return ;
}

int main()
{
	while (~scanf("%d", &n) && n)
	{
		clean();
		while (~scanf("%d", &u) && u)
		{
			while (getchar() != '\n')
			{
				scanf("%d", &v);
				add(u, v);
			}
		}
		for (int i = 1; i <= n; i++) if (!dfn[i]) Tarjan(i, 0);
		for (int i = 1; i <= n; i++) if (cut_vertex[i]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
