#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 2510
#define MAXM 6210
using namespace std;

struct link
{
	int to, val, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt;
int n, m, S, T, u, v, w, dis[MAXN];
bool vis[MAXN];
queue <int> q;

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, head[u]
	};
	head[u] = cnt++;
	e[cnt] = (link)
	{
		u, w, head[v]
	};
	head[v] = cnt++;
}

inline int SPFA(int S, int T)
{
	memset(dis, 0x7f, sizeof dis);
	dis[S] = 0;
	vis[S] = true;
	q.push(S);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > dis[u] + e[i].val)
			{
				dis[e[i].to] = dis[u] + e[i].val;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	return dis[T];
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
	read(m);
	read(S);
	read(T);
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		read(w);
		add(u, v, w);
	}
	printf("%d\n", SPFA(S, T));
	return 0;
}