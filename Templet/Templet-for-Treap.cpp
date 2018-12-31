#include <cstdio>
#include <cstdlib>
#define MAXN 100010
#define LC tree[x].lc
#define RC tree[x].rc
using namespace std;

struct Treap
{
	int lc, rc, siz, key, cnt, rnd;
	Treap() {}
	Treap(int _key): lc(0), rc(0), siz(1), key(_key), cnt(1), rnd(rand()/**rand()*/) {}
};

Treap tree[MAXN];
int T, opt, x, root, siz;

inline void Push_Up(int x)
{
	//Something else
	tree[x].siz = tree[LC].siz + tree[RC].siz + tree[x].cnt;
	return ;
}

inline void Push_Down(int x)
{
	//Something else
	return ;
}

inline void rturn(int &x)
{
	int k = LC;
	LC = tree[k].rc;
	tree[k].rc = x;
	Push_Up(x);
	Push_Up(k);
	x = k;
	return ;
}

inline void lturn(int &x)
{
	int k = RC;
	RC = tree[k].lc;
	tree[k].lc = x;
	Push_Up(x);
	Push_Up(k);
	x = k;
	return ;
}

inline void add(int &x, int v)
{
	if (!x)
	{
		tree[x = ++siz] = Treap(v);
		return ;
	}
	tree[x].siz++;
	if (tree[x].key == v) tree[x].cnt++;
	else if (v < tree[x].key)
	{
		add(LC, v);
		if (tree[LC].rnd < tree[x].rnd) rturn(x);
	}
	else
	{
		add(RC, v);
		if (tree[RC].rnd < tree[x].rnd) lturn(x);
	}
	return ;
}

inline void del(int &x, int v)
{
	if (!x) return ;
	tree[x].siz--;
	if (tree[x].key == v)
	{
		if (tree[x].cnt > 1)
		{
			tree[x].cnt--;
			return ;
		}
		if (!LC || !RC) x = LC + RC;
		else if (tree[LC].rnd < tree[RC].rnd)
		{
			rturn(x);
			del(x, v);
		}
		else
		{
			lturn(x);
			del(x, v);
		}
	}
	else if (v < tree[x].key) del(LC, v);
	else del(RC, v);
	return ;
}

inline bool exist(int &x, int v)
{
	if (!x) return false;
	if (v < tree[x].key) return exist(LC, v);
	else return (tree[x].key == v) || exist(RC, v);
}

inline int getrank(int &x, int v)
{
	if (!x) return 0;
	if (tree[x].key == v) return tree[LC].siz + 1;
	else if (v > tree[x].key) return tree[LC].siz + tree[x].cnt + getrank(RC, v);
	else return getrank(LC, v);
}

inline int select(int &x, int v)
{
	if (!x) return 0;
	if (v <= tree[LC].siz) return select(LC, v);
	else if (v > tree[LC].siz + tree[x].cnt) return select(RC, v - tree[LC].siz - tree[x].cnt);
	else return tree[x].key;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline int prec(int &x, int v)
{
	if (!x) return 1 << 31;
	if (v <= tree[x].key) return prec(LC, v);
	else return mymax(tree[x].key, prec(RC, v));
}

inline int succ(int &x, int v)
{
	if (!x) return ~(1 << 31);
	if (v < tree[x].key) return mymin(tree[x].key, succ(LC, v));
	else return succ(RC, v);
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
		if (opt == 1) add(root, x);
		else if (opt == 2)
		{
			if (exist(root, x)) del(root, x);
		}
		else if (opt == 3) printf("%d\n", getrank(root, x));
		else if (opt == 4) printf("%d\n", select(root, x));
		else if (opt == 5) printf("%d\n", prec(root, x));
		else printf("%d\n", succ(root, x));
	}
	return 0;
}