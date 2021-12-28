#include <queue>
#include <cstdio>
#include <algorithm>
#define MAXN 50010
#define MAXM 10
#define MAXK 5
#define INF ~(1<<31)
#define sqr(x) (x)*(x)
using namespace std;

int K, D;

struct point
{
	int a[MAXK];
	inline int Dis(const point &p)const
	{
		int dis = 0;
		for (int i = 0; i < K; i++) dis += sqr(a[i] - p.a[i]);
		return dis;
	}
};

bool cmp(point x, point y)
{
	return x.a[D] < y.a[D];
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
	int ch[2], mx[MAXK], mn[MAXK];
	point P;
	inline int MinDis(const point &x)const
	{
		int dis = 0;
		for (int i = 0; i < K; i++)
			if (x.a[i] < mn[i] || x.a[i] > mx[i])
				dis += mymin(sqr(x.a[i] - mn[i]), sqr(mx[i] - x.a[i]));
		return dis;
	}
};

point p[MAXN], t, ans[MAXM];
KDTree tree[MAXN];
int n, T, m, top;
priority_queue <point> q;

bool operator <(point x, point y)
{
	return t.Dis(x) < t.Dis(y);
}

inline void Push_Up(int x, int y)
{
	for (int i = 0; i < K; i++)
	{
		tree[x].mx[i] = mymax(tree[x].mx[i], tree[y].mx[i]);
		tree[x].mn[i] = mymin(tree[x].mn[i], tree[y].mn[i]);
	}
	return ;
}

inline void Build_KDTree(int u, int l, int r, int d)
{
	D = d;
	int mid = l + r >> 1;
	nth_element(p + l, p + mid, p + r + 1, cmp);
	tree[u].P = p[mid];
	tree[u].ch[0] = tree[u].ch[1] = 0;
	for (int i = 0; i < K; i++) tree[u].mx[i] = tree[u].mn[i] = p[mid].a[i];
	if (l <= mid - 1)
	{
		tree[u].ch[0] = ++top;
		Build_KDTree(top, l, mid - 1, (d + 1) % K);
	}
	if (mid + 1 <= r)
	{
		tree[u].ch[1] = ++top;
		Build_KDTree(top, mid + 1, r, (d + 1) % K);
	}
	if (tree[u].ch[0]) Push_Up(u, tree[u].ch[0]);
	if (tree[u].ch[1]) Push_Up(u, tree[u].ch[1]);
	return ;
}

// The cloest M point
inline void query(int u)
{
	if (!u) return ;
	int d0 = t.Dis(tree[u].P), dis[2] = {INF, INF};
	if (q.size() < m) q.push(tree[u].P);
	else if (t.Dis(q.top()) > d0)
	{
		q.pop();
		q.push(tree[u].P);
	}
	if (tree[u].ch[0]) dis[0] = tree[tree[u].ch[0]].MinDis(t);
	if (tree[u].ch[1]) dis[1] = tree[tree[u].ch[1]].MinDis(t);
	int f = dis[0] > dis[1];
	if (q.size() < m || dis[f] < t.Dis(q.top())) query(tree[u].ch[f]);
	f ^= 1;
	if (q.size() < m || dis[f] < t.Dis(q.top())) query(tree[u].ch[f]);
	return ;
}

// Get the min
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

inline void read(int &x)
{
	x = 0;
	bool f = false;
	char ch;
	if ((ch = getchar()) == EOF)
	{
		x = -1;
		return ;
	}
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
	while (true)
	{
		read(n);
		if (!~n) break;
		read(K);
		top = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < K; j++)
				read(p[i].a[j]);
		Build_KDTree(1, 1, n, 0);
		read(T);
		while (T--)
		{
			for (int i = 0; i < K; i++) read(t.a[i]);
			read(m);
			zcnt = 0;
			query(1);
			for (int i = 0; !q.empty(); q.pop(), i++) ans[i] = q.top();
			printf("the closest %d points are:\n", m);
			for (int i = m - 1; ~i; i--)
				for (int j = 0; j < K; j++)
					printf("%d%c", ans[i].a[j], j == K - 1 ? '\n' : ' ');
		}
	}
	return 0;
}