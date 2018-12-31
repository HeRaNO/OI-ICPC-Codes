#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1100
#define MAXM 20000
using namespace std;

struct Segment
{
	int l, r, len;
};

struct link
{
	int to, val, flow, nxt;
};

Segment a[MAXN >> 1];
link e[MAXM << 1];
int head[MAXN], cnt = 1;
int n, m, k, S, T, ans;
int dis[MAXN], from[MAXN], f[MAXN];
bool vis[MAXN];
pair <int, int *> b[MAXN];
queue <int> q;

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
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	//freopen("interv.in","r",stdin);freopen("interv.out","w",stdout);
	read(n);
	read(k);
	for (int i = 1; i <= n; i++)
	{
		read(a[i].l);
		read(a[i].r);
		a[i].len = a[i].r - a[i].l;
		b[(i << 1) - 1] = make_pair(a[i].l, &a[i].l);
		b[i << 1] = make_pair(a[i].r, &a[i].r);
	}
	sort(b + 1, b + (n << 1) + 1);
	for (int i = 1; i <= n << 1; i++)
	{
		if (i == 1 || b[i].first != b[i - 1].first) m++;
		*b[i].second = m;
	}
	S = 0;
	T = m + 1;
	add(S, 1, 0, k);
	for (int i = 1; i < m; i++) add(i, i + 1, 0, ~(1 << 31));
	for (int i = 1; i <= n; i++) add(a[i].l, a[i].r, a[i].len, 1);
	add(m, T, 0, k);
	while (Edmonds_Karp());
	printf("%d\n", ans);
	return 0;
}