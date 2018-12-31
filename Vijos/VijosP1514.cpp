#include <cstdio>
#define MAXN 210000
using namespace std;

struct rec
{
	int p, r, m;
	int left, right;
	int sum;
};

int top = 1;
int a[MAXN];
rec tree[2 * MAXN] = {};
int n, p, q, m;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].sum = a[tree[u].p];
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
	tree[u].sum = mymax(tree[tree[u].left].sum, tree[tree[u].right].sum);
}

int query(int u, int a, int b)
{
	if ((tree[u].p == a) && (tree[u].r == b))
		return tree[u].sum;
	if (tree[u].m >= b) return query(tree[u].left, a, b);
	else if (tree[u].m <= a) return query(tree[u].right, a, b);
	else return mymax(query(tree[u].left, a, tree[u].m), query(tree[u].right, tree[u].m, b));
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d %d", &p, &q);
		printf("%d\n", query(1, p, q + 1));
	}
	return 0;
}
