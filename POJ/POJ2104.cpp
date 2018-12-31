#include <cstdio>
#include <algorithm>
#define MAXN 100010
#define logN 20
using namespace std;

struct ChairmanTree
{
	int lc, rc, sum;
};

ChairmanTree tree[MAXN * logN];
int n, m, T, l, r, k, a[MAXN];
int pool, root[MAXN], ori[MAXN];
pair <int, int *> b[MAXN];

inline void Discretization()
{
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (b[i].first != b[i - 1].first) ori[++m] = b[i].first;
		*b[i].second = m;
	}
	return ;
}

inline void add(int &y, int &x, int l, int r, int v)
{
	tree[x = ++pool] = tree[y];
	tree[x].sum++;
	if (l == r) return ;
	int mid = l + r >> 1;
	if (v <= mid) add(tree[y].lc, tree[x].lc, l, mid, v);
	else add(tree[y].rc, tree[x].rc, mid + 1, r, v);
	return ;
}

inline int query(int tl, int tr, int l, int r, int k)
{
	if (l == r) return l;
	int delta = tree[tree[tr].lc].sum - tree[tree[tl].lc].sum;
	int mid = l + r >> 1;
	if (delta >= k) return query(tree[tl].lc, tree[tr].lc, l, mid, k);
	else return query(tree[tl].rc, tree[tr].rc, mid + 1, r, k - delta);
}

inline void Build_Chairman_Tree()
{
	for (int i = 1; i <= n; i++) add(root[i - 1], root[i], 1, m, a[i]);
	return ;
}

int main()
{
	while (~scanf("%d %d", &n, &T))
	{
		pool = m = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = make_pair(a[i], &a[i]);
		Discretization();
		Build_Chairman_Tree();
		while (T--)
		{
			scanf("%d %d %d", &l, &r, &k);
			printf("%d\n", ori[query(root[l - 1], root[r], 1, m, k)]);
		}
	}
	return 0;
}