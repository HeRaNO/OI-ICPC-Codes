#include <cstdio>
#define MAXN 1100010
using namespace std;

struct rec
{
	int sum;
	int inc;
};

int m, n;
rec tree[2 * MAXN];
int i;
int u, v, w;
bool finish = false;

inline void read(int &x)
{
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	x = 0;
	while (ch <= '9' && ch >= '0')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return ;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void Build_A_Tree(int pos, int l, int r)
{
	if (l + 1 == r)
	{
		int tmp;
		read(tmp);
		tree[pos].sum = tmp;
		return ;
	}
	int mid = (l + r) >> 1;
	Build_A_Tree(pos << 1, l, mid);
	Build_A_Tree((pos << 1) + 1, mid, r);
	tree[pos].sum = mymin(tree[pos << 1].sum, tree[(pos << 1) + 1].sum);
}

inline void update(int pos)
{
	if (!tree[pos].inc) return ;
	tree[pos << 1].inc += tree[pos].inc;
	tree[(pos << 1) + 1].inc += tree[pos].inc;
	tree[pos << 1].sum += tree[pos].inc;
	tree[(pos << 1) + 1].sum += tree[pos].inc;
	tree[pos].inc = 0;
}

void modify(int pos, int l, int r, int ll, int rr, int delta)
{
	if (finish) return ;
	if (l >= ll && r <= rr)
	{
		tree[pos].sum += delta;
		if (tree[pos].sum < 0)
		{
			printf("-1\n%d\n", i);
			finish = true;
			return ;
		}
		tree[pos].inc += delta;
		return ;
	}
	update(pos);
	int mid = (l + r) >> 1;
	if (ll < mid) modify(pos << 1, l, mid, ll, rr, delta);
	if (rr > mid) modify((pos << 1) + 1, mid, r, ll, rr, delta);
	tree[pos].sum = mymin(tree[pos << 1].sum, tree[(pos << 1) + 1].sum);
}

int main()
{
	//freopen("classroom.in","r",stdin);freopen("classroom.out","w",stdout);
	read(n);
	read(m);
	Build_A_Tree(1, 1, n + 1);
	for (i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		read(w);
		modify(1, 1, n + 1, v, w + 1, -u);
		if (finish) return 0;
	}
	printf("0\n");
	return 0;
}
