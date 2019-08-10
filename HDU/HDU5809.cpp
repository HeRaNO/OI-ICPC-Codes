#include <bits/stdc++.h>
#define MAXN 100010
#define sqr(x) (x)*(x)
using namespace std;

struct point
{
	long long x, y; int p;
	inline long long Dis(const point &a)const
	{
		return sqr(x - a.x) + sqr(y - a.y);
	}
	bool operator < (const point &a)const{
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
	bool operator == (const point &a)const{
		return (x == a.x) && (y == a.y);
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
	inline long long MinDis(const point &p)const{
		long long ans = 0;
		if (p.x < mnx || p.x > mxx) ans += min(sqr(p.x - mnx), sqr(mxx - p.x));
		if (p.y < mny || p.y > mxy) ans += min(sqr(p.y - mny), sqr(mxy - p.y));
		return ans;
	}
};

point p[MAXN], resP;
KDTree tree[MAXN];
int n, T, top, f[MAXN];
long long res;

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
	tree[u].lch = tree[u].rch = 0;
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
	long long q = tree[u].P.Dis(P);
	if (q)
	{
		if (q < res)
		{
			res = q;
			resP = tree[u].P;
		}
		else if (q == res && tree[u].P < resP)
		{
			resP = tree[u].P;
		}
	}
	long long ldis = tree[u].lch ? tree[tree[u].lch].MinDis(P) : ~(1LL<<63);
	long long rdis = tree[u].rch ? tree[tree[u].rch].MinDis(P) : ~(1LL<<63);
	if (ldis < rdis)
	{
		if (tree[u].lch && res >= ldis) query(tree[u].lch, P);
		if (tree[u].rch && res >= rdis) query(tree[u].rch, P);
	}
	else
	{
		if (tree[u].rch && res >= rdis) query(tree[u].rch, P);
		if (tree[u].lch && res >= ldis) query(tree[u].lch, P);
	}
	return ;
}

inline int getf(int x){return x == f[x] ? x : f[x] = getf(f[x]);}

inline void Merge(int x, int y)
{
	int fx = getf(x), fy = getf(y);
	if (fx != fy) f[fy] = fx;
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
	x = 0; char ch = getchar(); bool f=false;
	while (ch < '0' || ch > '9') {if (ch == '-') f = true; ch = getchar();}
	while (ch >= '0' && ch <= '9') x = x * 10LL + ch - '0', ch = getchar();
	if (f) x = -x; return ;
}

int main()
{
	int TT; read(TT);
	for (int cas = 1; cas <= TT; cas++)
	{
		printf("Case #%d:\n", cas);
		read(n); read(T); top = 1;
		for (int i = 1; i <= n; i++) read(p[i].x), read(p[i].y), p[i].p = i, f[i] = i;
		Build_KDTree(1, 1, n, false);
		for (int i = 1; i <= n; i++)
		{
			res = ~(1LL<<63);
			query(1, p[i]);
			Merge(p[i].p, resP.p);
		}
		while (T--)
		{
			int x, y;
			read(x); read(y);
			if (getf(x) != getf(y)) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}