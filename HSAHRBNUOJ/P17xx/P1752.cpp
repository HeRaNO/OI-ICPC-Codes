#include <cstdio>
#include <climits>
#define MAXN 1000010

struct rec
{
	int left;
	int right;
	int p, r, m;
	int siz;
	int biggest, smallest;
};

rec tree[2 * MAXN];
int in[MAXN];
int top = 1;
int n, m, root = 1, opt, a, b;
int ansmax, ansmin;

void pre_work()
{
	for (int i = 0; i < 2 * MAXN; i++)
	{
		tree[i].biggest = INT_MIN;
		tree[i].smallest = INT_MAX;
	}
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void Build_A_Tree(int u)
{
	if (tree[u].p == tree[u].r)
	{
		tree[u].biggest = tree[u].smallest = in[tree[u].p];
		tree[u].siz++;
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
	tree[top].p = tree[u].m + 1;
	tree[top].r = tree[u].r;
	Build_A_Tree(top);
	tree[u].siz = tree[tree[u].left].siz + tree[tree[u].right].siz;
	tree[u].biggest = mymax(tree[tree[u].left].biggest, tree[tree[u].right].biggest);
	tree[u].smallest = mymin(tree[tree[u].left].smallest, tree[tree[u].right].smallest);
}

void query(int u, int a, int b)
{
	if (a == 1 && b == tree[u].siz)
	{
		ansmin = mymin(ansmin, tree[u].smallest);
		ansmax = mymax(ansmax, tree[u].biggest);
		return ;
	}
	if (a <= tree[tree[u].left].siz && b > tree[tree[u].left].siz)
	{
		query(tree[u].left, a, tree[tree[u].left].siz);
		query(tree[u].right, 1, b - tree[tree[u].left].siz);
	}
	else if (a <= tree[tree[u].left].siz && b <= tree[tree[u].left].siz) query(tree[u].left, a, b);
	else if (a > tree[tree[u].left].siz && b <= tree[tree[u].left].siz + tree[tree[u].right].siz)
		query(tree[u].right, a - tree[tree[u].left].siz, b - tree[tree[u].left].siz);
}

void del(int u, int a)
{
	if (tree[u].p == tree[u].r)
	{
		tree[u].siz--;
		tree[u].biggest = INT_MIN;
		tree[u].smallest = INT_MAX;
		return ;
	}
	if (a <= tree[tree[u].left].siz) del(tree[u].left, a);
	else del(tree[u].right, a - tree[tree[u].left].siz);
	tree[u].siz = tree[tree[u].left].siz + tree[tree[u].right].siz;
	tree[u].biggest = mymax(tree[tree[u].left].biggest, tree[tree[u].right].biggest);
	tree[u].smallest = mymin(tree[tree[u].left].smallest, tree[tree[u].right].smallest);
}

int main()
{
	scanf("%d %d", &n, &m);
	pre_work();
	for (int i = 1; i <= n; i++) scanf("%d", &in[i]);
	tree[1].p = 1;
	tree[1].r = n;
	Build_A_Tree(root);
	while (m--)
	{
		scanf("%d", &opt);
		if (opt == 1)
		{
			scanf("%d", &a);
			del(root, a);
		}
		else
		{
			ansmax = INT_MIN;
			ansmin = INT_MAX;
			scanf("%d %d", &a, &b);
			query(root, a, b);
			printf("%d %d\n", ansmin, ansmax);
		}
	}
	return 0;
}
