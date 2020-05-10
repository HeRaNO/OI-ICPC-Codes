#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200005
#define logN 30
using namespace std;

long long x[1 << 19], lazy[1 << 19];
int n, T, R = 1, u, v, o, top;
int fib[logN], label[MAXN], a[MAXN];
int range[2][MAXN][logN], sta[MAXN];
queue <int> q;
vector <int> g[MAXN];

inline void BFS_Relabel()
{
	fib[1] = fib[2] = 1;
	for (int i = 3; fib[i - 1] <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];
	fib[1] = 0; q.push(1); label[1] = R;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (auto v : g[u])
			if (!label[v])
			{
				label[v] = ++R;
				q.push(v);
			}
	}
	return ;
}

inline void DFS(int x)
{
	sta[++top] = x;
	for (int i = 1; top - fib[i] > 0; i++)
	{
		range[0][sta[top - fib[i]]][i] = min(range[0][sta[top - fib[i]]][i], label[x]);
		range[1][sta[top - fib[i]]][i] = max(range[1][sta[top - fib[i]]][i], label[x]);
	}
	for (auto v : g[x]) DFS(v);
	top--;
	return ;
}

inline void add(int u, int l, int r, long long v)
{
	x[u] += (r - l) * v;
	lazy[u] += v;
	return ;
}

inline void PushDown(int u, int l, int r)
{
	if (!lazy[u]) return ;
	int m = l + r >> 1;
	add(u << 1, l, m, lazy[u]);
	add(u << 1 | 1, m, r, lazy[u]);
	lazy[u] = 0;
	return ;
}

inline void BuildTree(int u, int l, int r)
{
	if (l + 1 == r)
	{
		x[u] = a[label[l]];
		return ;
	}
	int m = l + r >> 1;
	BuildTree(u << 1, l, m);
	BuildTree(u << 1 | 1, m, r);
	x[u] = x[u << 1] + x[u << 1 | 1];
	return ;
}

inline void modify(int u, int l, int r, int v, int pl, int pr)
{
	if (pl == l && pr == r)
	{
		add(u, l, r, v);
		return ;
	}
	PushDown(u, pl, pr); int m = pl + pr >> 1;
	if (r <= m) modify(u << 1, l, r, v, pl, m);
	else if (m <= l) modify(u << 1 | 1, l, r, v, m, pr);
	else
	{
		modify(u << 1, l, m, v, pl, m);
		modify(u << 1 | 1, m, r, v, m, pr);
	}
	x[u] = x[u << 1] + x[u << 1 | 1];
	return ;
}

inline long long query(int u, int l, int r, int pl, int pr)
{
	if (pl == l && pr == r) return x[u];
	PushDown(u, pl, pr); int m = pl + pr >> 1;
	if (r <= m) return query(u << 1, l, r, pl, m);
	else if (m <= l) return query(u << 1 | 1, l, r, m, pr);
	else return query(u << 1, l, m, pl, m) + query(u << 1 | 1, m, r, m, pr);
}

inline void read(int &x)
{
	x = 0; bool f = false; char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	if (f) x = -x;
	return ;
}

int main()
{
	memset(range[0], 0x7f, sizeof range[0]);
	read(n); read(T);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 2; i <= n; i++) read(u), g[u].push_back(i);
	BFS_Relabel(); DFS(1); BuildTree(1, 1, n + 1);
	while (T--)
	{
		read(o); read(u);
		if (o == 1)
		{
			read(v);
			for (int i = 1; range[1][u][i]; i++)
				modify(1, range[0][u][i], range[1][u][i] + 1, v, 1, n + 1);
		}
		else
		{
			long long ans = 0;
			for (int i = 1; range[1][u][i]; i++)
				ans = ans + query(1, range[0][u][i], range[1][u][i] + 1, 1, n + 1);
			printf("%lld\n", ans);
		}
	}
	return 0;
}