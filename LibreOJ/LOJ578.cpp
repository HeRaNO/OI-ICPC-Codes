//By using Splay, you can pass all the test points!
//Code by HeRaNO

#include <cstdio>
#include <algorithm>
#define MAXN 100010
#define LC(x) tree[(x)].ch[0]
#define RC(x) tree[(x)].ch[1]
using namespace std;

struct SplayTree
{
	int ch[2], f, siz;
	bool rev;
	long long lazy, w, sw;
	SplayTree() {}
	SplayTree(int _f, long long _w):
		f(_f), siz(1), w(_w), rev(false), lazy(0LL), sw(_w)
	{
		ch[0] = ch[1] = 0;
	}
};

SplayTree tree[MAXN];
char opt[3];
int n, T, root, top, l, r;
long long w[MAXN], all, v;
double p[MAXN];

inline void Push_Up(int x)
{
	tree[x].siz = tree[LC(x)].siz + tree[RC(x)].siz + 1;
	tree[x].sw = tree[LC(x)].sw + tree[RC(x)].sw + tree[x].w;
	return ;
}

inline void Push_Down(int x)
{
	if (tree[x].rev)
	{
		tree[LC(x)].rev ^= 1;
		tree[RC(x)].rev ^= 1;
		tree[x].rev = false;
		swap(LC(x), RC(x));
	}
	if (tree[x].lazy != 0)
	{
		tree[LC(x)].w += tree[x].lazy;
		tree[LC(x)].lazy += tree[x].lazy;
		tree[LC(x)].sw += (long long)tree[LC(x)].siz * tree[x].lazy;
		tree[RC(x)].w += tree[x].lazy;
		tree[RC(x)].lazy += tree[x].lazy;
		tree[RC(x)].sw += (long long)tree[RC(x)].siz * tree[x].lazy;
		tree[x].lazy = 0LL;
	}
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

inline int find(int k)
{
	int x = root, lsiz = 0;
	while (x)
	{
		Push_Down(x);
		int t = lsiz + tree[LC(x)].siz;
		if (k <= t) x = LC(x);
		else if (k <= t + 1) return x;
		else lsiz = t + 1, x = RC(x);
	}
	return -1;
}

inline int BuildTree(int l, int r, int f)
{
	if (l > r) return 0;
	int pos = ++top, m = l + r >> 1;
	tree[pos] = SplayTree(f, w[m]);
	if (l == r) return pos;
	LC(pos) = BuildTree(l, m - 1, pos);
	RC(pos) = BuildTree(m + 1, r, pos);
	Push_Up(pos);
	return pos;
}

inline void add(int l, int r, long long v)
{
	int x = find(l), y = find(r + 2);
	Splay(x, root);
	Splay(y, RC(x));
	tree[LC(y)].lazy += v;
	tree[LC(y)].w += v;
	tree[LC(y)].sw += (long long)tree[LC(y)].siz * v;
	return ;
}

inline void reverse(int l, int r)
{
	int x = find(l), y = find(r + 2);
	Splay(x, root);
	Splay(y, RC(x));
	tree[LC(y)].rev ^= 1;
	return ;
}

inline int query(long long all)
{
	int l = 1, r = n;
	while (l != r)
	{
		int mid = l + r >> 1;
		int x = find(l), y = find(mid + 2);
		Splay(x, root);
		Splay(y, RC(x));
		if (tree[LC(y)].sw > all) r = mid;
		else
		{
			all -= tree[LC(y)].sw;
			l = mid + 1;
		}
	}
	return l;
}

int main()
{
	//freopen("pigeon.in","r",stdin);freopen("pigeon.out","w",stdout);
	scanf("%d%d", &n, &T);
	w[1] = w[n + 2] = 0;
	for (int i = 1; i <= n; i++) scanf("%lld", &w[i + 1]), all += w[i + 1], w[i + 1] <<= 1;
	for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
	root = BuildTree(1, n + 2, 0);
	while (T--)
	{
		scanf("%s", opt);
		if (opt[0] == 'A')
		{
			scanf("%d%d%lld", &l, &r, &v);
			all += (long long)(r - l + 1) * v;
			add(l, r, v * 2LL);
		}
		else if (opt[0] == 'B')
		{
			scanf("%d%d", &l, &r);
			if (l < r)
			{
				reverse(l, r);
				reverse(l, r - 1);
			}
			else
			{
				reverse(r, l);
				reverse(r + 1, l);
			}
		}
		else printf("%.3lf\n", p[query(all)]);
	}
	return 0;
}