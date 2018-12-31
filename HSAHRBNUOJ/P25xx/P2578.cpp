#include <cstdio>
#include <algorithm>
#define MAXN 20010
using namespace std;

struct SegmentTree
{
	int p, r, m;
	int left, right;
	int c;
};

struct Seg
{
	int l, r;
};

Seg a[MAXN];
SegmentTree tree[MAXN * 4];
pair <int, int *> b[MAXN * 2];
int ori[MAXN * 2], cnt;
int n, top = 1, ans;
bool appear[MAXN];

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
	tree[np].c = tree[u].c;
	np = tree[u].right;
	tree[np].c = tree[u].c;
	tree[u].c = 0;
	return ;
}

void modify(int u, int l, int r, int c)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].c = c;
		return ;
	}
	if (tree[u].c) Push_Down(u);
	if (r <= tree[u].m) modify(tree[u].left, l, r, c);
	else if (tree[u].m <= l) modify(tree[u].right, l, r, c);
	else
	{
		modify(tree[u].left, l, tree[u].m, c);
		modify(tree[u].right, tree[u].m, r, c);
	}
	return ;
}

void query(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		appear[tree[u].c] = true;
		return ;
	}
	if (tree[u].c) Push_Down(u);
	query(tree[u].left);
	query(tree[u].right);
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	//freopen("punch.in","r",stdin);freopen("punch.out","w",stdout);
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i].l);
		read(a[i].r);
		b[2 * i - 1].first = a[i].l;
		b[2 * i - 1].second = &a[i].l;
		b[2 * i].first = a[i].r;
		b[2 * i].second = &a[i].r;
	}
	sort(b + 1, b + n * 2 + 1);
	b[0].first = -1;
	for (int i = 1; i <= 2 * n; i++)
	{
		if (b[i].first != b[i - 1].first) cnt++;
		*b[i].second = cnt;
	}
	tree[1].p = 1;
	tree[1].r = cnt + 1;
	Build_A_Tree(1);
	for (int i = 1; i <= n; i++) modify(1, a[i].l, a[i].r, i);
	query(1);
	for (int i = 1; i <= n; i++) ans += appear[i];
	printf("%d\n", ans);
	return 0;
}
