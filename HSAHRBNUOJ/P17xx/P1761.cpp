#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#define MAXN 10010
#define MAXM 1000010
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

struct edge
{
	int u;
	int v;
	int w;
};

link e[MAXM];
edge in[MAXM];
int edge_num[MAXN], cnt;
//Graph

int n, m, t;
int u, v, w;
int k;
int father[MAXM];
int _2pow[20];
//In&&Prework&&Kruskal

int LCAFather[MAXN][20], LCAVal[MAXN][20];
int dep[MAXN];
//LCA&&dfs

void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, w, edge_num[v]
	};
	edge_num[v] = cnt++;
}

int getfather(int x)
{
	return father[x] == x ? x : father[x] = getfather(father[x]);
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void dfs(int node, int pre_father, int val, int deep)
{
	LCAFather[node][0] = pre_father;
	LCAVal[node][0] = val;
	dep[node] = deep;
	for (int i = edge_num[node]; i; i = e[i].nxt)
		if (e[i].to != pre_father)
			dfs(e[i].to, node, e[i].val, deep + 1);
}

void LCA()
{
	for (int j = 1; j <= k; j++)
		for (int i = 1; i <= n; i++)
		{
			LCAFather[i][j] = LCAFather[LCAFather[i][j - 1]][j - 1];
			LCAVal[i][j] = mymin(LCAVal[i][j - 1], LCAVal[LCAFather[i][j - 1]][j - 1]);
		}
	return ;
}

int query(int u, int v)
{
	int ans = INT_MAX;
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = k; ~i; i--)
	{
		if (_2pow[i] <= dep[v] - dep[u])
		{
			ans = mymin(ans, LCAVal[v][i]);
			v = LCAFather[v][i];
		}
	}
	for (int i = k; ~i; i--)
	{
		if (LCAFather[v][i] != LCAFather[u][i])
		{
			ans = mymin(ans, mymin(LCAVal[u][i], LCAVal[v][i]));
			u = LCAFather[u][i];
			v = LCAFather[v][i];
		}
	}
	if (u != v) ans = mymin(ans, mymin(LCAVal[u][0], LCAVal[v][0]));
	return ans;
}

bool cmp(edge a, edge b)
{
	return a.w > b.w;
}

int prework()
{
	_2pow[0] = 1;
	int kk;
	for (int i = 1; i <= n; i++)
		father[i] = i;
	for (kk = 0; _2pow[kk] <= n; kk++) _2pow[kk + 1] = _2pow[kk] << 1;
	return kk;
}

void kruskal()
{
	sort(in + 1, in + m + 1, cmp);
	for (int i = 1; i <= m; i++)
	{
		int u = getfather(in[i].u);
		int v = getfather(in[i].v);
		if (u != v)
		{
			father[v] = u;
			add(u, v, in[i].w);
		}
	}
	return ;
}

int main()
{
	scanf("%d %d", &n, &m);
	k = prework();
	for (int i = 1; i <= m; i++)
		scanf("%d %d %d", &in[i].u, &in[i].v, &in[i].w);
	kruskal();
	for (int i = 1; i <= n; i++)
		if (!LCAFather[i][0]) dfs(i, 0, INT_MAX, 1);
	LCA();
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &u, &v);
		if (getfather(u) != getfather(v)) printf("-1\n");
		else printf("%d\n", query(u, v));
	}
	return 0;
}