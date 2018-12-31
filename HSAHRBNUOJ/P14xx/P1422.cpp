#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 5000
#define MAXM 400000
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt;
int n, k, S, T, ans;
int dpt[MAXN], a[MAXN], dp[MAXN];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void add(int u, int v, int f)
{
	e[++cnt] = (link)
	{
		v, f, head[u]
	};
	head[u] = cnt;
	e[++cnt] = (link)
	{
		u, 0, head[v]
	};
	head[v] = cnt;
}

inline bool BFS()
{
	memset(dpt, -1, sizeof dpt);
	dpt[S] = 1;
	q.push(S);
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
	return dpt[T] != -1;
}

inline int Dinic(int x, int flow)
{
	int left = flow;
	if (x == T) return flow;
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

inline void Dynamic_Programming()
{
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++) if (a[j] <= a[i]) dp[i] = mymax(dp[i], dp[j]);
		dp[i]++;
		k = mymax(k, dp[i]);
	}
	return ;
}

inline void Build_Graph(bool f)
{
	memset(head, 0, sizeof head);
	cnt = 1;
	if (f)
	{
		for (int i = 1; i <= n; i++)
		{
			if (dp[i] == 1) add(S, i, 1);
			if (dp[i] == k) add(i + n, T, 1);
			add(i, i + n, 1);
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			int v = 1;
			if (i == 1 || i == n) v = ~(1 << 31);
			if (dp[i] == 1) add(S, i, v);
			if (dp[i] == k) add(i + n, T, v);
			add(i, i + n, v);
		}
	}
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (a[j] <= a[i] && dp[i] == dp[j] + 1) add(j + n, i, 1);
	return ;
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
	//freopen("alis.in","r",stdin);freopen("alis.out","w",stdout);
	read(n);
	S = 0;
	T = (n << 1) + 1;
	for (int i = 1; i <= n; i++) read(a[i]);
	Dynamic_Programming();
	printf("%d\n", k);
	if (k == 1)
	{
		printf("%d\n%d\n", n, n);
		return 0;
	}
	Build_Graph(true);
	while (BFS()) ans += Dinic(S, ~(1 << 31));
	printf("%d\n", ans);
	ans = 0;
	Build_Graph(false);
	while (BFS()) ans += Dinic(S, ~(1 << 31));
	printf("%d\n", ans);
	return 0;
}