#include <cstdio>
#include <algorithm>
#define MAXN 1000010
#define INF ~(1<<31)
using namespace std;

struct point
{
	int x, y;
	inline int myabs(const int x)const
	{
		return x > 0 ? x : -x;
	}
	inline int Dis(const point &a)const
	{
		return myabs(x - a.x) + myabs(y - a.y);
	}
};

bool cmpx(point a, point b)
{
	return a.x < b.x;
}
bool cmpy(point a, point b)
{
	return a.y < b.y;
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

struct KDTree
{
	int lch, rch;
	point P;
	int mxx, mxy, mnx, mny;
	inline int MinDis(const point &p)const
	{
		int ans = 0;
		if (p.x < mnx) ans += mnx - p.x;
		if (p.x > mxx) ans += p.x - mxx;
		if (p.y < mny) ans += mny - p.y;
		if (p.y > mxy) ans += p.y - mxy;
		return ans;
	}
};

point p[MAXN >> 1], t;
KDTree tree[MAXN];
int n, T, x, top = 1, res, opt;

inline void Push_Up(int x, int y)
{
	tree[x].mxx = mymax(tree[x].mxx, tree[y].mxx);
	tree[x].mnx = mymin(tree[x].mnx, tree[y].mnx);
	tree[x].mxy = mymax(tree[x].mxy, tree[y].mxy);
	tree[x].mny = mymin(tree[x].mny, tree[y].mny);
	return ;
}

inline void Build_KDTree(int u, int l, int r, bool D)
{
	int mid = l + r >> 1;
	nth_element(p + l, p + mid, p + r + 1, D ? cmpy : cmpx);
	tree[u].P = p[mid];
	tree[u].mxx = tree[u].mnx = p[mid].x;
	tree[u].mxy = tree[u].mny = p[mid].y;
	if (l <= mid - 1)
	{
		tree[u].lch = ++top;
		Build_KDTree(top, l, mid - 1, !D);
	}
	if (mid + 1 <= r)
	{
		tree[u].rch = ++top;
		Build_KDTree(top, mid + 1, r, !D);
	}
	if (tree[u].lch) Push_Up(u, tree[u].lch);
	if (tree[u].rch) Push_Up(u, tree[u].rch);
	return ;
}

inline void add(int u, point P, bool D, int father, bool way)
{
	if (!u)
	{
		top++;
		if (!way) tree[father].lch = top;
		else tree[father].rch = top;
		tree[top].P = P;
		tree[top].mxx = tree[top].mnx = P.x;
		tree[top].mxy = tree[top].mny = P.y;
		return ;
	}
	if ((D ? cmpy : cmpx)(P, tree[u].P))
	{
		add(tree[u].lch, P, !D, u, false);
		Push_Up(u, tree[u].lch);
	}
	else
	{
		add(tree[u].rch, P, !D, u, true);
		Push_Up(u, tree[u].rch);
	}
	return ;
}

inline void query(int u, point P)
{
	res = mymin(res, tree[u].P.Dis(P));
	int ldis = tree[u].lch ? tree[tree[u].lch].MinDis(P) : INF;
	int rdis = tree[u].rch ? tree[tree[u].rch].MinDis(P) : INF;
	if (ldis < rdis)
	{
		if (tree[u].lch && res > ldis) query(tree[u].lch, P);
		if (tree[u].rch && res > rdis) query(tree[u].rch, P);
	}
	else
	{
		if (tree[u].rch && res > rdis) query(tree[u].rch, P);
		if (tree[u].lch && res > ldis) query(tree[u].lch, P);
	}
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	//freopen("angel.in","r",stdin);freopen("angel.out","w",stdout);
	read(n);
	read(T);
	for (int i = 1; i <= n; i++) read(p[i].x), read(p[i].y);
	Build_KDTree(1, 1, n, false);
	while (T--)
	{
		read(opt);
		read(t.x);
		read(t.y);
		opt--;
		if (!opt) add(1, t, false, 0, false);
		else
		{
			res = INF;
			query(1, t);
			printf("%d\n", res);
		}
	}
	return 0;
}