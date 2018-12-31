#include <cstdio>
using namespace std;

struct SegmentTree
{
	int p, r, m, x;
};

SegmentTree tree[1 << 19];
int n, T, MOD, opt, x, last;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r) return ;
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	Build_A_Tree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_A_Tree(u << 1 | 1);
	return ;
}

inline void modify(int u, int x, int v)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].x = v;
		return ;
	}
	if (x < tree[u].m) modify(u << 1, x, v);
	else modify(u << 1 | 1, x, v);
	tree[u].x = mymax(tree[u << 1].x, tree[u << 1 | 1].x);
	return ;
}

inline int query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].x;
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else return mymax(query(u << 1, l, tree[u].m), query(u << 1 | 1, tree[u].m, r));
}

inline void read(int &x)
{
	x = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'A')
		{
			x = 0;
			return ;
		}
		if (ch == 'Q')
		{
			x = 1;
			return ;
		}
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	x = f ? -x : x;
	return ;
}

int main()
{
	read(T);
	read(MOD);
	tree[1].p = 1;
	tree[1].r = T + 1;
	Build_A_Tree(1);
	while (T--)
	{
		read(opt);
		read(x);
		if (!opt)
		{
			n++;
			x = (x + last) % MOD;
			modify(1, n, x);
		}
		else printf("%d\n", last = query(1, n - x + 1, n + 1));
	}
	return 0;
}