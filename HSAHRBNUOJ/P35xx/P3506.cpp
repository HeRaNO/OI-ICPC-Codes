#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXN * 2];
int n, T, R, u, v, k, dis, x, y;
int edge_num[MAXN], cnt;
int dep[MAXN], LCAFather[MAXN][20], son[MAXN];
int _2pow[20];

inline int pre_work()
{
	int kk;
	_2pow[0] = 1;
	for (kk = 0; _2pow[kk] <= n; kk++) _2pow[kk + 1] = _2pow[kk] << 1;
	return kk;
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

void dfs(int node, int father, int deep)
{
	son[node] = 1;
	dep[node] = deep;
	LCAFather[node][0] = father;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != father)
		{
			dfs(e[i].to, node, deep + 1);
			son[node] += son[e[i].to];
		}
	return ;
}

void LCA()
{
	for (int j = 1; j <= k; j++)
		for (int i = 1; i <= n; i++)
			LCAFather[i][j] = LCAFather[LCAFather[i][j - 1]][j - 1];
	return ;
}

int LCA(int u, int v)
{
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = k; ~i; i--)
		if (_2pow[i] <= dep[v] - dep[u]) v = LCAFather[v][i];
	if (u == v) return u;
	for (int i = k; ~i; i--)
		if (LCAFather[u][i] != LCAFather[v][i])
			u = LCAFather[u][i], v = LCAFather[v][i];
	return LCAFather[v][0];
}

int get_LCA_low(int u, int v)
{
	for (int i = k; ~i; i--)
		if (dep[LCAFather[u][i]] > dep[v])
			u = LCAFather[u][i];
	return u;
}

int get_middle(int u, int dis)
{
	for (int i = k; ~i; i--)
		if (dep[LCAFather[u][i]] > dis)
			u = LCAFather[u][i];
	return u;
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	//freopen("date.in","r",stdin);freopen("date.out","w",stdout);
	memset(edge_num, -1, sizeof edge_num);
	read(n);
	k = pre_work();
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		add(u, v);
	}
	dfs(1, 0, 0);
	LCA();
	read(T);
	while (T--)
	{
		read(u);
		read(v);
		if (u == v)
		{
			printf("%d\n", n);
			continue;
		}
		R = LCA(u, v);
		dis = dep[u] + dep[v] - (dep[R] << 1);
		if (dep[u] < dep[v]) swap(u, v);
		if (R == v)
		{
			if ((dep[u] - dep[v]) & 1) puts("0");
			else
			{
				x = get_middle(u, (dep[u] + dep[v]) >> 1);
				printf("%d\n", son[LCAFather[x][0]] - son[x]);
			}
		}
		else
		{
			if (dep[u] == dep[v])
			{
				x = get_LCA_low(u, R);
				y = get_LCA_low(v, R);
				printf("%d\n", n - son[x] - son[y]);
			}
			else
			{
				if (dis & 1) puts("0");
				else
				{
					x = get_middle(u, dep[u] - (dis >> 1));
					printf("%d\n", son[LCAFather[x][0]] - son[x]);
				}
			}
		}
	}
	return 0;
}
