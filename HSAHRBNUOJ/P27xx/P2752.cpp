#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 5010
#define MAXM 50010
using namespace std;

struct link
{
	int to, nxt;
};

link e[MAXM << 1];
int edge_num[MAXN], cnt;
int n, m, T, u, v, t, scc_cnt, maxx, k;
int dfn[MAXN], low[MAXN], sta[MAXN], top;
int belong[MAXN], rnk[MAXN], ccnt[MAXN], ans[MAXN];
bool vis[MAXN];

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
		scc_cnt++;
		do
		{
			t = sta[top--];
			vis[t] = true;
			belong[t] = scc_cnt;
		}
		while (t != x);
	}
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
	freopen("classroom10.in", "r", stdin);
	freopen("classroom.out", "w", stdout);
	memset(edge_num, -1, sizeof edge_num);
	read(n);
	read(m);
	rnk[0] = ~(1 << 31);
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		read(t);
		t--;
		add(u, v);
		if (t) add(v, u);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) Tarjan(i);
	for (int i = 1; i <= n; i++)
	{
		ccnt[belong[i]]++;
		if (!rnk[belong[i]]) rnk[belong[i]] = i;
	}
	for (int i = 1; i <= scc_cnt; i++)
		if (maxx < ccnt[i] || (maxx == ccnt[i] && rnk[i] < rnk[k]))
			maxx = ccnt[k = i];
	printf("%d\n", maxx);
	for (int i = 1; i <= n; i++) if (belong[i] == k) ans[++ans[0]] = i;
	for (int i = 1; i < ans[0]; i++) printf("%d ", ans[i]);
	printf("%d\n", ans[ans[0]]);
	return 0;
}
