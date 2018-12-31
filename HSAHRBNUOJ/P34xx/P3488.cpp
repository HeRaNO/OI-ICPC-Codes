#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 251
using namespace std;

struct point
{
	long long x, y;
	long long Dis(const point &a)const
	{
		return (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y);
	}
};

struct plate
{
	int r, c;
	bool operator < (const plate &a)const
	{
		return r != a.r ? r<a.r: c>a.c;
	}
};

struct link
{
	int to, val, nxt;
};

struct node
{
	int d, u;
	bool operator < (const node &a)const
	{
		return d > a.d;
	}
};

link e[MAXN * MAXN * MAXN];
plate a[MAXN], disk[MAXN];
point p[MAXN];
int head[MAXN * MAXN], cnt;
int n, m, cas, W, x, y, top, S, T, ans;
int dis[MAXN * MAXN];
bool vis[MAXN * MAXN];
priority_queue <node> q;

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, head[u]
	};
	head[u] = cnt++;
}

inline int Dijkstra(int S, int T)
{
	memset(dis, 0x3f, sizeof dis);
	memset(vis, false, sizeof vis);
	q.push((node)
	{
		0, S
	});
	dis[S] = 0;
	while (!q.empty())
	{
		node x = q.top();
		q.pop();
		if (vis[x.u]) continue;
		vis[x.u] = true;
		for (int i = head[x.u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > dis[x.u] + e[i].val)
			{
				dis[e[i].to] = dis[x.u] + e[i].val;
				q.push((node)
				{
					dis[e[i].to], e[i].to
				});
			}
	}
	return dis[T];
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
	read(cas);
	while (cas--)
	{
		memset(head, -1, sizeof head);
		cnt = 0;
		read(n);
		read(m);
		read(W);
		T = n * m + 1;
		for (int i = 1; i <= n; i++)
		{
			read(x);
			read(y);
			p[i].x = x;
			p[i].y = y;
		}
		for (int i = 1; i <= m; i++) read(a[i].r), read(a[i].c);
		sort(a + 1, a + m + 1);
		top = 0;
		for (int i = 1; i <= m; i++)
		{
			while (top && a[i].c < disk[top].c) top--;
			disk[++top] = a[i];
		}
		m = top;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (disk[j].r >= p[i].y) add(S, (i - 1)*m + j, disk[j].c);
				if (disk[j].r + p[i].y >= W) add((i - 1)*m + j, T, 0);
				if (j < m) add((i - 1)*m + j, (i - 1)*m + j + 1, disk[j + 1].c - disk[j].c);
			}
			for (int j = 1; j <= n; j++)
				if (j != i)
				{
					long long dist = p[i].Dis(p[j]);
					int x = m + 1;
					for (int k = 1; k <= m; k++)
					{
						while (x > 1 && 1LL * (disk[k].r + disk[x - 1].r) * (disk[k].r + disk[x - 1].r) >= dist) --x;
						if (x <= m) add((i - 1)*m + k, (j - 1)*m + x, disk[x].c);
					}
				}
		}
		ans = Dijkstra(S, T);
		if (ans != 0x3f3f3f3f) printf("%d\n", ans);
		else puts("impossible");
	}
	return 0;
}