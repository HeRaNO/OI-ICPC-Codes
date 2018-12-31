#include <cstdio>
#define MAXN 300010
#define LC(x) tree[(x)].ch[0]
#define RC(x) tree[(x)].ch[1]
using namespace std;

struct SplayTree
{
	int ch[2], f, siz, key, cnt;
	SplayTree() {}
	SplayTree(int _f, int _v): f(_f), siz(1), key(_v), cnt(1)
	{
		ch[0] = ch[1] = 0;
	}
};

SplayTree tree[MAXN];
int T, opt, x, root, siz, ans;

inline void Push_Up(int x)
{
	//Something else
	tree[x].siz = tree[LC(x)].siz + tree[RC(x)].siz + tree[x].cnt;
	return ;
}

inline void Push_Down(int x)
{
	//Something else
	return ;
}

inline void Rotate(int x, int &k)
{
	int y = tree[x].f, z = tree[y].f, l = RC(y) == x, r = l ^ 1;
	if (y == k) k = x;
	else tree[z].ch[RC(z) == y] = x;
	tree[x].f = z;
	tree[y].f = x;
	tree[tree[x].ch[r]].f = y;
	tree[y].ch[l] = tree[x].ch[r];
	tree[x].ch[r] = y;
	Push_Up(y);
	Push_Up(x);
	return ;
}

inline void Splay(int x, int &k)
{
	int y, z;
	while (x != k)
	{
		y = tree[x].f;
		z = tree[y].f;
		if (y != k)
		{
			if (LC(z) == y ^ LC(y) == x) Rotate(x, k);
			else Rotate(y, k);
		}
		Rotate(x, k);
	}
	return ;
}

inline void add(int &x, int v, int fa)
{
	if (!x)
	{
		tree[x = ++siz] = SplayTree(fa, v);
		Splay(x, root);
		return ;
	}
	if (tree[x].key == v) tree[x].siz++, tree[x].cnt++, Splay(x, root);
	else if (v < tree[x].key) add(LC(x), v, x);
	else add(RC(x), v, x);
	return ;
}

inline int prec(int x, int v)
{
	int k = -1;
	while (x)
	{
		if (v > tree[x].key) k = x;
		x = tree[x].ch[v > tree[x].key];
	}
	return k;
}

inline int succ(int x, int v)
{
	int k = -1;
	while (x)
	{
		if (v < tree[x].key) k = x;
		x = tree[x].ch[v >= tree[x].key];
	}
	return k;
}

inline void del(int x, int v)
{
	if (!x) return ;
	if (tree[x].key == v)
	{
		if (tree[x].cnt > 1) tree[x].cnt--, tree[x].siz--, Splay(x, root);
		else
		{
			int x1 = prec(root, v), x2 = succ(root, v);
			if (~x1 && ~x2)
			{
				Splay(x1, root);
				Splay(x2, RC(x1));
				LC(x2) = 0;
				Push_Up(x2);
				Splay(x2, root);
			}
			else if (!~x1 && !~x2) root = 0;
			else if (!~x1)
			{
				Splay(x2, root);
				LC(x2) = 0;
				Push_Up(x2);
			}
			else
			{
				Splay(x1, root);
				RC(x1) = 0;
				Push_Up(x1);
			}
		}
	}
	else if (v < tree[x].key) del(LC(x), v);
	else del(RC(x), v);
	return ;
}

inline int getrank(int x, int v)
{
	if (!x) return 0;
	if (v < tree[x].key) return getrank(LC(x), v);
	else if (tree[x].key == v) return tree[LC(x)].siz;
	else return getrank(RC(x), v) + tree[LC(x)].siz + tree[x].cnt;
}

inline int select(int x, int v)
{
	if (!x) return 0;
	if (tree[LC(x)].siz >= v) return select(LC(x), v);
	else if (tree[LC(x)].siz < v && v <= tree[LC(x)].siz + tree[x].cnt) return tree[x].key;
	else return select(RC(x), v - tree[LC(x)].siz - tree[x].cnt);
}

inline void read(int &x)
{
	x = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	if (f) x = -x;
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		read(opt);
		read(x);
		if (opt == 0) add(root, x, 0);
		else if (opt == 1) del(root, x);
		else if (opt == 2) printf("%d\n", select(root, x));
		else if (opt == 3) printf("%d\n", getrank(root, x));
		else if (opt == 4)
		{
			ans = prec(root, x);
			printf("%d\n", !~ans ? ans : tree[ans].key);
		}
		else
		{
			ans = succ(root, x);
			printf("%d\n", !~ans ? ans : tree[ans].key);
		}
	}
	return 0;
}