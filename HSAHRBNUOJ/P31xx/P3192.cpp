#include <cstdio>
#include <cstring>
#define MAXN 500005
using namespace std;

struct SegmentTree
{
	int p, r, m;
	int left, right;
	long long status;
};

int m, n, T, top = 1, root = 1;
SegmentTree tree[2 * MAXN];
int a[MAXN];
int opt, u, v, l, r, c;
bool s[64];

void get_sequence(long long status)
{
	int cnt = 0;
	memset(s, false, sizeof(s));
	while (status)
	{
		if (status % 2LL) s[++cnt] = 1;
		else cnt++;
		status >>= 1LL;
	}
	for (int i = 1; i < m; i++) printf("%d ", s[i]);
	printf("%d\n", s[m]);
	return ;
}

void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].status = 1LL << (a[tree[u].p] - 1);
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
	tree[u].status = tree[tree[u].left].status | tree[tree[u].right].status;
	return ;
}

void modify(int u, int x, int v)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].status = 1LL << (v - 1);
		return ;
	}
	if (x < tree[u].m) modify(tree[u].left, x, v);
	else modify(tree[u].right, x, v);
	tree[u].status = tree[tree[u].left].status | tree[tree[u].right].status;
	return ;
}

long long big_query(int u, int a, int b)
{
	if (tree[u].p == a && tree[u].r == b) return tree[u].status;
	if (tree[u].m >= b) return big_query(tree[u].left, a, b);
	else if (tree[u].m <= a) return big_query(tree[u].right, a, b);
	else return big_query(tree[u].left, a, tree[u].m) | big_query(tree[u].right, tree[u].m, b);
}

bool exist_query(int u, int a, int b, int v)
{
	if (tree[u].p == a && tree[u].r == b)
	{
		long long work = tree[u].status >> (v - 1);
		if (work & 1LL) return true;
		else return false;
	}
	if (tree[u].m >= b) return exist_query(tree[u].left, a, b, v);
	else if (tree[u].m <= a) return exist_query(tree[u].right, a, b, v);
	else return exist_query(tree[u].left, a, tree[u].m, v) || exist_query(tree[u].right, tree[u].m, b, v);
}

int main()
{
	freopen("pencil.in", "r", stdin);
	freopen("pencil.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(root);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &opt);
		if (opt == 1)
		{
			scanf("%d %d", &u, &c);
			modify(root, u, c);
		}
		else if (opt == 2)
		{
			scanf("%d %d", &l, &r);
			get_sequence(big_query(root, l, r + 1));
		}
		else
		{
			scanf("%d %d %d", &l, &r, &c);
			if (exist_query(root, l, r + 1, c)) puts("Exist");
			else puts("Not Found");
		}
	}
	return 0;
}
