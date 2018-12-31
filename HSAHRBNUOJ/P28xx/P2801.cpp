#include <cstdio>
#include <algorithm>
#define MAXN 300010
using namespace std;

struct circle
{
	int x, r, L, R;
};

struct SegmentTree
{
	int p, r, m;
	int left, right;
	bool c;
};

SegmentTree tree[MAXN * 4];
circle a[MAXN];
pair <int, int *> b[2 * MAXN];
int n, m, top = 1, ans = 1;

void Build_A_Tree(int u)
{
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
	return ;
}

inline void Push_Down(int u)
{
	int np = tree[u].left;
	tree[np].c |= tree[u].c;
	np = tree[u].right;
	tree[np].c |= tree[u].c;
	return ;
}

void modify(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].c = 1;
		return ;
	}
	Push_Down(u);
	if (tree[u].m >= r) modify(tree[u].left, l, r);
	else if (tree[u].m <= l) modify(tree[u].right, l, r);
	else
	{
		modify(tree[u].left, l, tree[u].m);
		modify(tree[u].right, tree[u].m, r);
	}
	tree[u].c = tree[tree[u].left].c && tree[tree[u].right].c;
	return ;
}

bool query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].c;
	Push_Down(u);
	if (tree[u].m >= r) return query(tree[u].left, l, r);
	else if (tree[u].m <= l) return query(tree[u].right, l, r);
	else return query(tree[u].left, l, tree[u].m) && query(tree[u].right, tree[u].m, r);
}

bool cmp(circle a, circle b)
{
	return a.r < b.r;
}

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

int main()
{
	//freopen("circle.in","r",stdin);freopen("circle.out","w",stdout);
	n = read();
	for (int i = 1; i <= n; i++)
	{
		a[i].x = read();
		a[i].r = read();
		a[i].L = a[i].x - a[i].r;
		a[i].R = a[i].x + a[i].r;
		b[(i << 1) - 1].first = a[i].L;
		b[(i << 1) - 1].second = &a[i].L;
		b[i << 1].first = a[i].R;
		b[i << 1].second = &a[i].R;
	}
	sort(b + 1, b + 2 * n + 1);
	for (int i = 1; i <= 2 * n; i++)
	{
		if (b[i].first != b[i - 1].first) m++;
		*b[i].second = m;
	}
	tree[1].p = 1;
	tree[1].r = m + 1;
	Build_A_Tree(1);
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		ans++;
		if (query(1, a[i].L, a[i].R)) ans++;
		else modify(1, a[i].L, a[i].R);
	}
	printf("%d\n", ans);
	return 0;
}
