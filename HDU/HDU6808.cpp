#include <bits/stdc++.h>
#define MAXN 200005
#define MAXM 300005
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt;
int dpt[MAXN], l[MAXN], r[MAXN];
int n, X, Y, S, T, ans;
queue <int> q;
pair <int, int*> b[MAXN], c[MAXN];

inline void add(int u, int v, int f)
{
	e[++cnt] = (link){ v, f, head[u] }; head[u] = cnt;
	e[++cnt] = (link){ u, 0, head[v] }; head[v] = cnt;
}

inline bool BFS()
{
	memset(dpt, -1, sizeof dpt);
	dpt[S] = 1;
	q.push(S);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = head[x]; ~i; i = e[i].nxt)
			if (e[i].flow && !~dpt[e[i].to])
			{
				dpt[e[i].to] = dpt[x] + 1;
				q.push(e[i].to);
			}
	}
	return dpt[T] != -1;
}

inline int Dinic(int x, int flow)
{
	int left = flow;
	if (x == T) return flow;
	for (int i = head[x]; ~i && left; i = e[i].nxt)
		if (e[i].flow && dpt[e[i].to] == dpt[x] + 1)
		{
			int t = Dinic(e[i].to, min(left, e[i].flow));
			e[i].flow -= t;
			e[i ^ 1].flow += t;
			left -= t;
		}
	if (left) dpt[x] = -1;
	return flow - left;
}

inline void Solve()
{
	X = Y = ans = 0; cnt = 1;
	memset(head, -1, sizeof head);
	scanf("%d", &n); b[0].first = c[0].first = 1 << 31;
	for (int i = 1, x, y; i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		b[i] = { x - y, &l[i] };
		c[i] = { x + y, &r[i] };
	}
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (b[i].first != b[i - 1].first) ++X;
		*b[i].second = X;
	}
	for (int i = 1; i <= n; i++)
	{
		if (c[i].first != c[i - 1].first) ++Y;
		*c[i].second = Y;
	}
	S = 0; T = X + Y + 1;
	for (int i = 1; i <= X; i++) add(S, i, 1);
	for (int i = 1; i <= Y; i++) add(i + X, T, 1);
	for (int i = 1; i <= n; i++) add(l[i], r[i] + X, 1);
	while (BFS()) ans += Dinic(S, ~(1 << 31));
	printf("%d\n", ans);
	return ;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--) Solve();
	return 0;
}