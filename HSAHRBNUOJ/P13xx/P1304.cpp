#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10010
using namespace std;

struct link
{
	int to, val, nxt;
};

link e[MAXN << 1];
int head[MAXN], cnt;
int n, T, u, v, w, k;
int dep[MAXN], LCAFather[MAXN][16], _2pow[16], LCADis[MAXN][16], ans;

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

inline void dfs(int x, int f, int v, int deep)
{
	LCAFather[x][0] = f;
	LCADis[x][0] = v;
	dep[x] = deep;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != f) dfs(e[i].to, x, e[i].val, deep + 1);
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

inline bool query(int u, int v)
{
	int res = 0;
	for (int i = k; ~i; i--)
		if (_2pow[i] <= dep[v] - dep[u])
		{
			res += LCADis[v][i];
			v = LCAFather[v][i];
		}
	if (u != v) return false;
	ans += res;
	return true;
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
	read(T);
	for (_2pow[0] = 1; _2pow[k] <= n; k++) _2pow[k + 1] = _2pow[k] << 1;
	k--;
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		read(w);
		add(u, v, w);
	}
	dfs(1, 0, 0, 1);
	LCA();
	cnt = 0;
	while (T--)
	{
		read(u);
		read(v);
		if (query(u, v)) ++cnt;
	}
	printf("%d\n%d\n", cnt, ans);
	return 0;
}