#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
using namespace std;

struct link
{
	int to, nxt;
};

link e[MAXN << 1];
int head[MAXN], cnt, ans = ~(1 << 31), sum, l, r;
int n, k, a[MAXN], dep[MAXN], _2pow[8], LCAFather[MAXN][8], LCADis[MAXN][8];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, head[u]
	};
	head[u] = cnt++;
	e[cnt] = (link)
	{
		u, head[v]
	};
	head[v] = cnt++;
}

inline void dfs(int x, int father, int deep)
{
	LCAFather[x][0] = father;
	LCADis[x][0] = 1;
	dep[x] = deep;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father) dfs(e[i].to, x, deep + 1);
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
	int ans = 0;
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = k; ~i; i--)
		if (_2pow[i] <= dep[u] - dep[v])
		{
			ans += LCADis[u][i];
			u = LCAFather[u][i];
		}
	for (int i = k; ~i; i--)
		if (LCAFather[u][i] != LCAFather[v][i])
		{
			ans += LCADis[u][i] + LCADis[v][i];
			u = LCAFather[u][i];
			v = LCAFather[v][i];
		}
	if (u != v) ans += LCADis[u][0] + LCADis[v][0];
	return ans;
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
	for (_2pow[0] = 1; _2pow[k] <= n; k++) _2pow[k + 1] = _2pow[k] << 1;
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		read(l);
		read(r);
		if (l) add(i, l);
		if (r) add(i, r);
	}
	dfs(1, 0, 1);
	LCA();
	for (int i = 1; i <= n; i++)
	{
		sum = 0;
		for (int j = 1; j <= n; j++) sum += a[j] * GetDis(i, j);
		ans = mymin(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}