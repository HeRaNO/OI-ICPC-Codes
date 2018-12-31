#include <cstdio>
#define MAXN 50010
using namespace std;

struct data
{
	int lup, rup, len;
	int ldown, rdown;
	int mxup, mxdown;
	int l, r;
} x;

struct SegmentTree
{
	int p, r, m;
	data w;
};

SegmentTree tree[1 << 17];
int n, T, l, r;
int a[MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline data Push_Up(data a, data b)
{
	data res = (data)
	{
		a.lup, b.rup, a.len + b.len, a.ldown, b.rdown, mymax(a.mxup, b.mxup), mymax(a.mxdown, b.mxdown), a.l, b.r
	};
	if (res.lup == a.len && a.r <= b.l) res.lup += b.lup;
	if (res.ldown == a.len && a.r >= b.l) res.ldown += b.ldown;
	if (res.rup == b.len && b.l >= a.r) res.rup += a.rup;
	if (res.rdown == b.len && b.l <= a.r) res.rdown += a.rdown;
	if (a.r <= b.l) res.mxup = mymax(res.mxup, a.rup + b.lup);
	if (a.r >= b.l) res.mxdown = mymax(res.mxdown, a.rdown + b.ldown);
	return res;
}

inline void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].w = (data)
		{
			1, 1, 1, 1, 1, 1, 1, a[tree[u].p], a[tree[u].p]
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
	tree[u].w = Push_Up(tree[u << 1].w, tree[u << 1 | 1].w);
	return ;
}

inline data query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].w;
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
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	read(T);
	while (T--)
	{
		read(l);
		read(r);
		x = query(1, l, r + 1);
		printf("%d\n", mymax(x.mxup, x.mxdown));
	}
	return 0;
}
