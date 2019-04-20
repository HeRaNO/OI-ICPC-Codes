#include <cstdio>
#define MAXN 500010
using namespace std;

struct data
{
	int all, ans, pre, suf;
};

struct SegmentTree
{
	int p, r, m;
	int right, left;
	data w;
};

SegmentTree tree[MAXN * 2];
int n, T, top = 1, l, r, opt;
int a[MAXN];

inline int read()
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

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline data PushUp(data x, data y)
{
	data res;
	res.all = x.all + y.all;
	res.ans = mymax(x.suf + y.pre, mymax(x.ans, y.ans));
	res.pre = mymax(x.pre, x.all + y.pre);
	res.suf = mymax(y.suf, y.all + x.suf);
	return res;
}

void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].w.all = tree[u].w.ans = tree[u].w.pre = tree[u].w.suf = a[tree[u].p];
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
	tree[u].w = PushUp(tree[tree[u].left].w, tree[tree[u].right].w);
	return ;
}

void modify(int u, int x, int v)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].w.all = tree[u].w.ans = tree[u].w.pre = tree[u].w.suf = v;
		return ;
	}
	if (x < tree[u].m) modify(tree[u].left, x, v);
	else modify(tree[u].right, x, v);
	tree[u].w = PushUp(tree[tree[u].left].w, tree[tree[u].right].w);
	return ;
}

data query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].w;
	if (tree[u].m >= r) return query(tree[u].left, l, r);
	else if (tree[u].m <= l) return query(tree[u].right, l, r);
	else
	{
		data x = query(tree[u].left, l, tree[u].m);
		data y = query(tree[u].right, tree[u].m, r);
		return PushUp(x, y);
	}
}

int main()
{
	n = read(); T = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	while (T--)
	{
		opt = read();
		l = read();
		r = read();
		if (opt == 2) modify(1, l, r);
		else printf("%d\n", query(1, l, r + 1).ans);
	}
	return 0;
}
