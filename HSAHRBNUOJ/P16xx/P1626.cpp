#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 200010
using namespace std;

struct link
{
	int to, nxt;
};

link e[MAXN << 1];
int head[MAXN], cnt;
int n, u, v, ans, p, dpt[MAXN];
queue <int> q;

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, head[u]
	};
	head[u] = cnt++;
	e[cnt] = (link)
	{
		u, head[v]
	};
	head[v] = cnt++;
}

inline int BFS(int S)
{
	int pt = S, mx = 0;
	memset(dpt, -1, sizeof dpt);
	dpt[S] = 0;
	q.push(S);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		if (dpt[u] > mx) mx = dpt[pt = u];
		for (int i = head[u]; ~i; i = e[i].nxt)
			if (!~dpt[e[i].to])
			{
				dpt[e[i].to] = dpt[u] + 1;
				q.push(e[i].to);
			}
	}
	return pt;
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
	memset(head, -1, sizeof head);
	read(n);
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		add(u, v);
	}
	printf("%d\n", dpt[BFS(BFS(1))]);
	return 0;
}