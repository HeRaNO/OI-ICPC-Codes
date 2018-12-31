#include <cstdio>
#include <algorithm>
#define MAXN 50010
using namespace std;

struct SplayTree
{
	int ch[2], father;
	int siz, key, mx, lazy;
	bool rev;
};

SplayTree tree[MAXN];
int n, T, opt, l, r, x;
int root, siz;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void Push_Up(int x)
{
	int l = tree[x].ch[0], r = tree[x].ch[1];
	tree[x].mx = mymax(mymax(tree[l].mx, tree[r].mx), tree[x].key);
	tree[x].siz = tree[l].siz + tree[r].siz + 1;
	return ;
}

inline void Push_Down(int x)
{
	int l = tree[x].ch[0], r = tree[x].ch[1];
	if (tree[x].lazy)
	{
		if (l)
		{
			tree[l].key += tree[x].lazy;
			tree[l].mx += tree[x].lazy;
			tree[l].lazy += tree[x].lazy;
		}
		if (r)
		{
			tree[r].key += tree[x].lazy;
			tree[r].mx += tree[x].lazy;
			tree[r].lazy += tree[x].lazy;
		}
		tree[x].lazy = 0;
	}
	if (tree[x].rev)
	{
		tree[x].rev = false;
		tree[l].rev ^= 1;
		tree[r].rev ^= 1;
		swap(tree[x].ch[0], tree[x].ch[1]);
	}
	return ;
}

inline void Rotate(int x, int &k)
{
	int y = tree[x].father, z = tree[y].father, l, r;
	if (tree[y].ch[0] == x) l = 0;
	else l = 1;
	r = l ^ 1;
	if (y == k) k = x;
	else
	{
		if (tree[z].ch[0] == y) tree[z].ch[0] = x;
		else tree[z].ch[1] = x;
	}
	tree[x].father = z;
	tree[y].father = x;
	tree[tree[x].ch[r]].father = y;
	tree[y].ch[l] = tree[x].ch[r];
	tree[x].ch[r] = y;
	Push_Up(y);
	Push_Up(x);
	return ;
}

inline void Splay(int x, int &k)
{
	while (x != k)
	{
		int y = tree[x].father, z = tree[y].father;
		if (y != k)
		{
			if (tree[y].ch[0] == x ^ tree[z].ch[0] == y) Rotate(x, k);
			else Rotate(y, k);
		}
		Rotate(x, k);
	}
	return ;
}

inline void add(int &x, int f, int v, bool way)
{
	if (!x)
	{
		x = ++siz;
		tree[x].father = f;
		tree[x].key = v;
		tree[x].siz = 1;
		tree[f].ch[way] = x;
		tree[x].rev = false;
		Splay(x, root);
		return ;
	}
	if (v < tree[x].key) add(tree[x].ch[0], x, v, 0);
	else add(tree[x].ch[1], x, v, 1);
	Push_Up(x);
	return ;
}

inline int select(int x, int v)
{
	Push_Down(x);
	int l = tree[x].ch[0], r = tree[x].ch[1];
	if (tree[l].siz + 1 == v) return x;
	else if (tree[l].siz >= v) return select(l, v);
	else return select(r, v - tree[l].siz - 1);
}

inline void Add(int l, int r, int v)
{
	int x = select(root, l), y = select(root, r + 2);
	Splay(x, root);
	Splay(y, tree[x].ch[1]);
	int z = tree[y].ch[0];
	tree[z].lazy += v;
	tree[z].mx += v;
	tree[z].key += v;
	return ;
}

inline void Reverse(int l, int r)
{
	int x = select(root, l), y = select(root, r + 2);
	Splay(x, root);
	Splay(y, tree[x].ch[1]);
	int z = tree[y].ch[0];
	tree[z].rev ^= 1;
	return ;
}

inline int Get_max(int l, int r)
{
	int x = select(root, l), y = select(root, r + 2);
	Splay(x, root);
	Splay(y, tree[x].ch[1]);
	int z = tree[y].ch[0];
	return tree[z].mx;
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
	tree[0].mx = -0x7f7f7f7f;
	for (int i = 1; i <= n + 2; i++) add(root, 0, 0, 0);
	while (T--)
	{
		read(opt);
		if (opt == 1)
		{
			read(l);
			read(r);
			read(x);
			Add(l, r, x);
		}
		else if (opt == 2)
		{
			read(l);
			read(r);
			Reverse(l, r);
		}
		else
		{
			read(l);
			read(r);
			printf("%d\n", Get_max(l, r));
		}
	}
	return 0;
}
