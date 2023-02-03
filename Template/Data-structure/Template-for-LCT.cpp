#include <cstdio>
#include <algorithm>
#define MAXN 200010
using namespace std;

struct LCT
{
	int ch[MAXN][2], fa[MAXN];
	long long path_s[MAXN], sub_s[MAXN], w[MAXN], v[MAXN];
	bool rev[MAXN];

	void pushUp(int x)
	{
		int l = ch[x][0], r = ch[x][1];
		path_s[x] = path_s[l] + path_s[r] + w[x];
		sub_s[x] = sub_s[l] + sub_s[r] + w[x] + v[x];
		return ;
	}

	void filp(int x)
	{
		rev[x] = (!rev[x]);
		swap(ch[x][0], ch[x][1]);
		return ;
	}

	void pushDown(int x)
	{
		if (!rev[x]) return ;
		if (ch[x][0]) filp(ch[x][0]);
		if (ch[x][1]) filp(ch[x][1]);
		rev[x] = false;
		return ;
	}

	bool isRoot(int x)
	{
		return !(ch[fa[x]][0] == x || ch[fa[x]][1] == x);
	}

	bool isRightCh(int x)
	{
		return ch[fa[x]][1] == x;
	}

	void rotate(int x)
	{
		int y = fa[x], z = fa[y];
		int chx = (ch[y][1] == x), chy = (ch[z][1] == y);
		if (!isRoot(y)) ch[z][chy] = x;
		ch[y][chx] = ch[x][chx ^ 1]; fa[ch[x][chx ^ 1]] = y;
		ch[x][chx ^ 1] = y; fa[y] = x; fa[x] = z;
		pushUp(y); pushUp(x);
		return ;
	}

	void update(int x)
	{
		if (!isRoot(x)) update(fa[x]);
		pushDown(x);
		return ;
	}

	void splay(int x)
	{
		update(x);
		for (int f = fa[x]; f = fa[x], !isRoot(x); rotate(x))
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

	void makeRoot(int x)
	{
		access(x); splay(x); filp(x);
		return ;
	}

	void Init(int x, int y)
	{
		w[x] = y; pushUp(x);
		return ;
	}

	void Link(int x, int y)
	{
		makeRoot(x); access(y); splay(y);
		fa[x] = y; v[y] += sub_s[x]; pushUp(y);
		return ;
	}

	void Cut(int x, int y)
	{
		makeRoot(x); access(y); splay(y);
		ch[y][0] = fa[x] = 0; pushUp(y);
		return ;
	}

	void Modify(int x, int y)
	{
		makeRoot(x); w[x] += y; pushUp(x);
		return ;
	}

	long long QueryPath(int x, int y)
	{
		makeRoot(x); access(y); splay(y);
		return path_s[y];
	}

	long long QuerySubTree(int x, int p)
	{
		makeRoot(p); access(x); splay(x);
		return v[x] + w[x];
	}
};

LCT T;
int n, Q, opt, u, v;

int main()
{
	scanf("%d %d", &n, &Q);
	for (int i = 1; i <= n; i++) scanf("%d", &u), T.Init(i, u);
	for (int i = 1; i < n; i++) scanf("%d %d", &u, &v), T.Link(u + 1, v + 1);
	while (Q--)
	{
		scanf("%d", &opt);
		if (!opt)
		{
			scanf("%d %d", &u, &v); T.Cut(u + 1, v + 1);
			scanf("%d %d", &u, &v); T.Link(u + 1, v + 1);
		}
		else if (opt == 1)
		{
			scanf("%d %d", &u, &v);
			T.Modify(u + 1, v);
		}
		else
		{
			scanf("%d %d", &u, &v);
			printf("%lld\n", T.QuerySubTree(u + 1, v + 1));
		}
	}
	return 0;
}
