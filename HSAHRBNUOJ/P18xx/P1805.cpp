#include <cstdio>
#define MAXN 1000010
using namespace std;

struct node
{
	int left_child;
	int right_child;
	int s;
	int key;
};

node tree[MAXN];
int n, k;
int siz;
int min_gz;

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
	if (flag)
	{
		if (tree[tree[tree[node].right_child].right_child].s > tree[tree[node].left_child].s)
			left_rotate(node);
		else if (tree[tree[tree[node].right_child].left_child].s > tree[tree[node].left_child].s)
		{
			right_rotate(tree[node].right_child);
			left_rotate(node);
		}
		else return;
	}
	else
	{
		if (tree[tree[tree[node].left_child].left_child].s > tree[tree[node].right_child].s)
			right_rotate(node);
		else if (tree[tree[tree[node].left_child].right_child].s > tree[tree[node].right_child].s)
		{
			left_rotate(tree[node].left_child);
			right_rotate(node);
		}
		else return;
	}
	maintain(tree[node].left_child, false);
	maintain(tree[node].right_child, true);
	maintain(node, false);
	maintain(node, true);
}

void insert(int &node, int k)
{
	if (!node)
	{
		node = ++siz;
		tree[node].s = 1;
		tree[node].left_child = tree[node].right_child = 0;
		tree[node].key = k;
	}
	else
	{
		tree[node].s++;
		if (tree[node].key > k)
			insert(tree[node].left_child, k);
		else insert(tree[node].right_child, k);
		maintain(node, k >= tree[node].key);
	}
}

int select(int &node, int k)
{
	int v = tree[tree[node].right_child].s + 1;
	if (k == v) return tree[node].key;
	else if (k > v) return select(tree[node].left_child, k - v);
	else return select(tree[node].right_child, k);
}

void Delete(int &node, int delay, int v)
{
	if (!node) return ;
	if (tree[node].key + delay < v)
	{
		node = tree[node].right_child;
		Delete(node, delay, v);
	}
	else
	{
		Delete(tree[node].left_child, delay, v);
		tree[node].s = tree[tree[node].left_child].s + tree[tree[node].right_child].s + 1;
	}
}

int main()
{
	char c[5];
	int x;
	int u = siz = tree[0].s = 0;
	int delay = 0;
	scanf("%d %d", &n, &min_gz);
	while (n--)
	{
		scanf("%s%d", c, &x);
		if (c[0] == 'I')
		{
			if (x < min_gz) continue;
			insert(u, x - delay);
		}
		else if (c[0] == 'A') delay += x;
		else if (c[0] == 'F') printf("%d\n", tree[u].s < x ? -1 : select(u, x) + delay);
		else
		{
			delay -= x;
			Delete(u, delay, min_gz);
		}
	}
	printf("%d\n", siz - tree[u].s);
	return 0;
}
