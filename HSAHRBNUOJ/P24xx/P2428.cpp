#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 1100
#define MAXM 22000
#define MAXB 21
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt;
int a, n, B, S, T, dpt[MAXN], ans = ~(1 << 31);
int rnk[MAXN][MAXB], lim[MAXB];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int f)
{
	cnt++;
	e[cnt] = (link)
	{
		v, f, head[u]
	};
	head[u] = cnt;
	cnt++;
	e[cnt] = (link)
	{
		u, 0, head[v]
	};
	head[v] = cnt;
}

inline void MakeGraph(int l, int r)
{
	memset(head, -1, sizeof head);
	cnt = 1;
	for (int i = 1; i <= n; i++) add(S, i, 1);
	for (int i = 1; i <= B; i++) add(i + n, T, lim[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= B; j++)
			if (rnk[i][j] >= l && rnk[i][j] <= r) add(i, j + n, 1);
	return ;
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
		for (int i = head[u]; ~i; i = e[i].nxt)
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
	for (int i = head[x]; ~i && left; i = e[i].nxt)
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

inline bool check(int x, int mid)
{
	MakeGraph(x, x + mid);
	int res = 0;
	while (BFS()) res += Dinic(S, ~(1 << 31));
	return res >= n;
}

inline int Binary(int x)
{
	int l = 0, r = B - x, mid, res = ~(1 << 31);
	while (l <= r)
	{
		mid = l + r >> 1;
		if (check(x, mid)) res = mid, r = mid - 1;
		else l = mid + 1;
	}
	return res;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(B);
	S = 0;
	T = n + B + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= B; j++)
		{
			read(a);
			rnk[i][a] = j;
		}
	for (int i = 1; i <= B; i++) read(lim[i]);
	for (int i = 0; i <= B; i++) ans = mymin(ans, Binary(i));
	printf("%d\n", ans + 1);
	return 0;
}