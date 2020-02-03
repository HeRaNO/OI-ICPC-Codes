#include <cstdio>
#include <algorithm>
#define MAXN 110000
using namespace std;

typedef pair <long long, int> pii;

struct SBT
{
	int left_child;
	int right_child;
	int s;
	pii key;
};

SBT tree[MAXN];
int siz, root;
//SBT

int n, m;
long long x0;
int x, s;
long long a[MAXN];
//in

int bnxt[MAXN];
//prework

long long dis_a[MAXN][21], dis_b[MAXN][21];
int father[MAXN][21];
//LCA

int ans, arrive, nowheight;
long long best_a, best_b;
long long rest_dis;
double now, best = 1e18;
//question #1 & #2

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

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

void add(int &node, pii k)
{
	if (!node)
	{
		tree[node = ++siz].s = 1;
		tree[node].left_child = tree[node].right_child = 0;
		tree[node].key = k;
		return ;
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

pii prec(int &node, pii v)
{
	if (!node) return v;
	if (v <= tree[node].key) return prec(tree[node].left_child, v);
	else
	{
		pii r = prec(tree[node].right_child, v);
		if (r == v) return tree[node].key;
		else return r;
	}
}

pii succ(int &node, pii v)
{
	if (!node) return v;
	if (tree[node].key <= v) return succ(tree[node].right_child, v);
	else
	{
		pii r = succ(tree[node].left_child, v);
		if (r == v) return tree[node].key;
		else return r;
	}
}

inline long long myabs(long long a)
{
	return a > 0 ? a : -a;
}

inline void LCA()
{
	for (int j = 2; j <= 17; j++)
		for (int i = 1; i <= n; i++)
		{
			father[i][j] = father[father[i][j - 1]][j - 1];
			dis_a[i][j] = dis_a[i][j - 1] + dis_a[father[i][j - 1]][j - 1];
			dis_b[i][j] = dis_b[i][j - 1] + dis_b[father[i][j - 1]][j - 1];
		}
	return ;
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	add(root, make_pair(1e18, 0));
	add(root, make_pair(-1e18, 0));
	for (int i = n; i; i--)
	{
		pii pre, aft, now;
		int k;
		now = make_pair(a[i], i);
		add(root, now);
		pre = prec(root, now);
		aft = succ(root, now);
		if (i == n) continue;
		if (i == n - 1)
		{
			bnxt[i] = n;
			continue;
		}
		if (myabs(pre.first - a[i]) <= myabs(aft.first - a[i]))
		{
			bnxt[i] = pre.second;
			now = prec(root, pre);
			k = (myabs(now.first - a[i]) <= myabs(aft.first - a[i]) ? now.second : aft.second);
		}
		else
		{
			bnxt[i] = aft.second;
			now = succ(root, aft);
			k = (myabs(pre.first - a[i]) <= myabs(now.first - a[i]) ? pre.second : now.second);
		}
		father[i][1] = bnxt[k];
		dis_a[i][1] = myabs(a[k] - a[i]);
		dis_b[i][1] = (k ? myabs(a[k] - a[bnxt[k]]) : 0);
	}
	LCA();
	x0 = read();
	for (int pos = 1; pos <= n; pos++)
	{
		arrive = pos;
		rest_dis = x0;
		best_a = best_b = 0;
		for (int i = 17; i; i--)
			if (father[arrive][i] && dis_a[arrive][i] + dis_b[arrive][i] <= rest_dis)
			{
				best_a += dis_a[arrive][i];
				best_b += dis_b[arrive][i];
				rest_dis -= dis_a[arrive][i] + dis_b[arrive][i];
				arrive = father[arrive][i];
			}
		if (dis_a[arrive][1] <= rest_dis) best_a += dis_a[arrive][1];
		now = (!best_b ? 1e18 : double(best_a) / double(best_b));
		if (now < best || (now == best && a[pos] > nowheight))
		{
			best = now;
			nowheight = a[pos];
			ans = pos;
		}
	}
	printf("%d\n", ans);
	m = read();
	while (m--)
	{
		s = read();
		x = read();
		best_a = best_b = 0;
		for (int i = 17; i; i--)
			if (father[s][i] && dis_a[s][i] + dis_b[s][i] <= x)
			{
				best_a += dis_a[s][i];
				best_b += dis_b[s][i];
				x -= dis_a[s][i] + dis_b[s][i];
				s = father[s][i];
			}
		if (dis_a[s][1] <= x) best_a += dis_a[s][1];
		printf("%lld %lld\n", best_a, best_b);
	}
	return 0;
}