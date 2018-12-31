#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 35
#define MAXM 1010
using namespace std;

struct link
{
	int to, flow, nxt;
};

struct milk
{
	int u, v, f, pt;
	milk() {}
	milk(int _u, int _v, int _f, int _pt): u(_u), v(_v), f(_f), pt(_pt) {}
	bool operator < (const milk &a)const
	{
		return f != a.f ? f > a.f : pt < a.pt;
	}
};

milk a[MAXM];
link e[MAXM << 1], bak[MAXM << 1];
int head[MAXN], cnt = 1;
int n, m, u, v, w, ans, now;
int dpt[MAXN], cut[MAXM];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int f)
{
	bak[++cnt] = (link)
	{
		v, f, head[u]
	};
	head[u] = cnt;
	bak[++cnt] = (link)
	{
		u, 0, head[v]
	};
	head[v] = cnt;
}

inline bool BFS()
{
	memset(dpt, -1, sizeof dpt);
	dpt[1] = 1;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nxt)
			if (e[i].flow && !~dpt[e[i].to])
			{
				dpt[e[i].to] = dpt[u] + 1;
				q.push(e[i].to);
			}
	}
	return dpt[n] != -1;
}

inline int Dinic(int x, int flow)
{
	int left = flow;
	if (x == n) return flow;
	for (int i = head[x]; i && left; i = e[i].nxt)
		if (e[i].flow && dpt[e[i].to] == dpt[x] + 1)
		{
			int t = Dinic(e[i].to, mymin(e[i].flow, left));
			e[i].flow -= t;
			e[i ^ 1].flow += t;
			left -= t;
		}
	if (left) dpt[x] = -1;
	return flow - left;
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
	read(n);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		read(w);
		add(u, v, w);
		a[i] = milk(u, v, w, i);
	}
	sort(a + 1, a + m + 1);
	memcpy(e, bak, sizeof bak);
	while (BFS()) ans += Dinic(1, ~(1 << 31));
	printf("%d ", ans);
	for (int i = 1; i <= m; i++)
	{
		now = 0;
		memcpy(e, bak, sizeof bak);
		for (int j = head[a[i].u]; j; j = e[j].nxt)
			if (e[j].to == a[i].v && e[j].flow == a[i].f)
			{
				e[j].flow = 0;
				break;
			}
		while (BFS()) now += Dinic(1, ~(1 << 31));
		if (now + a[i].f == ans)
		{
			cut[++cut[0]] = a[i].pt;
			for (int j = head[a[i].u]; j; j = bak[j].nxt)
				if (bak[j].to == a[i].v && bak[j].flow == a[i].f)
				{
					bak[j].flow = 0;
					break;
				}
			ans = now;
		}
	}
	sort(cut + 1, cut + cut[0] + 1);
	printf("%d\n", cut[0]);
	for (int i = 1; i <= cut[0]; i++) printf("%d\n", cut[i]);
	return 0;
}