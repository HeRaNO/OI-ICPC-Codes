#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
using namespace std;

struct link
{
	int to, val, nxt;
};

link e[MAXN << 1];
int head[MAXN], cnt;
int n, u, v, w, k, ans;
int _2pow[15], dep[MAXN];
int LCAFather[MAXN][11], LCADis[MAXN][11];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
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

inline void dfs(int x, int father, int val, int deep)
{
	LCAFather[x][0] = father;
	LCADis[x][0] = val;
	dep[x] = deep;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father) dfs(e[i].to, x, e[i].val, deep + 1);
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

inline int GetDis(int x, int y)
{
	int res = 0;
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = k; ~i; i--)
		if (_2pow[i] <= dep[y] - dep[x])
		{
			res += LCADis[y][i];
			y = LCAFather[y][i];
		}
	for (int i = k; ~i; i--)
		if (LCAFather[x][i] != LCAFather[y][i])
		{
			res += LCADis[x][i] + LCADis[y][i];
			x = LCAFather[x][i];
			y = LCAFather[y][i];
		}
	if (x != y) res += LCADis[x][0] + LCADis[y][0];
	return res;
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
	_2pow[0] = 1;
	for (; _2pow[k] <= n; k++) _2pow[k + 1] = _2pow[k] << 1;
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		read(w);
		add(u, v, w);
	}
	dfs(1, -1, 0, 1);
	LCA();
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			ans = mymax(ans, GetDis(i, j));
	printf("%d\n", ans);
	return 0;
}