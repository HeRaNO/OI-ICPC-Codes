#include <cstdio>
#include <cstring>
#define MAXN 100010
using namespace std;

struct SegmentTree
{
	int p, r, m;
	int left, right;
	long long sum;
};

SegmentTree tree[MAXN * 2];
int n, T, l, r, top = 1;
long long MOD;
char a[MAXN];

void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].sum = a[tree[u].p - 1];
		return ;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u].left = ++top;
	tree[top].p = tree[u].p;
	tree[top].r = tree[u].m;
	Build_A_Tree(top);
	tree[u].right = ++top;
	tree[top].p = tree[u].m;
	tree[top].r = tree[u].r;
	Build_A_Tree(top);
	tree[u].sum = (tree[tree[u].left].sum * tree[tree[u].right].sum) % MOD;
	return ;
}

long long query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].sum;
	if (r <= tree[u].m) return query(tree[u].left, l, r);
	else if (tree[u].m <= l) return query(tree[u].right, l, r);
	else return query(tree[u].left, l, tree[u].m) * query(tree[u].right, tree[u].m, r) % MOD;
}

int main()
{
	//freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	gets(a);
	n = strlen(a);
	scanf("%lld", &MOD);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &l, &r);
		printf("%lld\n", query(1, l, r + 1));
	}
	return 0;
}
