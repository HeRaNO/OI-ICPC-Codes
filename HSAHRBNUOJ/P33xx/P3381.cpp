#include <cstdio>
#define MAXN 500010
using namespace std;

struct data
{
	int ans;
	int suf;
	int pre;
	int lazy;
};

struct SegmentTree
{
	int p, r, m;
	int left, right;
	data w;
};

SegmentTree tree[MAXN * 2];
int n, T, x, y, top = 1, ans, pos;
char opt;

__attribute__((__optimize__("O2"))) inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

__attribute__((__optimize__("O2"))) inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

__attribute__((__optimize__("O2"))) inline data Push_Up(int u, data x, data y)
{
	data res;
	res.ans = mymax(x.suf + y.pre, mymax(x.ans, y.ans));
	res.pre = x.pre;
	if (res.pre == tree[tree[u].left].r - tree[tree[u].left].p) res.pre += y.pre;
	res.suf = y.suf;
	if (res.suf == tree[tree[u].right].r - tree[tree[u].right].p) res.suf += x.suf;
	res.lazy = 0;
	return res;
}

__attribute__((__optimize__("O2"))) inline void Push_Down(int u)
{
	int np = tree[u].left;
	if (tree[u].w.lazy == -1)
	{
		tree[np].w = (data)
		{
			0, 0, 0, -1
		};
		np = tree[u].right;
		tree[np].w = (data)
		{
			0, 0, 0, -1
		};
	}
	else
	{
		int len = tree[np].r - tree[np].p;
		tree[np].w = (data)
		{
			len, len, len, 1
		};
		np = tree[u].right;
		len = tree[np].r - tree[np].p;
		tree[np].w = (data)
		{
			len, len, len, 1
		};
	}
	tree[u].w.lazy = 0;
	return ;
}

__attribute__((__optimize__("O2"))) void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].w = (data)
		{
			1, 1, 1, 0
		};
		return ;
	}
	tree[u].m = (tree[u].p + tree[u].r) >> 1;
	top++;
	tree[u].left = top;
	tree[top].p = tree[u].p;
	tree[top].r = tree[u].m;
	Build_A_Tree(top);
	top++;
	tree[u].right = top;
	tree[top].p = tree[u].m;
	tree[top].r = tree[u].r;
	Build_A_Tree(top);
	tree[u].w = Push_Up(u, tree[tree[u].left].w, tree[tree[u].right].w);
	return ;
}

__attribute__((__optimize__("O2"))) void modify(int u, int l, int r, bool way)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		if (way)
		{
			tree[u].w.ans = tree[u].w.pre = tree[u].w.suf = r - l;
			tree[u].w.lazy = 1;
		}
		else
		{
			tree[u].w.ans = tree[u].w.pre = tree[u].w.suf = 0;
			tree[u].w.lazy = -1;
		}
		return ;
	}
	if (tree[u].w.lazy != 0) Push_Down(u);
	if (r <= tree[u].m) modify(tree[u].left, l, r, way);
	else if (l >= tree[u].m)modify(tree[u].right, l, r, way);
	else
	{
		modify(tree[u].left, l, tree[u].m, way);
		modify(tree[u].right, tree[u].m, r, way);
	}
	tree[u].w = Push_Up(u, tree[tree[u].left].w, tree[tree[u].right].w);
	return ;
}

__attribute__((__optimize__("O2"))) int query(int u, int x)
{
	if (tree[u].p + 1 == tree[u].r) return tree[u].p;
	if (tree[u].w.lazy != 0) Push_Down(u);
	if (tree[tree[u].left].w.ans >= x) return query(tree[u].left, x);
	else if (tree[tree[u].left].w.suf + tree[tree[u].right].w.pre >= x) return tree[tree[u].left].r - tree[tree[u].left].w.suf;
	else return query(tree[u].right, x);
}

__attribute__((__optimize__("O2"))) int main()
{
	n = read();
	T = read();
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	while (T--)
	{
		opt = getchar();
		while (opt != 'A' && opt != 'L') opt = getchar();
		if (opt == 'A')
		{
			x = read();
			if (tree[1].w.ans < x)
			{
				ans++;
				continue;
			}
			pos = query(1, x);
			modify(1, pos, pos + x, false);
		}
		else
		{
			x = read();
			y = read();
			modify(1, x, y + 1, true);
		}
	}
	printf("%d\n", ans);
	return 0;
}
