#include <cmath>
#include <cstdio>
#define MAXN 100010
using namespace std;

struct SegmentTree
{
	int p, r, m;
	int left, right;
	long long lazy, set;
	long long sum, mx, mn;
};

SegmentTree tree[MAXN * 2];
int n, T, top = 1, opt, u, v, w;
long long a[MAXN];

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
	while (ch >= '0' && ch <= '9') x = x * 10LL + ch - '0', ch = getchar();
	return ;
}

inline void read(long long &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10LL + ch - '0', ch = getchar();
	return ;
}

inline long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}
inline long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

inline void lazy(int u, long long v)
{
	tree[u].sum += (tree[u].r - tree[u].p) * v;
	tree[u].mn += v;
	tree[u].mx += v;
	tree[u].lazy += v;
	return ;
}

inline void setit(int u, long long v)
{
	tree[u].sum = (tree[u].r - tree[u].p) * v;
	tree[u].mn = tree[u].mx = tree[u].set = v;
	tree[u].lazy = 0;
	return ;
}

void Push_Up(int u)
{
	tree[u].sum = tree[tree[u].left].sum + tree[tree[u].right].sum;
	tree[u].mx = mymax(tree[tree[u].left].mx, tree[tree[u].right].mx);
	tree[u].mn = mymin(tree[tree[u].left].mn, tree[tree[u].right].mn);
	return ;
}

inline void Push_Down(int u)
{
	int lch = tree[u].left, rch = tree[u].right;
	if (tree[u].set != -1)
	{
		setit(lch, tree[u].set);
		setit(rch, tree[u].set);
		tree[u].set = -1;
	}
	if (tree[u].lazy)
	{
		lazy(lch, tree[u].lazy);
		lazy(rch, tree[u].lazy);
		tree[u].lazy = 0;
	}
	return ;
}

void Build_A_Tree(int u)
{
	tree[u].sum = tree[u].mx = tree[u].mn = 0LL;
	tree[u].set = -1LL;
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].mn = tree[u].mx = tree[u].sum = a[tree[u].p];
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
	Push_Up(u);
	return ;
}

void modify_sqrt(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		long long smn = (long long)sqrt(tree[u].mn);
		long long smx = (long long)sqrt(tree[u].mx);
		if (smn == smx)
		{
			setit(u, smn);
			return ;
		}
		else if (tree[u].mx == tree[u].mn + 1)
		{
			lazy(u, smn - tree[u].mn);
			return ;
		}
		Push_Down(u);
		modify_sqrt(tree[u].left, l, tree[u].m);
		modify_sqrt(tree[u].right, tree[u].m, r);
		Push_Up(u);
		return ;
	}
	Push_Down(u);
	if (tree[u].m >= r) modify_sqrt(tree[u].left, l, r);
	else if (tree[u].m <= l) modify_sqrt(tree[u].right, l, r);
	else
	{
		modify_sqrt(tree[u].left, l, tree[u].m);
		modify_sqrt(tree[u].right, tree[u].m, r);
	}
	Push_Up(u);
	return ;
}

void modify_add(int u, int l, int r, int delta)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		lazy(u, delta);
		return;
	}
	Push_Down(u);
	if (r <= tree[u].m) modify_add(tree[u].left, l, r, delta);
	else if (l >= tree[u].m) modify_add(tree[u].right, l, r, delta);
	else
	{
		modify_add(tree[u].left, l, tree[u].m, delta);
		modify_add(tree[u].right, tree[u].m, r, delta);
	}
	Push_Up(u);
	return ;
}

long long query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].sum;
	Push_Down(u);
	if (tree[u].m >= r) return query(tree[u].left, l, r);
	else if (tree[u].m <= l) return query(tree[u].right, l, r);
	else return query(tree[u].left, l, tree[u].m) + query(tree[u].right, tree[u].m, r);
}

int main()
{
	read(n);
	read(T);
	for (int i = 1; i <= n; i++) read(a[i]);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	while (T--)
	{
		read(opt);
		if (opt == 1)
		{
			read(u);
			read(v);
			read(w);
			modify_add(1, u, v + 1, w);
		}
		else if (opt == 2)
		{
			read(u);
			read(v);
			modify_sqrt(1, u, v + 1);
		}
		else
		{
			read(u);
			read(v);
			printf("%lld\n", query(1, u, v + 1));
		}
	}
	return 0;
}
