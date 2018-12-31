#include <cmath>
#include <cstdio>
#define MAXN 300005
using namespace std;

struct SegmentTree
{
	int p, r, m;
	int left, right;
	long long sum;
};

int n, T, top = 1, root = 1;
SegmentTree tree[2 * MAXN];
long long a[MAXN];
int opt, L, R;
long long c;

void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].sum = a[tree[u].p];
		return ;
	}
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
	tree[u].sum = tree[tree[u].left].sum + tree[tree[u].right].sum;
	return ;
}

void modify_add(int u, int x, long long v)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].sum = v;
		return ;
	}
	if (x < tree[u].m) modify_add(tree[u].left, x, v);
	else modify_add(tree[u].right, x, v);
	tree[u].sum = tree[tree[u].left].sum + tree[tree[u].right].sum;
	return ;
}

void modify_log(int u, int ll, int rr)
{
	if (!tree[u].sum) return ;
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].sum = log2(tree[u].sum);
		return ;
	}
	if (tree[u].m >= rr) modify_log(tree[u].left, ll, rr);
	else if (tree[u].m <= ll) modify_log(tree[u].right, ll, rr);
	else
	{
		modify_log(tree[u].left, ll, tree[u].m);
		modify_log(tree[u].right, tree[u].m, rr);
	}
	tree[u].sum = tree[tree[u].left].sum + tree[tree[u].right].sum;
	return ;
}

long long query(int u, int a, int b)
{
	if (tree[u].p == a && tree[u].r == b) return tree[u].sum;
	if (tree[u].m >= b) return query(tree[u].left, a, b);
	else if (tree[u].m <= a) return query(tree[u].right, a, b);
	else return query(tree[u].left, a, tree[u].m) + query(tree[u].right, tree[u].m, b);
}

int main()
{
	freopen("biology.in", "r", stdin);
	freopen("biology.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(root);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &opt);
		if (opt == 1)
		{
			scanf("%d %lld", &L, &c);
			modify_add(root, L, c);
		}
		else if (opt == 2)
		{
			scanf("%d %d", &L, &R);
			modify_log(root, L, R + 1);
		}
		else
		{
			scanf("%d %d", &L, &R);
			printf("%lld\n", query(root, L, R + 1));
		}
	}
	return 0;
}

