#include <cstdio>
#include <cstring>
#define MAXN 10010
using namespace std;

struct rec
{
	int p, r, m;
	int left, right;
	int sum;
};

int m, n, top = 1;
rec tree[2 * MAXN];
int x[MAXN];
int j, k;
char flag[10];

void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].sum = x[tree[u].p];
		return;
	}
	tree[u].m = (tree[u].p + tree[u].r) / 2;
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
	tree[u].sum = tree[tree[u].left].sum + tree[tree[u].right].sum;
}

void modify(int u, int x, int v)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].sum = v;
		return;
	}
	if (x < tree[u].m) modify(tree[u].left, x, v);
	else modify(tree[u].right, x, v);
	tree[u].sum = tree[tree[u].left].sum + tree[tree[u].right].sum;
}

int query(int u, int a, int b)
{
	if ((tree[u].p == a) && (tree[u].r == b)) return tree[u].sum;
	if (tree[u].m >= b) return query(tree[u].left, a, b);
	else if (tree[u].m <= a) return query(tree[u].right, a, b);
	else return query(tree[u].left, a, tree[u].m) + query(tree[u].right, tree[u].m, b);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	for (int i = 1; i <= m; i++)
	{
		scanf("%s %d %d", flag, &j, &k);
		if (flag[0] == 'm') modify(1, j, k);
		else printf("%d\n", query(1, j, k + 1));
	}
	return 0;
}
