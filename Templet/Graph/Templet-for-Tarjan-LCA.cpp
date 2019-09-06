#include <cstdio>
#include <cstring>
#define MAXN 500010
using namespace std;

struct link
{
	int from, to, val, nxt;
};

struct query
{
	int from, to, num, nxt;
};

link e[MAXN << 1];
query q[MAXN << 1];
int head1[MAXN], cnt1, cnt2;
int head2[MAXN];
int n, T, u, v;
int LCA[MAXN];
int dis[MAXN], father[MAXN];
bool vis[MAXN];

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

inline void add(int u, int v)
{
	e[cnt1] = (link)
	{
		u, v, 1, head1[u]
	};
	head1[u] = cnt1++;
	e[cnt1] = (link)
	{
		v, u, 1, head1[v]
	};
	head1[v] = cnt1++;
}

inline void add_query(int u, int v, int c)
{
	q[cnt2] = (query)
	{
		u, v, c, head2[u]
	};
	head2[u] = cnt2++;
	q[cnt2] = (query)
	{
		v, u, c, head2[v]
	};
	head2[v] = cnt2++;
}

int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

void Tarjan(int u)
{
	vis[u] = true;
	father[u] = u;
	for (int i = head2[u]; ~i; i = q[i].nxt)
		if (vis[q[i].to])
			LCA[q[i].num] = getfather(q[i].to);
	for (int i = head1[u]; ~i; i = e[i].nxt)
		if (!vis[e[i].to])
		{
			dis[e[i].to] = dis[u] + e[i].val;
			Tarjan(e[i].to);
			father[e[i].to] = u;
		}
}

int main()
{
	memset(head1, -1, sizeof head1);
	memset(head2, -1, sizeof head2);
	memset(vis, false, sizeof vis);
	n = read();
	T = read();
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i < n; i++)
	{
		u = read();
		v = read();
		add(u, v);
	}
	for (int i = 0; i < T; i++)
	{
		u = read();
		v = read();
		add_query(u, v, i);
	}
	Tarjan(1);
	for (int i = 0; i < cnt2; i += 2)
		printf("%d\n", dis[q[i].from] + dis[q[i].to] - 2 * dis[LCA[q[i].num]]);
	return 0;
}
