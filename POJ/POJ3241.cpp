#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct link
{
	int from, to;
	long long val;
};

struct point
{
	long long x, y;
	int id;
};

link e[MAXN << 2];
point p[MAXN];
long long c_dis[MAXN];
int c_id[MAXN];
int father[MAXN];
long long pos[MAXN], val[MAXN];
int n, k, cnt, m;
pair <long long, long long *> b[MAXN];

inline int lowbit(int x)
{
	return x & -x;
}
inline int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}
inline bool cmp_point(point a, point b)
{
	return a.x != b.x ? a.x < b.x : a.y < b.y;
}
inline bool cmp_link(link a, link b)
{
	return a.val < b.val;
}

inline void Discretization()
{
	m = 0;
	for (int i = 1; i <= n; i++)
	{
		pos[i] = p[i].y - p[i].x;
		val[i] = p[i].y + p[i].x;
		b[i].first = pos[i];
		b[i].second = &pos[i];
	}
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (b[i].first != b[i - 1].first) m++;
		*b[i].second = m;
	}
	return ;
}

inline void query(int id, long long pos, long long val)
{
	int tid = -1;
	long long res = ~(1LL << 63);
	for (; pos <= m; pos += lowbit(pos))
		if (res > c_dis[pos])
		{
			res = c_dis[pos];
			tid = c_id[pos];
		}
	if (~tid) e[++cnt] = (link)
	{
		id, tid, res - val
	};
	return ;
}

inline void modify(int id, long long pos, long long val)
{
	for (; pos; pos -= lowbit(pos))
		if (val < c_dis[pos])
		{
			c_dis[pos] = val;
			c_id[pos] = id;
		}
	return ;
}

inline void Build_Spanning_Tree()
{
	for (int i = 1; i <= n; i++) c_dis[i] = ~(1LL << 63);
	sort(p + 1, p + n + 1, cmp_point);
	Discretization();
	for (int i = n; i; i--)
	{
		query(p[i].id, pos[i], val[i]);
		modify(p[i].id, pos[i], val[i]);
	}
	return ;
}

inline int Kruskal()
{
	sort(e + 1, e + cnt + 1, cmp_link);
	int spanning_tree = 0;
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= cnt; i++)
	{
		int x = getfather(e[i].from), y = getfather(e[i].to);
		if (x != y)
		{
			father[y] = x;
			spanning_tree++;
			if (spanning_tree == n - k) return e[i].val;
		}
	}
	return -1;
}

inline int solve()
{
	cnt = 0;
	Build_Spanning_Tree();
	for (int i = 1; i <= n; i++) swap(p[i].x, p[i].y);
	Build_Spanning_Tree();
	for (int i = 1; i <= n; i++) p[i].y = -p[i].y;
	Build_Spanning_Tree();
	for (int i = 1; i <= n; i++) swap(p[i].x, p[i].y);
	Build_Spanning_Tree();
	return Kruskal();
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

inline void read(long long &x)
{
	x = 0;
	long long f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1LL;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10LL + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	read(n);
	read(k);
	for (int i = 1; i <= n; i++)
	{
		read(p[i].x);
		read(p[i].y);
		p[i].id = i;
	}
	printf("%d\n", solve());
	return 0;
}