#include <cstdio>
#include <cstdlib>
using namespace std;

struct rec
{
	int sum, inc;
};

rec tree[1 << 21];
int m, n, i;
int u, v, w;
bool finish;

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

void Build_A_Tree(int u, int l, int r)
{
	if (l + 1 == r)
	{
		read(tree[u].sum);
		return ;
	}
	int mid = (l + r) >> 1;
	Build_A_Tree(u << 1, l, mid);
	Build_A_Tree(u << 1 | 1, mid, r);
	tree[u].sum = mymin(tree[u << 1].sum, tree[u << 1 | 1].sum);
	return ;
}

inline void update(int u)
{
	if (!tree[u].inc) return ;
	tree[u << 1].inc += tree[u].inc;
	tree[u << 1 | 1].inc += tree[u].inc;
	tree[u << 1].sum += tree[u].inc;
	tree[u << 1 | 1].sum += tree[u].inc;
	tree[u].inc = 0;
	return ;
}

void modify(int u, int l, int r, int ll, int rr, int delta)
{
	if (finish) return ;
	if (l >= ll && r <= rr)
	{
		tree[u].sum += delta;
		if (tree[u].sum < 0)
		{
			printf("-1\n%d\n", i);
			exit(0);
		}
		tree[u].inc += delta;
		return ;
	}
	update(u);
	int mid = (l + r) >> 1;
	if (ll < mid) modify(u << 1, l, mid, ll, rr, delta);
	if (rr > mid) modify(u << 1 | 1, mid, r, ll, rr, delta);
	tree[u].sum = mymin(tree[u << 1].sum, tree[u << 1 | 1].sum);
	return ;
}

int main()
{
	read(n);
	read(m);
	Build_A_Tree(1, 1, n + 1);
	for (i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		read(w);
		modify(1, 1, n + 1, v, w + 1, -u);
	}
	printf("0\n");
	return 0;
}
