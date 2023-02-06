#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 100005
using namespace std;

struct LCT
{
	int ch[MAXN][2], fa[MAXN];
	int sub_s[MAXN], v[MAXN];

	void pushUp(int x)
	{
		int l = ch[x][0], r = ch[x][1];
		sub_s[x] = sub_s[l] + sub_s[r] + 1 + v[x];
		return ;
	}

	bool isRoot(int x)
	{
		return !(ch[fa[x]][0] == x || ch[fa[x]][1] == x);
	}

	int isRightCh(int x)
	{
		return (ch[fa[x]][1] == x) ? 1 : 0;
	}

	void rotate(int x)
	{
		int y = fa[x], z = fa[y], chx = isRightCh(x);
		if (!isRoot(y)) ch[z][isRightCh(y)] = x; fa[x] = z;
		ch[y][chx] = ch[x][chx ^ 1]; fa[ch[x][chx ^ 1]] = y; 
		ch[x][chx ^ 1] = y; fa[y] = x;
		pushUp(y); pushUp(x);
		return ;
	}

	void splay(int x)
	{
		for (int f = fa[x]; !isRoot(x); rotate(x), f = fa[x])
			if (!isRoot(f))
				rotate(isRightCh(x) == isRightCh(f) ? f : x);
		return ;
	}

	void access(int x)
	{
		for (int i = 0; x; i = x, x = fa[x])
		{
			splay(x);
			v[x] += sub_s[ch[x][1]] - sub_s[i];
			ch[x][1] = i, pushUp(x);
		}
		return ;
	}

	void Init(int x, int y)
	{
		sub_s[x] = y;
		return ;
	}

	int FindRoot(int x)
	{
		access(x); splay(x);
		while (ch[x][0]) x = ch[x][0];
		splay(x); return x;
	}

	void Link(int x, int y)
	{
		access(x); splay(x); access(y); splay(y);
		fa[x] = y; v[y] += sub_s[x]; pushUp(y);
		return ;
	}

	void Cut(int x, int y)
	{
		access(x); splay(x);
		fa[ch[x][0]] = 0; ch[x][0] = 0; pushUp(x);
		return ;
	}

	int Query(int x)
	{
		x = FindRoot(x);
		return sub_s[ch[x][1]];
	}
} Tb, Tw;

int n, Q, opt, u, v, fa[MAXN];
bool col[MAXN];
vector<int> g[MAXN];

void add(int u, int v)
{
	g[u].push_back(v); g[v].push_back(u);
	return ;
}

void dfs(int x, int f)
{
	fa[x] = f;
	for (int v : g[x]) if (v != f) dfs(v, x);
	return ;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++) scanf("%d %d", &u, &v), add(u, v);
	dfs(1, n + 1);
	for (int i = 1; i <= n; i++) Tb.Init(i, 1), Tw.Init(i, 1);
	for (int i = 1; i <= n; i++) Tb.Link(i, fa[i]);
	scanf("%d", &Q);
	while (Q--)
	{
		scanf("%d %d", &opt, &u);
		if (opt)
		{
			(!col[u] ? Tb : Tw).Cut(u, fa[u]);
			(!col[u] ? Tw : Tb).Link(u, fa[u]);
			col[u] = (!col[u]);
		}
		else
			printf("%d\n", (!col[u] ? Tb : Tw).Query(u));
	}
	return 0;
}
