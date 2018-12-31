#include <cstdio>
#define MAXN 100010
using namespace std;

struct SegmentTree
{
	int p, r, m, x, lazy;
};

SegmentTree tree[1 << 18];
int n, m, opt, l, r, x, a[MAXN];

char ib[20000007], *ip = ib;
void read(int &x)
{
	x = 0;
	bool f = false;
	while (*ip < '0' || *ip > '9')
	{
		if (*ip == '-') f = true;
		++ip;
	}
	while (*ip >= '0' && *ip <= '9') x = x * 10 + *ip++ -48;
	x = f ? -x : x;
	return ;
}

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void Build_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		read(tree[u].x);
		return ;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	Build_Tree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_Tree(u << 1 | 1);
	tree[u].x = mymax(tree[u << 1].x, tree[u << 1 | 1].x);
	return ;
}

inline void Push_Down(int u)
{
	tree[u << 1].lazy += tree[u].lazy;
	tree[u << 1].x += tree[u].lazy;
	tree[u << 1 | 1].lazy += tree[u].lazy;
	tree[u << 1 | 1].x += tree[u].lazy;
	tree[u].lazy = 0;
	return ;
}

inline void modify(int u, int l, int r, int c)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].lazy += c;
		tree[u].x += c;
		return ;
	}
	Push_Down(u);
	if (r <= tree[u].m) modify(u << 1, l, r, c);
	else if (tree[u].m <= l) modify(u << 1 | 1, l, r, c);
	else
	{
		modify(u << 1, l, tree[u].m, c);
		modify(u << 1 | 1, tree[u].m, r, c);
	}
	tree[u].x = mymax(tree[u << 1].x, tree[u << 1 | 1].x);
	return ;
}

inline long long query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].x;
	Push_Down(u);
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else return mymax(query(u << 1, l, tree[u].m), query(u << 1 | 1, tree[u].m, r));
}

int main()
{
	fread(ib, 1, sizeof ib, stdin);
	read(n);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_Tree(1);
	read(m);
	while (m--)
	{
		read(opt);
		read(l);
		read(r);
		if (opt == 1)
		{
			read(x);
			modify(1, l, r + 1, x);
		}
		else printf("%d\n", query(1, l, r + 1));
	}
	return 0;
}