#include <bits/stdc++.h>
#define MAXN 100010
#define INF 1000000000000000000LL
#define sqr(x) (x)*(x)
using namespace std;

struct point
{
	long long x, y;
	inline long long Dis(const point &a)const
	{
		return sqr(x - a.x) + sqr(y - a.y);
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

struct KDTree
{
	int lch, rch;
	point P;
	long long mxx, mxy, mnx, mny;
	inline long long MinDis(const point &p)const
	{
		long long ans = 0;
		if (p.x < mnx || p.x > mxx) ans += min(sqr(p.x - mnx), sqr(mxx - p.x));
		if (p.y < mny || p.y > mxy) ans += min(sqr(p.y - mny), sqr(mxy - p.y));
		return ans;
	}
};

point p[MAXN], t;
KDTree tree[MAXN];
int n, T, top = 1;
long long ans = INF, res;

inline void Push_Up(int x, int y)
{
	tree[x].mxx = max(tree[x].mxx, tree[y].mxx);
	tree[x].mnx = min(tree[x].mnx, tree[y].mnx);
	tree[x].mxy = max(tree[x].mxy, tree[y].mxy);
	tree[x].mny = min(tree[x].mny, tree[y].mny);
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

inline void query(int u, point P)
{
	res = min(res, tree[u].P.Dis(P));
	long long ldis = tree[u].lch ? tree[tree[u].lch].MinDis(P) : INF;
	long long rdis = tree[u].rch ? tree[tree[u].rch].MinDis(P) : INF;
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

inline void read(long long &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10LL + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(p[i].x), read(p[i].y);
	Build_KDTree(1, 1, n, false);
	while (n--)
	{
		read(t.x);
		read(t.y);
		res = INF;
		query(1, t);
		ans = min(ans, res);
	}
	printf("%.3f\n", sqrt(ans));
	return 0;
}