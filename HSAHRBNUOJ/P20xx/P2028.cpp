#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 210
#define MAXM 1500
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1], bak[MAXM << 1];
int head[MAXN], cnt = 1;
int n, m, u, v, S, T, ans, now;
int dpt[MAXN];
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
	read(n);
	read(m);
	read(S);
	read(T);
	S += n;
	for (int i = 1; i <= n; i++) add(i, i + n, 1);
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		add(u + n, v, ~(1 << 31));
		add(v + n, u, ~(1 << 31));
	}
	memcpy(e, bak, sizeof bak);
	while (BFS()) ans += Dinic(S, ~(1 << 31));
	printf("%d\n", ans);
	bool first = true;
	for (int i = 1; i <= n && ans; i++)
	{
		now = 0;
		memcpy(e, bak, sizeof bak);
		for (int j = head[i]; j; j = e[j].nxt)
			if (e[j].to == i + n)
			{
				e[j].flow = 0;
				break;
			}
		while (BFS()) now += Dinic(S, ~(1 << 31));
		if (now + 1 == ans)
		{
			ans--;
			for (int j = head[i]; j; j = bak[j].nxt)
				if (bak[j].to == i + n)
				{
					bak[j].flow = 0;
					break;
				}
			if (first)
			{
				printf("%d", i);
				first = false;
			}
			else printf(" %d", i);
		}
	}
	puts("");
	return 0;
}