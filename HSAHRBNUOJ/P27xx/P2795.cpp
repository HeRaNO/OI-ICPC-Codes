#include <cstdio>
#define MAXN 500010
#define INT_MAX 2147483647
using namespace std;

struct SBT
{
	int left_child;
	int right_child;
	int s;
	int key;
};

SBT tree[MAXN];
int siz, root;
int n, T, a, l, r, p, ans, t, pp, s;
long long pre[MAXN];

void right_rotate(int &node)
{
	int k = tree[node].left_child;
	tree[node].left_child = tree[k].right_child;
	tree[k].right_child = node;
	tree[k].s = tree[node].s;
	tree[node].s = tree[tree[node].left_child].s + tree[tree[node].right_child].s + 1;
	node = k;
}

void left_rotate(int &node)
{
	int k = tree[node].right_child;
	tree[node].right_child = tree[k].left_child;
	tree[k].left_child = node;
	tree[k].s = tree[node].s;
	tree[node].s = tree[tree[node].left_child].s + tree[tree[node].right_child].s + 1;
	node = k;
}

void maintain(int &node, bool flag)
{
	if (!flag)
	{
		if (tree[tree[tree[node].left_child].left_child].s > tree[tree[node].right_child].s)
			right_rotate(node);
		else if (tree[tree[tree[node].right_child].left_child].s > tree[tree[node].right_child].s)
		{
			left_rotate(node);
			right_rotate(node);
		}
		else return;
	}
	else
	{
		if (tree[tree[tree[node].right_child].right_child].s > tree[tree[node].left_child].s)
			left_rotate(node);
		else if (tree[tree[tree[node].left_child].right_child].s > tree[tree[node].left_child].s)
		{
			right_rotate(node);
			left_rotate(node);
		}
		else return;
	}
	maintain(tree[node].left_child, false);
	maintain(tree[node].right_child, true);
	maintain(node, false);
	maintain(node, true);
}

void add(int &node, int k)
{
	if (!node)
	{
		tree[node = ++siz].s = 1;
		tree[node].left_child = tree[node].right_child = 0;
		tree[node].key = k;
	}
	else
	{
		tree[node].s++;
		if (tree[node].key > k)
			add(tree[node].left_child, k);
		else add(tree[node].right_child, k);
		maintain(node, k >= tree[node].key);
	}
}

int select(int &node, int k)
{
	int v = tree[tree[node].left_child].s + 1;
	if (k == v) return tree[node].key;
	else if (k < v) return select(tree[node].left_child, k);
	else return select(tree[node].right_child, k - v);
}

bool exist(int &node, int v)
{
	if (!node) return false;
	if (v < tree[node].key) return exist(tree[node].left_child, v);
	else return (tree[node].key == v) || exist(tree[node].right_child, v);
}

int prec(int &node, int v)
{
	if (!node) return v;
	if (v <= tree[node].key) return prec(tree[node].left_child, v);
	else
	{
		int r = prec(tree[node].right_child, v);
		if (r == v) return tree[node].key;
	}
}

int succ(int &node, int v)
{
	if (!node) return v;
	if (tree[node].key <= v) return succ(tree[node].right_child, v);
	else
	{
		int r = succ(tree[node].left_child, v);
		if (r == v) return tree[node].key;
	}
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

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	//freopen("seq.in","r",stdin);freopen("seq.out","w",stdout);
	read(n);
	read(T);
	for (int i = 1; i <= n; i++)
	{
		read(a);
		pre[i] = pre[i - 1] + a;
	}
	while (T--)
	{
		read(l);
		read(r);
		read(p);
		if (r - l + 1 >= p)
		{
			puts("0");
			continue;
		}
		root = siz = 0;
		ans = INT_MAX;
		add(root, 0);
		for (int i = l; i <= r; i++)
		{
			t = (pre[i] - pre[l - 1]) % p;
			if (exist(root, t))
			{
				ans = 0;
				break;
			}
			pp = prec(root, t);
			ans = mymin(ans, t - pp);
			add(root, t);
		}
		printf("%d\n", ans);
	}
	return 0;
}
