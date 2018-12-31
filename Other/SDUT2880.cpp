#include <cstdio>
#define MAXN 100010
using namespace std;

struct SegmentTree
{
	int p, r, m;
	int left, right;
	long long sum, lazy, setit;
};

SegmentTree tree[2 * MAXN];
int n, T, l, r, v, top, opt, cas, t;
long long ans;

inline void Prepare()
{
	top = 1;
	tree[1].p = 1;
	tree[1].r = n + 1;
	return ;
}

inline void Set(int u)
{
	int np = tree[u].left;
	tree[np].sum = (tree[np].r - tree[np].p) * tree[u].setit;
	tree[np].setit = tree[u].setit;
	tree[np].lazy = 0LL;
	np = tree[u].right;
	tree[np].sum = (tree[np].r - tree[np].p) * tree[u].setit;
	tree[np].setit = tree[u].setit;
	tree[np].lazy = 0LL;
	tree[u].setit = -1LL;
	return ;
}

inline void Push(int u)
{
	int np = tree[u].left;
	tree[np].sum += (tree[np].r - tree[np].p) * tree[u].lazy;
	tree[np].lazy += tree[u].lazy;
	np = tree[u].right;
	tree[np].sum += (tree[np].r - tree[np].p) * tree[u].lazy;
	tree[np].lazy += tree[u].lazy;
	tree[u].lazy = 0LL;
	return ;
}

inline void Update(int u)
{
	tree[u].sum = tree[tree[u].left].sum + tree[tree[u].right].sum;
	return ;
}

void Build_A_Tree(int u)
{
	tree[u].lazy = 0LL;
	tree[u].setit = -1LL;
	tree[u].sum = 0LL;
	if (tree[u].p + 1 == tree[u].r) return ;
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
	Update(u);
	return ;
}

void modify_one(int u, int x, int v)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].sum = v;
		return ;
	}
	if (tree[u].setit != -1) Set(u);
	if (tree[u].lazy) Push(u);
	if (x < tree[u].m) modify_one(tree[u].left, x, v);
	else modify_one(tree[u].right, x, v);
	Update(u);
	return ;
}

void modify_interval(int u, int l, int r, int delta)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].sum += (r - l) * delta;
		tree[u].lazy += delta;
		return ;
	}
	if (tree[u].setit != -1) Set(u);
	if (tree[u].lazy) Push(u);
	if (r <= tree[u].m) modify_interval(tree[u].left, l, r, delta);
	else if (l >= tree[u].m) modify_interval(tree[u].right, l, r, delta);
	else
	{
		modify_interval(tree[u].left, l, tree[u].m, delta);
		modify_interval(tree[u].right, tree[u].m, r, delta);
	}
	Update(u);
	return ;
}

void set_the_interval(int u, int l, int r, int xi)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].sum = (r - l) * xi;
		tree[u].setit = xi;
		tree[u].lazy = 0;
		return ;
	}
	if (tree[u].setit != -1) Set(u);
	if (tree[u].lazy) Push(u);
	if (r <= tree[u].m) set_the_interval(tree[u].left, l, r, xi);
	else if (l >= tree[u].m) set_the_interval(tree[u].right, l, r, xi);
	else
	{
		set_the_interval(tree[u].left, l, tree[u].m, xi);
		set_the_interval(tree[u].right, tree[u].m, r, xi);
	}
	Update(u);
	return ;
}

long long query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].sum;
	if (tree[u].setit != -1) Set(u);
	if (tree[u].lazy) Push(u);
	if (r <= tree[u].m) return query(tree[u].left, l, r);
	else if (l >= tree[u].m) return query(tree[u].right, l, r);
	else return query(tree[u].left, l, tree[u].m) + query(tree[u].right, tree[u].m, r);
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
	read(cas);
	while (cas--)
	{
		read(n);
		read(T);
		Prepare();
		Build_A_Tree(1);
		ans = 0;
		t = 0;
		while (T--)
		{
			read(opt);
			read(l);
			read(r);
			modify_interval(1, 1, n + 1, opt - t);
			ans += query(1, l, r + 1);
			set_the_interval(1, l, r + 1, 0);
			t = opt;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
