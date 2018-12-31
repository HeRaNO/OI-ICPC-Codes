#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 505
#define MAXM 124755
using namespace std;

struct link
{
	int x, y, z;
};

link e[MAXM], g[MAXN << 1];
int head[MAXN], cnt, ans1, ans2;
int n, m, k, f[MAXN], _2pow[10], dep[MAXN];
bool used[MAXM];
int LCAFather[MAXN][10], LCADis[MAXN][10];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline int getfather(int x)
{
	return x == f[x] ? x : f[x] = getfather(f[x]);
}

inline void addedge(int u, int v, int w)
{
	g[cnt] = (link)
	{
		v, w, head[u]
	};
	head[u] = cnt++;
	g[cnt] = (link)
	{
		u, w, head[v]
	};
	head[v] = cnt++;
}

inline void Kruskal()
{
	int cnt = 0, fx, fy;
	for (int i = 1; i <= m; i++)
	{
		fx = getfather(e[i].x);
		fy = getfather(e[i].y);
		if (fx != fy)
		{
			used[i] = true;
			f[fy] = fx;
			ans1 += e[i].z;
			cnt++;
			addedge(e[i].x, e[i].y, e[i].z);
		}
		if (cnt == n - 1) break;
	}
	if (cnt != n - 1)
	{
		puts("-1");
		exit(0);
	}
	printf("%d\n", ans1);
	return ;
}

inline void dfs(int x, int father, int val, int deep)
{
	LCAFather[x][0] = father;
	LCADis[x][0] = val;
	dep[x] = deep;
	for (int i = head[x]; ~i; i = g[i].z)
		if (g[i].x != father) dfs(g[i].x, x, g[i].y, deep + 1);
	return ;
}

inline void LCA()
{
	for (int j = 1; j <= k; j++)
		for (int i = 1; i <= n; i++)
		{
			LCAFather[i][j] = LCAFather[LCAFather[i][j - 1]][j - 1];
			LCADis[i][j] = mymax(LCADis[i][j - 1], LCADis[LCAFather[i][j - 1]][j - 1]);
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
			res = mymax(res, LCADis[v][i]);
			v = LCAFather[v][i];
		}
	for (int i = k; ~i; i--)
		if (LCAFather[u][i] != LCAFather[v][i])
		{
			res = mymax(res, mymax(LCADis[u][i], LCADis[v][i]));
			u = LCAFather[u][i];
			v = LCAFather[v][i];
		}
	if (u != v) res = mymax(res, mymax(LCADis[u][0], LCADis[v][0]));
	return res;
}

inline void NextminKruskal()
{
	ans2 = ~(1 << 31);
	for (int i = 1; i <= m; i++)
		if (!used[i])
			ans2 = mymin(ans2, ans1 - GetDis(e[i].x, e[i].y) + e[i].z);
	if (ans2 == ~(1 << 31)) puts("-1");
	else printf("%d\n", ans2);
	return ;
}

bool cmp(link a, link b)
{
	return a.z < b.z;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	memset(head, -1, sizeof head);
	read(n);
	read(m);
	for (_2pow[0] = 1; _2pow[k] <= n; k++) _2pow[k + 1] = _2pow[k] << 1;
	for (int i = 1; i <= n; i++) f[i] = i;
	if (m < n - 1)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= m; i++)
	{
		read(e[i].x);
		read(e[i].y);
		read(e[i].z);
	}
	sort(e + 1, e + m + 1, cmp);
	Kruskal();
	if (m == n - 1)
	{
		puts("-1");
		return 0;
	}
	dfs(1, 0, 0, 1);
	LCA();
	NextminKruskal();
	return 0;
}