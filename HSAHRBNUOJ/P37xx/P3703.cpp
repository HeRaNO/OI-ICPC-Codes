#include <queue>
#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

inline long long sqr(long long a)
{
	return a * a;
}

struct point
{
	int x, y, pt;
	inline long long Dis(const point &p)const
	{
		return sqr(x - p.x) + sqr(y - p.y);
	}
};

struct result
{
	long long dis;
	int pt;
	inline bool operator < (const result &a)const
	{
		return dis == a.dis ? pt<a.pt: dis>a.dis;
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
inline long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

struct KDTree
{
	int ch[2], mxx, mnx, mxy, mny;
	point P;
	inline long long MaxDis(const point &x)const
	{
		long long dis = 0LL;
		dis += mymax(sqr(mxx - x.x), sqr(mnx - x.x));
		dis += mymax(sqr(mxy - x.y), sqr(mny - x.y));
		return dis;
	}
};

point p[MAXN], t;
KDTree tree[MAXN];
int n, T, m, top = 1;
priority_queue <result> q;

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
	if (l < mid)
	{
		tree[u].ch[0] = ++top;
		Build_KDTree(top, l, mid - 1, !D);
	}
	if (mid < r)
	{
		tree[u].ch[1] = ++top;
		Build_KDTree(top, mid + 1, r, !D);
	}
	if (tree[u].ch[0]) Push_Up(u, tree[u].ch[0]);
	if (tree[u].ch[1]) Push_Up(u, tree[u].ch[1]);
	return ;
}

inline void query(int u)
{
	if (!u) return ;
	long long ldis, rdis, d0 = t.Dis(tree[u].P);
	result it = (result)
	{
		d0, tree[u].P.pt
	};
	ldis = tree[tree[u].ch[0]].MaxDis(t);
	rdis = tree[tree[u].ch[1]].MaxDis(t);
	if (q.size() < m) q.push(it);
	else if (it < q.top())
	{
		q.pop();
		q.push(it);
	}
	if (ldis > rdis)
	{
		if (q.size() < m || ldis >= q.top().dis) query(tree[u].ch[0]);
		if (q.size() < m || rdis >= q.top().dis) query(tree[u].ch[1]);
	}
	else
	{
		if (q.size() < m || rdis >= q.top().dis) query(tree[u].ch[1]);
		if (q.size() < m || ldis >= q.top().dis) query(tree[u].ch[0]);
	}
	return ;
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
	x = f ? -x : x;
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(p[i].x), read(p[i].y), p[i].pt = i;
	Build_KDTree(1, 1, n, 0);
	read(T);
	while (T--)
	{
		read(t.x);
		read(t.y);
		read(m);
		query(1);
		printf("%d\n", q.top().pt);
		while (!q.empty()) q.pop();
	}
	return 0;
}