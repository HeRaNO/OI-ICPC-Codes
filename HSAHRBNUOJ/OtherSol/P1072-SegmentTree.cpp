#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#define MAXN 10010
using namespace std;

struct rec
{
	int p, r, m;
	int left, right;
	int sum;
	int inc;
};

int m, n, top = 1, add;
rec tree[2 * MAXN];
int x[MAXN];
int i, j, k;
string flag;

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

void pass(int u)
{
	int np = tree[u].left;
	tree[np].sum += tree[u].inc * (tree[np].r - tree[np].p);
	tree[np].inc += tree[u].inc;
	np = tree[u].right;
	tree[np].sum += tree[u].inc * (tree[np].r - tree[np].p);
	tree[np].inc += tree[u].inc;
	tree[u].inc = 0;
}

void modify(int u, int l, int r, int add)
{
	if ((tree[u].p == l) && (tree[u].r == r))
	{
		tree[u].sum += add * (r - l);
		tree[u].inc += add;
		return;
	}
	if (tree[u].inc != 0)
		pass(u);
	if (r <= tree[u].m) modify(tree[u].left, l, r, add);
	else if (l >= tree[u].m) modify(tree[u].right, l, r, add);
	else
	{
		modify(tree[u].left, l, tree[u].m, add);
		modify(tree[u].right, tree[u].m, r, add);
	}
	tree[u].sum = tree[tree[u].left].sum + tree[tree[u].right].sum;
}

long query(int u, int a, int b)
{
	if ((tree[u].p == a) && (tree[u].r == b))
		return tree[u].sum;
	if (tree[u].inc != 0) pass(u);
	if (tree[u].m >= b) return query(tree[u].left, a, b);
	else if (tree[u].m <= a) return query(tree[u].right, a, b);
	else return query(tree[u].left, a, tree[u].m) + query(tree[u].right, tree[u].m, b);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", &x[i]);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	for (i = 1; i <= m; i++)
	{
		cin.clear();
		cin >> flag;
		if (flag == "modify")
		{
			cin >> j >> k >> add;
			modify(1, j, k + 1, add);
		}
		else if (flag == "query")
		{
			cin >> j >> k;
			cout << query(1, j, k + 1) << endl;
		}
	}
	return 0;
}
