#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 100010
#define MAXT 50010
using namespace std;

struct reunion
{
	int l, r, id;
	int res;
};

struct SegmentTree
{
	int p, r, m;
	pair <int, int> c;
};

reunion ans[MAXT];
SegmentTree tree[1 << 17];
int n, T, block_num, m;
int a[MAXN], pos[MAXN], ori[MAXN];
pair <int, int *> b[MAXN];

bool cmp(reunion a, reunion b)
{
	return pos[a.l] == pos[b.l] ? a.r < b.r : a.l < b.l;
}
bool cmp_id(reunion a, reunion b)
{
	return a.id < b.id;
}

inline void Push_Up(int u)
{
	pair <int, int> a = tree[u << 1].c, b = tree[u << 1 | 1].c;
	if (a.first > b.first) tree[u].c = a;
	else if (a.first == b.first)
	{
		if (a.second < b.second) tree[u].c = a;
		else tree[u].c = b;
	}
	else tree[u].c = b;
	return ;
}

inline void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].c = make_pair(0, tree[u].p);
		return ;
	}
	tree[u].m = (tree[u].p + tree[u].r) >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	Build_A_Tree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_A_Tree(u << 1 | 1);
	Push_Up(u);
	return ;
}

inline void modify(int u, int x, int delta)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].c.first += delta;
		return ;
	}
	if (x < tree[u].m) modify(u << 1, x, delta);
	else modify(u << 1 | 1, x, delta);
	Push_Up(u);
	return ;
}

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

inline void update(int x, int v)
{
	modify(1, a[x], v);
	return ;
}

inline void ModuiAlgorithm()
{
	sort(ans + 1, ans + T + 1, cmp);
	int l = 1, r = 0;
	for (int i = 1; i <= T; i++)
	{
		while (r < ans[i].r) update(++r, 1);
		while (r > ans[i].r) update(r--, -1);
		while (l < ans[i].l) update(l++, -1);
		while (l > ans[i].l) update(--l, 1);
		ans[i].res = ori[tree[1].c.second];
	}
	sort(ans + 1, ans + T + 1, cmp_id);
	return ;
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	freopen("reunion.in", "r", stdin);
	freopen("reunion.out", "w", stdout);
	read(n);
	read(T);
	block_num = (int)sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		b[i].first = a[i];
		b[i].second = &a[i];
		pos[i] = (i - 1) / block_num + 1;
	}
	for (int i = 1; i <= T; i++)
	{
		read(ans[i].l);
		read(ans[i].r);
		ans[i].id = i;
	}
	Discretization();
	tree[1].p = 1;
	tree[1].r = m + 1;
	Build_A_Tree(1);
	ModuiAlgorithm();
	for (int i = 1; i <= T; i++) printf("%d\n", ans[i].res);
	return 0;
}
