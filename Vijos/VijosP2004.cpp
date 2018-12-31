#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 300000
using namespace std;

struct link
{
	int x, y;
};

link e[MAXN << 1], f[MAXN << 1], g[MAXN << 1], h[MAXN << 1];
int ce[MAXN << 1], cf[MAXN << 1], cg[MAXN << 1], ch[MAXN << 1];
int cec, cfc, cgc, chc;
int n, m, k, u, v, x, len, lft;
int a[MAXN], appear[MAXN], up[MAXN << 1], down[MAXN << 1], ans[MAXN];
int _2pow[20];
int dep[MAXN], LCAFather[MAXN][20];

inline void add(link *e, int *edge_num, int &cnt, int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
}

inline int Pre_Work()
{
	int kk = 0;
	_2pow[0] = 1;
	for (; _2pow[kk] <= n; kk++) _2pow[kk + 1] = _2pow[kk] << 1;
	return kk;
}

inline void dfs(int x, int father, int deep)
{
	LCAFather[x][0] = father;
	dep[x] = deep;
	for (int i = ce[x]; ~i; i = e[i].y)
		if (e[i].x != father) dfs(e[i].x, x, deep + 1);
	return ;
}

inline void LCA()
{
	for (int j = 1; j <= k; j++)
		for (int i = 1; i <= n; i++)
			LCAFather[i][j] = LCAFather[LCAFather[i][j - 1]][j - 1];
	return ;
}

inline int LCA(int u, int v)
{
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = k; ~i; i--)
		if (_2pow[i] <= dep[v] - dep[u]) v = LCAFather[v][i];
	if (u == v) return u;
	for (int i = k; ~i; i--)
		if (LCAFather[u][i] != LCAFather[v][i])
		{
			u = LCAFather[u][i];
			v = LCAFather[v][i];
		}
	return (u == v) ? u : LCAFather[v][0];
}

inline void GatherAns(int x, int father)
{
	int u = down[dep[x] + a[x]], v = up[dep[x] - a[x] + MAXN];
	down[dep[x]] += appear[x];
	for (int i = cf[x]; ~i; i = f[i].y) up[f[i].x + MAXN]++;
	for (int i = ce[x]; ~i; i = e[i].y) if (e[i].x != father) GatherAns(e[i].x, x);
	ans[x] = down[dep[x] + a[x]] + up[dep[x] - a[x] + MAXN] - u - v;
	for (int i = cg[x]; ~i; i = g[i].y)
	{
		down[g[i].x]--;
		if (g[i].x == dep[x] + a[x]) ans[x]--;
	}
	for (int i = ch[x]; ~i; i = h[i].y) up[h[i].x + MAXN]--;
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
	memset(ce, -1, sizeof ce);
	memset(cf, -1, sizeof cf);
	memset(cg, -1, sizeof cg);
	memset(ch, -1, sizeof ch);
	read(n);
	read(m);
	k = Pre_Work();
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		add(e, ce, cec, u, v);
		add(e, ce, cec, v, u);
	}
	for (int i = 1; i <= n; i++) read(a[i]);
	dfs(1, 0, 1);
	LCA();
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		x = LCA(u, v);
		len = dep[u] + dep[v] - (dep[x] << 1);
		appear[u]++;
		lft = dep[v] - len;
		add(f, cf, cfc, v, lft);
		add(g, cg, cgc, x, dep[u]);
		add(h, ch, chc, x, lft);
	}
	GatherAns(1, 0);
	printf("%d", ans[1]);
	for (int i = 2; i <= n; i++) printf(" %d", ans[i]);
	puts("");
	return 0;
}
