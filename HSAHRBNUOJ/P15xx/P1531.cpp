#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 105
#define MAXM 10005
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 2];
int head[MAXN], cnt = 1;
int n, u, v, f, S, T, ans;
int dpt[MAXN];
queue <int> q;

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

inline int mymin(int a, int b)
{
	return a < b ? a : b;
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
	if (x == T) return flow;
	int left = flow;
	for (int i = head[x]; i && left; i = e[i].nxt)
		if (e[i].flow && dpt[e[i].to] == dpt[x] + 1)
		{
			int t = Dinic(e[i].to, mymin(left, e[i].flow));
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
	char ch;
	if ((ch = getchar()) == EOF)
	{
		x = 0;
		return ;
	}
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(S);
	read(T);
	while (true)
	{
		read(u);
		if (!u) break;
		read(v);
		read(f);
		add(u, v, f);
		add(v, u, f);
	}
	while (BFS()) ans += Dinic(S, ~(1 << 31));
	printf("%d\n", ans);
	return 0;
}