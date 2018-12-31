#include <cstdio>
#define MAXN 400010
using namespace std;

struct SegmentTree
{
	int p, r, m;
	int left, right;
	int ans;
	int lb, rb;
};

struct ask
{
	int lb;
	int rb;
	int ans;
};

SegmentTree tree[MAXN * 2];
int n, m, top = 1;
int a, b;
char s[MAXN];

void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		if (s[tree[u].p] == '(') tree[u].rb++;
		else tree[u].lb++;
		return ;
	}
	tree[u].m = (tree[u].p + tree[u].r) >> 1;
	tree[u].left = ++top;
	tree[top].p = tree[u].p;
	tree[top].r = tree[u].m;
	Build_A_Tree(top);
	tree[u].right = ++top;
	tree[top].p = tree[u].m;
	tree[top].r = tree[u].r;
	Build_A_Tree(top);
	tree[u].ans = tree[tree[u].left].ans + tree[tree[u].right].ans;
	if (tree[tree[u].left].rb > tree[tree[u].right].lb)
	{
		tree[u].ans += tree[tree[u].right].lb;
		tree[u].lb = tree[tree[u].left].lb;
		tree[u].rb = tree[tree[u].right].rb + tree[tree[u].left].rb - tree[tree[u].right].lb;
	}
	else
	{
		tree[u].ans += tree[tree[u].left].rb;
		tree[u].lb = tree[tree[u].left].lb + tree[tree[u].right].lb - tree[tree[u].left].rb;
		tree[u].rb = tree[tree[u].right].rb;
	}
	return ;
}

ask query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return (ask)
	{
		tree[u].lb, tree[u].rb, tree[u].ans
	};
	if (tree[u].m >= r) return query(tree[u].left, l, r);
	else if (tree[u].m <= l) return query(tree[u].right, l, r);
	else
	{
		ask aa = query(tree[u].left, l, tree[u].m);
		ask bb = query(tree[u].right, tree[u].m, r);
		if (aa.rb > bb.lb) return (ask)
		{
			aa.lb, aa.rb + bb.rb - bb.lb, aa.ans + bb.ans + bb.lb
		};
		else return (ask)
		{
			aa.lb + bb.lb - aa.rb, bb.rb, aa.ans + bb.ans + aa.rb
		};
	}
}

int main()
{
	scanf("%d%d%s", &n, &m, s + 1);
	tree[top].p = 1;
	tree[top].r = n + 1;
	Build_A_Tree(top);
	while (m--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", query(1, a, b + 1).ans * 2);
	}
	return 0;
}
