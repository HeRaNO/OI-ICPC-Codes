#include <cstdio>
using namespace std;

struct SegmentTree
{
	int p, r, m, x;
};

SegmentTree tree[1 << 18];
int n, T, opt, x, y;

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

inline void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		read(tree[u].x);
		return ;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	Build_A_Tree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_A_Tree(u << 1 | 1);
	tree[u].x = tree[u << 1].x + tree[u << 1 | 1].x;
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
	tree[u].x = tree[u << 1].x + tree[u << 1 | 1].x;
	return ;
}

inline int query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].x;
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, tree[u].m) + query(u << 1 | 1, tree[u].m, r);
}

int main()
{
	read(n);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	read(T);
	while (T--)
	{
		read(opt);
		read(x);
		read(y);
		opt--;
		if (!opt) modify(1, x, y);
		else printf("%d\n", query(1, x, y + 1));
	}
	return 0;
}