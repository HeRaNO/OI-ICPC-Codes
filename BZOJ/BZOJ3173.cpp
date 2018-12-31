#include <cstdio>
#include <cstdlib>
#define MAXN 100010
using namespace std;

struct Treap
{
	int left_child, right_child;
	int siz, v, rnd;
};

Treap tree[MAXN];
int siz, root;
int n, x, cnt, a[MAXN], c[MAXN], ans[MAXN];

void left_rotate(int &node)
{
	int t = tree[node].right_child;
	tree[node].right_child = tree[t].left_child;
	tree[t].left_child = node;
	tree[t].siz = tree[node].siz;
	tree[node].siz = tree[tree[node].left_child].siz + tree[tree[node].right_child].siz + 1;
	node = t;
}

void right_rotate(int &node)
{
	int t = tree[node].left_child;
	tree[node].left_child = tree[t].right_child;
	tree[t].right_child = node;
	tree[t].siz = tree[node].siz;
	tree[node].siz = tree[tree[node].left_child].siz + tree[tree[node].right_child].siz + 1;
	node = t;
}

void add(int &node, int v)
{
	if (!node)
	{
		siz++;
		node = siz;
		tree[node].siz = 1;
		tree[node].rnd = rand();
		return ;
	}
	tree[node].siz++;
	if (v <= tree[tree[node].left_child].siz)
	{
		add(tree[node].left_child, v);
		if (tree[tree[node].left_child].rnd < tree[node].rnd) right_rotate(node);
	}
	else
	{
		add(tree[node].right_child, v - tree[tree[node].left_child].siz - 1);
		if (tree[tree[node].right_child].rnd < tree[node].rnd) left_rotate(node);
	}
	return ;
}

inline void Get_a(int &node)
{
	if (!node) return ;
	Get_a(tree[node].left_child);
	a[++cnt] = node;
	Get_a(tree[node].right_child);
	return ;
}

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int lowbit(int x)
{
	return x & -x;
}

inline void update(int x, int y)
{
	for (; x <= n; x += lowbit(x)) c[x] = mymax(c[x], y);
	return ;
}

inline int query(int x)
{
	int res = 0;
	for (; x; x -= lowbit(x)) res = mymax(res, c[x]);
	return res;
}

inline void LIS()
{
	for (int i = 1; i <= n; i++)
	{
		int t = query(a[i]) + 1;
		update(a[i], t);
		ans[a[i]] = t;
	}
	for (int i = 1; i <= n; i++) ans[i] = mymax(ans[i], ans[i - 1]);
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
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(x);
		add(root, x);
	}
	Get_a(root);
	LIS();
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}
