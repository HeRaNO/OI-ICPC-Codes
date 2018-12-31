#include <cstdio>
#include <cstdlib>
#define MAXN 100010
using namespace std;

struct Treap
{
	int left_child, right_child;
	int siz, v, rnd, cnt;
};

Treap tree[MAXN];
int n, siz, root, ans;
int opt, x;

void left_rotate(int &node)
{
	int t = tree[node].right_child;
	tree[node].right_child = tree[t].left_child;
	tree[t].left_child = node;
	tree[t].siz = tree[node].siz;
	tree[node].siz = tree[tree[node].left_child].siz + tree[tree[node].right_child].siz + tree[node].cnt;
	node = t;
}

void right_rotate(int &node)
{
	int t = tree[node].left_child;
	tree[node].left_child = tree[t].right_child;
	tree[t].right_child = node;
	tree[t].siz = tree[node].siz;
	tree[node].siz = tree[tree[node].left_child].siz + tree[tree[node].right_child].siz + tree[node].cnt;
	node = t;
}

void add(int &node, int v)
{
	if (!node)
	{
		siz++;
		node = siz;
		tree[node].cnt = tree[node].siz = 1;
		tree[node].v = v;
		tree[node].rnd = rand();
		return ;
	}
	tree[node].siz++;
	if (tree[node].v == v) tree[node].cnt++;
	else if (tree[node].v < v)
	{
		add(tree[node].right_child, v);
		if (tree[tree[node].right_child].rnd < tree[node].rnd) left_rotate(node);
	}
	else
	{
		add(tree[node].left_child, v);
		if (tree[tree[node].left_child].rnd < tree[node].rnd) right_rotate(node);
	}
}

void del(int &node, int v)
{
	if (!node) return ;
	if (tree[node].v == v)
	{
		if (tree[node].cnt > 1)
		{
			tree[node].cnt--;
			tree[node].siz--;
			return ;
		}
		if (tree[node].left_child * tree[node].right_child == 0) node = tree[node].left_child + tree[node].right_child;
		else if (tree[tree[node].left_child].rnd < tree[tree[node].right_child].rnd)
		{
			right_rotate(node);
			del(node, v);
		}
		else
		{
			left_rotate(node);
			del(node, v);
		}
	}
	else if (v > tree[node].v) tree[node].siz--, del(tree[node].right_child, v);
	else tree[node].siz--, del(tree[node].left_child, v);
}

int getrank(int node, int v)
{
	if (!node) return 0;
	if (tree[node].v == v) return tree[tree[node].left_child].siz + 1;
	else if (v > tree[node].v) return tree[tree[node].left_child].siz + tree[node].cnt + getrank(tree[node].right_child, v);
	else return getrank(tree[node].left_child, v);
}

int select(int node, int v)
{
	if (!node) return 0;
	if (v <= tree[tree[node].left_child].siz) return select(tree[node].left_child, v);
	else if (v > tree[tree[node].left_child].siz + tree[node].cnt) return select(tree[node].right_child, v - tree[tree[node].left_child].siz - tree[node].cnt);
	else return tree[node].v;
}

void prec(int node, int v)
{
	if (!node) return ;
	if (tree[node].v < v)
	{
		ans = node;
		prec(tree[node].right_child, v);
	}
	else prec(tree[node].left_child, v);
}

void succ(int node, int v)
{
	if (!node) return ;
	if (tree[node].v > v)
	{
		ans = node;
		succ(tree[node].left_child, v);
	}
	else succ(tree[node].right_child, v);
}

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d", &opt, &x);
		if (opt == 1) add(root, x);
		if (opt == 2) del(root, x);
		if (opt == 3) printf("%d\n", getrank(root, x));
		if (opt == 4) printf("%d\n", select(root, x));
		if (opt == 5)
		{
			ans = 0;
			prec(root, x);
			printf("%d\n", tree[ans].v);
		}
		if (opt == 6)
		{
			ans = 0;
			succ(root, x);
			printf("%d\n", tree[ans].v);
		}
	}
	return 0;
}
