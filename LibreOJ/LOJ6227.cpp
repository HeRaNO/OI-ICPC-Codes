#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
#define MAXM 100000
using namespace std;

struct link
{
	int to, val, flow, nxt;
};

struct point
{
	int x, y;
	point() {}
	point(int _, int __): x(_), y(__) {}
	bool operator < (const point &a)const
	{
		if (x == a.x) return y < a.y;
		if (y == a.y) return x < a.x;
		return x < a.x && y < a.y;
	}
} p[MAXN][2];

link e[MAXM];
int head[MAXN], cnt = 1;
int n, m, k, a, b, c, d, S, T, pt, ans;
int dis[MAXN], from[MAXN], f[MAXN];
long long len[MAXN];
bool vis[MAXN];
queue <int> q;
pair <int, int *> bp[MAXN << 1];

inline long long sqr(long long x)
{
	return x * x;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int c, int f)
{
	e[++cnt] = (link)
	{
		v, c, f, head[u]
	};
	head[u] = cnt;
	e[++cnt] = (link)
	{
		u, -c, 0, head[v]
	};
	head[v] = cnt;
}

inline bool Edmonds_Karp()
{
	for (int i = S; i <= T; dis[i] = 1 << 31, i++);
	memset(vis, false, sizeof vis);
	q.push(S);
	vis[S] = true;
	dis[S] = 0;
	f[S] = ~(1 << 31);
	f[T] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i; i = e[i].nxt)
			if (dis[e[i].to] < dis[u] + e[i].val && e[i].flow)
			{
				dis[e[i].to] = dis[u] + e[i].val;
				f[e[i].to] = mymin(e[i].flow, f[u]);
				from[e[i].to] = i;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	if (!f[T]) return false;
	ans += dis[T] * f[T];
	for (int i = from[T]; i; i = from[e[i ^ 1].to])
		e[i].flow -= f[T], e[i ^ 1].flow += f[T];
	return true;
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
	read(k);
	for (int i = 1; i <= n; i++)
	{
		read(a);
		read(b);
		read(c);
		read(d);
		len[i] = sqrt(sqr(a - c) + sqr(b - d));
		p[i][0] = point(a, b);
		p[i][1] = point(c, d);
		if (p[i][1] < p[i][0]) swap(p[i][0], p[i][1]);
		a = p[i][0].x << 1;
		b = p[i][1].x << 1;
		if (a == b) --a;
		bp[++pt] = make_pair(a, &p[i][0].x);
		bp[++pt] = make_pair(b, &p[i][1].x);
	}
	sort(bp + 1, bp + pt + 1);
	for (int i = 1; i <= pt; i++)
	{
		if (bp[i].first != bp[i - 1].first) m++;
		*bp[i].second = m;
	}
	S = 0;
	T = pt + 1;
	add(S, 1, 0, k);
	add(pt, T, 0, k);
	for (int i = 1; i < pt; i++) add(i, i + 1, 0, ~(1 << 31));
	for (int i = 1; i <= n; i++)
		add(p[i][0].x, p[i][1].x, len[i], 1);
	while (Edmonds_Karp());
	printf("%d\n", ans);
	return 0;
}