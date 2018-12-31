#include <cstdio>
#define MAXN 500010
//If n is more than 5e5,SegmentTree is not recommended.
//You can try Block or ZKW SegmentTree then ^_^.
using namespace std;

struct SegmentTree
{
	int p, r, m; //p is the left of the interval.r is the right.m is the middle of the interval.
	//the left is closed and the right is open.
	int sum, lazy, setit;
	bool isset;
	//sum is the sum of the interval.lazy is used in order to optimize.
	//setit is used when you need to set the interval to one certain number.
	//isset is a sign when you need to set a interval.
};

SegmentTree tree[1 << 20];
int n, T, l, r, v, opt;
int a[MAXN];

inline void Prepare()
{
	tree[1].p = 1;
	tree[1].r = n + 1;
	return ;
}

inline void Set(int u)
{
	int np = u << 1;
	tree[np].sum = (tree[np].r - tree[np].p) * tree[u].setit;
	tree[np].setit = tree[u].setit;
	tree[np].lazy = 0;
	tree[np].isset = true;
	np = u << 1 | 1;
	tree[np].sum = (tree[np].r - tree[np].p) * tree[u].setit;
	tree[np].setit = tree[u].setit;
	tree[np].lazy = 0;
	tree[np].isset = true;
	tree[u].setit = 0;
	tree[u].isset = false;
	return ;
}

inline void Push(int u)
{
	int np = u << 1;
	tree[np].sum += (tree[np].r - tree[np].p) * tree[u].lazy;
	tree[np].lazy += tree[u].lazy;
	np = u << 1 | 1;
	tree[np].sum += (tree[np].r - tree[np].p) * tree[u].lazy;
	tree[np].lazy += tree[u].lazy;
	tree[u].lazy = 0;
	return ;
}

inline void Update(int u)
{
	tree[u].sum = tree[u << 1].sum + tree[u << 1 | 1].sum;
	return ;
}

void Build_A_Tree(int u)
{
	tree[u].lazy = tree[u].setit = 0;
	tree[u].isset = false; //If there is not multiple of data,this can be omitted.
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].sum = a[tree[u].p];
		return ;
	}
	tree[u].sum = 0;
	tree[u].m = tree[u].r + tree[u].p >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	Build_A_Tree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_A_Tree(u << 1 | 1);
	Update(u);
	return ;
}

void modify_one(int u, int x, int v) //Change a[x] into v.
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].sum = v;
		return ;
	}
	if (tree[u].isset) Set(u);
	if (tree[u].lazy) Push(u);
	if (x < tree[u].m) modify_one(u << 1, x, v);
	else modify_one(u << 1 | 1, x, v);
	Update(u);
	return ;
}

void modify_interval(int u, int l, int r, int delta) //Make the number in [l,r] add delta.
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].sum += (r - l) * delta;
		tree[u].lazy += delta;
		return ;
	}
	if (tree[u].isset) Set(u);
	if (tree[u].lazy) Push(u);
	if (r <= tree[u].m) modify_interval(u << 1, l, r, delta);
	else if (l >= tree[u].m) modify_interval(u << 1 | 1, l, r, delta);
	else
	{
		modify_interval(u << 1, l, tree[u].m, delta);
		modify_interval(u << 1 | 1, tree[u].m, r, delta);
	}
	Update(u);
	return ;
}

void set_the_interval(int u, int l, int r, int xi) //Set the interval[l,r] to xi
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].sum = (r - l) * xi;
		tree[u].setit = xi;
		tree[u].lazy = 0;
		tree[u].isset = true;
		return ;
	}
	if (tree[u].isset) Set(u);
	if (tree[u].lazy) Push(u);
	if (r <= tree[u].m) set_the_interval(u << 1, l, r, xi);
	else if (l >= tree[u].m) set_the_interval(u << 1 | 1, l, r, xi);
	else
	{
		set_the_interval(u << 1, l, tree[u].m, xi);
		set_the_interval(u << 1 | 1, tree[u].m, r, xi);
	}
	Update(u);
	return ;
}

int query(int u, int l, int r) //Query the sum of the interval[l,r].
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].sum;
	if (tree[u].isset) Set(u);
	if (tree[u].lazy) Push(u);
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (l >= tree[u].m) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, tree[u].m) + query(u << 1 | 1, tree[u].m, r);
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
	read(n);
	read(T);
	for (int i = 1; i <= n; i++) read(a[i]);
	Prepare();
	Build_A_Tree(1);
	while (T--)
	{
		read(opt);
		if (opt == 0)
		{
			read(l);
			read(v);
			modify_one(1, l, v);
		}
		else if (opt == 1)
		{
			read(l);
			read(r);
			read(v);
			modify_interval(1, l, r + 1, v);
		}
		else if (opt == 2)
		{
			read(l);
			read(r);
			read(v);
			set_the_interval(1, l, r + 1, v);
		}
		else
		{
			read(l);
			read(r);
			printf("%d\n", query(1, l, r + 1));
		}
	}
	return 0;
}
