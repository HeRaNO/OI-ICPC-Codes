#include <cstdio>
#include <vector>
#define MAXN 50010
using namespace std;

struct SegmentTree
{
	int p, r, m;
	int left, right;
	long long lazy1, lazy2, lazy3;
	long long sum, deep;
};

SegmentTree tree[2 * MAXN];
vector <int> g[MAXN];
int n, T, R = 1, x, cnt, top = 1;
int edge_num[MAXN];
int in[MAXN], out[MAXN];
int seq[MAXN];
long long dep[MAXN], y;
char opt[3];

void dfs(int node, long long d)
{
	in[node] = R;
	seq[R++] = node;
	dep[node] = d;
	for (int i = 0; i < g[node].size(); i++)
		dfs(g[node][i], d + 1LL);
	out[node] = R;
}

void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].deep = dep[seq[tree[u].p]];
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
	tree[u].deep = tree[tree[u].left].deep + tree[tree[u].right].deep;
	return ;
}

void lazy(int u)
{
	if (tree[u].p + 1 == tree[u].r) return ;
	long long length = tree[tree[u].left].r - tree[tree[u].left].p;
	tree[tree[u].left].lazy1 += tree[u].lazy1;
	tree[tree[u].left].lazy2 += tree[u].lazy2;
	tree[tree[u].left].lazy3 += tree[u].lazy3;
	tree[tree[u].left].sum += (tree[u].lazy1 - tree[u].lazy2) * length + tree[tree[u].left].deep * tree[u].lazy3;
	length = tree[tree[u].right].r - tree[tree[u].right].p;
	tree[tree[u].right].lazy1 += tree[u].lazy1;
	tree[tree[u].right].lazy2 += tree[u].lazy2;
	tree[tree[u].right].lazy3 += tree[u].lazy3;
	tree[tree[u].right].sum += (tree[u].lazy1 - tree[u].lazy2) * length + tree[tree[u].right].deep * tree[u].lazy3;
	tree[u].lazy1 = tree[u].lazy2 = tree[u].lazy3 = 0LL;
	return ;
}

void modify(int u, int l, int r, long long k, int deep)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		long long length = tree[u].r - tree[u].p;
		tree[u].lazy1 += k;
		tree[u].sum += length * k + tree[u].deep - dep[deep] * length;
		tree[u].lazy2 += dep[deep];
		tree[u].lazy3++;
		return ;
	}
	if (tree[u].lazy1 || tree[u].lazy2 || tree[u].lazy3) lazy(u);
	if (r <= tree[u].m) modify(tree[u].left, l, r, k, deep);
	else if (l >= tree[u].m) modify(tree[u].right, l, r, k, deep);
	else
	{
		modify(tree[u].left, l, tree[u].m, k, deep);
		modify(tree[u].right, tree[u].m, r, k, deep);
	}
	tree[u].sum = tree[tree[u].left].sum + tree[tree[u].right].sum;
}

long long query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].sum;
	if (tree[u].lazy1 || tree[u].lazy2 || tree[u].lazy3) lazy(u);
	if (tree[u].m >= r) return query(tree[u].left, l, r);
	else if (tree[u].m <= l) return query(tree[u].right, l, r);
	else return query(tree[u].left, l, tree[u].m) + query(tree[u].right, tree[u].m, r);
}

int main()
{
	//freopen("truetears.in","r",stdin);freopen("truetears.out","w",stdout);
	scanf("%d %d", &n, &T);
	for (int i = 2; i <= n; i++)
	{
		scanf("%d", &x);
		g[x].push_back(i);
	}
	dfs(1, 0LL);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	while (T--)
	{
		scanf("%s %d", opt, &x);
		if (opt[0] == 'Q') printf("%lld\n", query(1, in[x], out[x]));
		else
		{
			scanf("%lld", &y);
			modify(1, in[x], out[x], y, x);
		}
	}
	return 0;
}
