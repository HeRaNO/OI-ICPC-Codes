#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define MAXM 100010
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

link e[MAXM << 1];
int edge_num[MAXN], cnt;
int n, m, k, T, u, v, w;
int LCAFather[MAXN][20], LCADis[MAXN][20];
int _2pow[20], lg2[MAXN], dep[MAXN];

inline void add(int u, int v, int w)
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

inline int pre_work()
{
	int kk;
	_2pow[0] = 1;
	lg2[1] = 0;
	for (kk = 0; _2pow[kk] <= n; kk++) _2pow[kk + 1] = _2pow[kk] << 1;
	for (int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
	return kk;
}

inline void dfs(int node, int father, int val, int deep)
{
	LCAFather[node][0] = father;
	LCADis[node][0] = val;
	dep[node] = deep;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != father) dfs(e[i].to, node, e[i].val, deep + 1);
	return ;
}

inline void LCA()
{
	for (int j = 1; j <= k; j++)
		for (int i = 1; i <= n; i++)
		{
			LCAFather[i][j] = LCAFather[LCAFather[i][j - 1]][j - 1];
			LCADis[i][j] = LCADis[i][j - 1] + LCADis[LCAFather[i][j - 1]][j - 1];
		}
	return ;
}

inline int GetDis(int u, int v)
{
	int res = 0;
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = k; ~i; i--)
		if (_2pow[i] <= dep[v] - dep[u])
		{
			res += LCADis[v][i];
			v = LCAFather[v][i];
		}
	for (int i = k; ~i; i--)
		if (LCAFather[u][i] != LCAFather[v][i])
		{
			res += LCADis[u][i] + LCADis[v][i];
			u = LCAFather[u][i];
			v = LCAFather[v][i];
		}
	if (u != v) res += LCADis[u][0] + LCADis[v][0];
	return res;
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	memset(edge_num, -1, sizeof edge_num);
	read(n);
	read(m);
	k = pre_work();
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		read(w);
		add(u, v, w);
	}
	for (int i = 1; i <= n; i++) if (!LCAFather[i][0]) dfs(i, 0, 0, 1);
	LCA();
	read(T);
	while (T--)
	{
		read(u);
		read(v);
		printf("%d\n", GetDis(u, v));
	}
	return 0;
}