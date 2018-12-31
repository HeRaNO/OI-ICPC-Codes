#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 110
#define MAXM 20000
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt = 1;
int n, m, S, T, ans;
int dpt[MAXN];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
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

char buf[1 << 20];
int num[MAXM], ccnt;

inline void read(int f)
{
	gets(buf);
	int len = strlen(buf);
	int x = 0;
	ccnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (buf[i] < '0' || buf[i] > '9')
		{
			num[ccnt++] = x;
			x = 0;
		}
		else x = (x << 3) + (x << 1) + buf[i] - '0';
	}
	if (x) num[ccnt++] = x;
	if (!f)
	{
		m = num[0];
		n = num[1];
		return ;
	}
	if (!~f)
	{
		for (int i = 1; i <= n; i++) add(i + m, T, num[i - 1]);
		return ;
	}
	ans += num[0];
	add(S, f, num[0]);
	for (int i = 1; i < ccnt; i++) add(f, num[i] + m, ~(1 << 31));
	return ;
}

int main()
{
	read(0);
	S = 0;
	T = n + m + 1;
	for (int i = 1; i <= m; i++) read(i);
	read(-1);
	while (BFS()) ans -= Dinic(S, ~(1 << 31));
	printf("%d\n", ans);
	return 0;
}