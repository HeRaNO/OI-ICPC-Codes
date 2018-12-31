#include <cstdio>
#define MAXN 100010
using namespace std;

struct data
{
	long long lx, rx;
	int nlnr, nlr, lnr, lr;
};

struct SegmentTree
{
	int p, r, m;
	long long lazy;
	data a;
};

SegmentTree tree[1 << 18];
int n, T, a[MAXN], d[MAXN], opt, l, r;
long long A, B;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline data Push_Up(data l, data r)
{
	data c;
	c.lx = l.lx;
	c.rx = r.rx;
	int f = (l.rx == r.lx);
	c.nlnr = mymin(l.nlr + r.lnr - f, mymin(l.nlnr + r.lnr, l.nlr + r.nlnr));
	c.lnr = mymin(l.lr + r.lnr - f, mymin(l.lnr + r.lnr, l.lr + r.nlnr));
	c.nlr = mymin(l.nlr + r.lr - f, mymin(l.nlr + r.nlr, l.nlnr + r.lr));
	c.lr = mymin(l.lr + r.lr - f, mymin(l.lr + r.nlr, l.lnr + r.lr));
	return c;
}

inline void Push_Down(int u)
{
	if (!tree[u].lazy) return ;
	tree[u << 1].lazy += tree[u].lazy;
	tree[u << 1 | 1].lazy += tree[u].lazy;
	tree[u << 1].a.lx += tree[u].lazy;
	tree[u << 1 | 1].a.rx += tree[u].lazy;
	tree[u << 1].a.rx += tree[u].lazy;
	tree[u << 1 | 1].a.lx += tree[u].lazy;
	tree[u].lazy = 0LL;
	return ;
}

inline void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].a = (data)
		{
			d[tree[u].p], d[tree[u].p], 0, 1, 1, 1
		};
		return ;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	Build_A_Tree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_A_Tree(u << 1 | 1);
	tree[u].a = Push_Up(tree[u << 1].a, tree[u << 1 | 1].a);
	return ;
}

inline void modify_one(int u, int x, long long v)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].a.lx += v;
		tree[u].a.rx += v;
		return ;
	}
	Push_Down(u);
	if (x < tree[u].m) modify_one(u << 1, x, v);
	else modify_one(u << 1 | 1, x, v);
	tree[u].a = Push_Up(tree[u << 1].a, tree[u << 1 | 1].a);
	return ;
}

inline void modify_seq(int u, int l, int r, long long v)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].lazy += v;
		tree[u].a.lx += v;
		tree[u].a.rx += v;
		return ;
	}
	Push_Down(u);
	if (r <= tree[u].m) modify_seq(u << 1, l, r, v);
	else if (tree[u].m <= l) modify_seq(u << 1 | 1, l, r, v);
	else
	{
		modify_seq(u << 1, l, tree[u].m, v);
		modify_seq(u << 1 | 1, tree[u].m, r, v);
	}
	tree[u].a = Push_Up(tree[u << 1].a, tree[u << 1 | 1].a);
	return ;
}

inline data query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].a;
	Push_Down(u);
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else return Push_Up(query(u << 1, l, tree[u].m), query(u << 1 | 1, tree[u].m, r));
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'A')
		{
			x = 0;
			return ;
		}
		if (ch == 'B')
		{
			x = 1;
			return ;
		}
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	x *= f;
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
	while (ch >= '0' && ch <= '9') x = (x << 3LL) + (x << 1LL) + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 2; i <= n; i++) d[i] = a[i] - a[i - 1];
	tree[1].p = 2;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	read(T);
	while (T--)
	{
		read(opt);
		if (!opt)
		{
			read(l);
			read(r);
			read(A);
			read(B);
			if (l != 1) modify_one(1, l, A);
			if (l < n && l != r) modify_seq(1, l + 1, r + 1, B);
			if (r < n) modify_one(1, r + 1, -(A + B * (long long)(r - l)));
		}
		else
		{
			read(l);
			read(r);
			if (l == r) puts("1");
			else printf("%d\n", query(1, l + 1, r + 1).lr);
		}
	}
	return 0;
}