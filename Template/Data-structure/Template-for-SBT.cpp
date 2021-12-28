#include <cstdio>
#define MAXN 100010
#define LC tree[x].lc
#define RC tree[x].rc
using namespace std;

struct SBT
{
	int lc, rc, siz, key, cnt;
	SBT() {}
	SBT(int _key): lc(0), rc(0), siz(1), key(_key), cnt(1) {}
};

SBT tree[MAXN];
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

inline void Maintain(int &x, bool f)
{
	if (!f)
	{
		if (tree[tree[LC].lc].siz > tree[RC].siz) rturn(x);
		else if (tree[tree[RC].lc].siz > tree[RC].siz) lturn(x), rturn(x);
		else return ;
	}
	else
	{
		if (tree[tree[RC].rc].siz > tree[LC].siz) lturn(x);
		else if (tree[tree[LC].rc].siz > tree[LC].siz) rturn(x), lturn(x);
		else return ;
	}
	Maintain(LC, false);
	Maintain(RC, true);
	Maintain(x, false);
	Maintain(x, true);
	return ;
}

inline void add(int &x, int v)
{
	if (!x)
	{
		tree[x = ++siz] = SBT(v);
		return ;
	}
	tree[x].siz++;
	if (tree[x].key == v) tree[x].cnt++;
	else
	{
		if (tree[x].key > v) add(LC, v);
		else add(RC, v);
		Maintain(x, v >= tree[x].key);
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
		if (!LC && !RC) x = 0;
		else if (!LC || !RC) x = LC + RC;
		else
		{
			int t = RC;
			while (tree[t].lc) t = tree[t].lc;
			tree[x].key = tree[t].key;
			del(RC, tree[t].key);
		}
	}
	else if (v < tree[x].key) del(LC, v);
	else del(RC, v);
}

inline int select(int &x, int v)
{
	if (!x) return -1;
	if (v <= tree[LC].siz) return select(LC, v);
	else if (v > tree[LC].siz + tree[x].cnt) return select(RC, v - tree[LC].siz - tree[x].cnt);
	else return tree[x].key;
}

inline bool exist(int &x, int v)
{
	if (!x) return false;
	if (v < tree[x].key) return exist(LC, v);
	else return (tree[x].key == v) || exist(RC, v);
}

inline int getrank(int &x, int v)
{
	if (!x) return -1;
	if (v < tree[x].key) return getrank(LC, v);
	else if (v > tree[x].key) return tree[LC].siz + tree[x].cnt + getrank(RC, v);
	else return tree[LC].siz + 1;
}

inline int prec(int &x, int v)
{
	if (!x) return v;
	if (v <= tree[x].key) return prec(LC, v);
	else
	{
		int r = prec(RC, v);
		if (r == v) return tree[x].key;
		else return r;
	}
}

inline int succ(int &x, int v)
{
	if (!x) return v;
	if (tree[x].key <= v) return succ(RC, v);
	else
	{
		int r = succ(LC, v);
		if (r == v) return tree[x].key;
		else return r;
	}
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
		else if (opt == 2) del(root, x);
		else if (opt == 3) printf("%d\n", getrank(root, x));
		else if (opt == 4) printf("%d\n", select(root, x));
		else if (opt == 5) printf("%d\n", prec(root, x));
		else printf("%d\n", succ(root, x));
	}
	return 0;
}