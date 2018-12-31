#include <cstdio>
#include <cstring>
#define MAXN 50010
#define MAXM 100010
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

link e[MAXM];
int edge_num[MAXN], cnt;
int n, m, T, top, scc_cnt, u, v, w;
int dfn[MAXN], low[MAXN], belong[MAXN], sta[MAXN];
bool vis[MAXN];
long long ans, minn[MAXN];

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

void Tarjan(int x)
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
		scc_cnt++;
		do
		{
			t = sta[top--];
			belong[t] = scc_cnt;
			vis[t] = true;
		}
		while (t != x);
	}
}

int main()
{
	while (~scanf("%d %d", &n, &m) && n && m)
	{
		memset(edge_num, -1, sizeof edge_num);
		memset(dfn, 0, sizeof dfn);
		memset(low, 0, sizeof low);
		memset(belong, 0, sizeof belong);
		memset(vis, false, sizeof vis);
		memset(minn, 127, sizeof minn);
		cnt = 0;
		ans = 0LL;
		top = 0;
		scc_cnt = 0;
		T = 0;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &u, &v, &w);
			add(u, v, w);
		}
		for (int i = 0; i < n; i++) if (!vis[i]) Tarjan(i);
		for (int i = 0; i < n; i++)
			for (int j = edge_num[i]; ~j; j = e[j].nxt)
				if (belong[i] != belong[e[j].to])
					minn[belong[e[j].to]] = mymin(minn[belong[e[j].to]], (long long)e[j].val);
		for (int i = 1; i <= scc_cnt; i++) if (i != belong[0]) ans += minn[i];
		printf("%lld\n", ans);
	}
	return 0;
}
