#include <cmath>
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
int head[MAXN], cnt = 1;
int n, S, T;
int dpt[MAXN];
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

inline int check(int x)
{
	memset(head, 0, sizeof head);
	cnt = 1;
	int ans = 0;
	S = 0;
	T = (x << 1) + 1;
	for (int i = 1; i <= x; i++)
		for (int j = i + 1; j <= x; j++)
			if (sqrt(i + j) == (int)sqrt(i + j)) add(i, j + x, 1);
	for (int i = 1; i <= x; i++) add(S, i, 1), add(i + x, T, 1);
	while (BFS()) ans += Dinic(S, ~(1 << 31));
	return x - ans;
}

inline int Binary()
{
	int l = n, r = 1600, mid, ans = 0;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (check(mid) <= n) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

int main()
{
	//freopen("ball.in","r",stdin);freopen("ball.out","w",stdout);
	scanf("%d", &n);
	printf("%d\n", Binary());
	return 0;
}