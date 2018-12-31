#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define LC tree[x].lc
#define RC tree[x].rc
using namespace std;

struct Treap
{
	int lc, rc, siz, key, rnd;
	Treap() {}
	Treap(int _key): lc(0), rc(0), siz(1), key(_key), rnd(rand()) {}
};

struct link
{
	int to;
	long long val;
	int nxt;
};

link e[MAXN << 1];
Treap tree[MAXN];
int n, T, R, k, opt, u, v, w, p, s, root, siz;
int head[MAXN], cnt;
int LCAFather[MAXN][18];
long long LCADis[MAXN][18], ans;
int dfn[MAXN], seq[MAXN], _2pow[18], dep[MAXN];

inline void addedge(int u, int v, long long w)
{
	e[cnt] = (link)
	{
		v, w, head[u]
	};
	head[u] = cnt++;
	e[cnt] = (link)
	{
		u, w, head[v]
	};
	head[v] = cnt++;
}

inline void dfs(int x, int father, long long val, int deep)
{
	dfn[x] = ++R;
	seq[R] = x;
	LCAFather[x][0] = father;
	LCADis[x][0] = val;
	dep[x] = deep;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father) dfs(e[i].to, x, e[i].val, deep + 1);
	return ;
}

inline void LCA()
{
	for (int j = 1; j <= k; j++)
		for (int i = 1; i <= n; i++)
		{
			LCAFather[i][j] = LCAFather[LCAFather[i][j - 1]][j - 1];
			LCADis[i][j] = LCADis[i][j - 1] + LCADis[LCAFather[i][j - 1]][j - 1];
		}
	return ;
}

inline long long query(int u, int v)
{
	long long ans = 0LL;
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = k; ~i; i--)
		if (_2pow[i] <= dep[u] - dep[v])
		{
			ans += LCADis[u][i];
			u = LCAFather[u][i];
		}
	for (int i = k; ~i; i--)
		if (LCAFather[u][i] != LCAFather[v][i])
		{
			ans += LCADis[u][i] + LCADis[v][i];
			u = LCAFather[u][i];
			v = LCAFather[v][i];
		}
	if (u != v) ans += LCADis[u][0] + LCADis[v][0];
	return ans;
}

inline void Push_Up(int x)
{
	tree[x].siz = tree[LC].siz + tree[RC].siz + 1;
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
	if (v < tree[x].key)
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

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline int first(int &x)
{
	return !LC ? tree[x].key : first(LC);
}
inline int last(int &x)
{
	return !RC ? tree[x].key : last(RC);
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

inline int getL(int x)
{
	int p = prec(root, x);
	return p == 1 << 31 ? last(root) : p;
}

inline int getR(int x)
{
	int p = succ(root, x);
	return p == ~(1 << 31) ? first(root) : p;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '+')
		{
			x = -1;
			return ;
		}
		if (ch == '-')
			return ;
		if (ch == '?')
		{
			x = 1;
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	memset(head, -1, sizeof head);
	read(n);
	for (_2pow[0] = 1; _2pow[k] <= n; k++) _2pow[k + 1] = _2pow[k] << 1;
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		read(w);
		addedge(u, v, (long long)w);
	}
	dfs(1, 1, 0LL, 1);
	LCA();
	read(T);
	while (T--)
	{
		read(opt);
		if (!~opt)
		{
			read(u);
			add(root, dfn[u]);
			if (siz > 1)
			{
				p = getL(dfn[u]);
				s = getR(dfn[u]);
				ans -= query(seq[p], seq[s]);
				ans += query(seq[p], u) + query(u, seq[s]);
			}
		}
		else if (!opt)
		{
			read(u);
			if (siz > 1)
			{
				p = getL(dfn[u]);
				s = getR(dfn[u]);
				ans -= query(seq[p], u) + query(u, seq[s]);
				ans += query(seq[p], seq[s]);
			}
			del(root, dfn[u]);
		}
		else printf("%lld\n", ans >> 1);
	}
	return 0;
}