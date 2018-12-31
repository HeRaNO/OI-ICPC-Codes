#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 205
#define MAXM 200000
using namespace std;

const int d[8][2] =
{
	{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2},
	{1, 2}, {1, -2}, {2, 1}, {2, -1}
};

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN * MAXN], cnt = 1;
int n, m, S, T, x, y, ans;
int dpt[MAXN * MAXN];
bool ban[MAXN][MAXN];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline int GetPos(int x, int y)
{
	return (x - 1) * n + y;
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
	//freopen("knight.in","r",stdin);freopen("knight.out","w",stdout);
	read(n);
	read(m);
	S = 0;
	T = n * n + 1;
	for (int i = 1; i <= m; i++) read(x), read(y), ban[x][y] = true;
	for (int i = 1; i <= n; i++)
		for (int j = 2 - (i & 1); j <= n; j += 2)
			if (!ban[i][j])
			{
				add(S, GetPos(i, j), 1);
				for (int k = 0; k < 8; k++)
				{
					int tx = i + d[k][0], ty = j + d[k][1];
					if (tx < 1 || tx > n || ty < 1 || ty > n || ban[tx][ty]) continue;
					add(GetPos(i, j), GetPos(tx, ty), 1);
				}
			}
	for (int i = 1; i <= n; i++)
		for (int j = (i & 1) + 1; j <= n; j += 2)
			if (!ban[i][j]) add(GetPos(i, j), T, 1);
	while (BFS()) ans += Dinic(S, ~(1 << 31));
	printf("%d\n", n * n - m - ans);
	return 0;
}