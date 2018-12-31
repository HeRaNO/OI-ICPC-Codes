#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 50010
#define MAXM 150010
using namespace std;

struct link
{
	int to, val, nxt;
};

link e[MAXM];
int head[MAXN], cnt;
int n, m, x, y, z, dis[MAXN];
bool vis[MAXN];
queue <int> q;

inline void min(int &a, int b)
{
	if (a > b) a = b;
}
inline void max(int &a, int b)
{
	if (a < b) a = b;
}

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, head[u]
	};
	head[u] = cnt++;
	return ;
}

inline int SPFA()
{
	for (int i = 1; i <= n + 1; i++) dis[i] = 1 << 31;
	q.push(1);
	vis[1] = true;
	dis[1] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x] = false;
		for (int i = head[x]; ~i; i = e[i].nxt)
			if (dis[e[i].to] < dis[x] + e[i].val)
			{
				dis[e[i].to] = dis[x] + e[i].val;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	return dis[n + 1];
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
	for (int i = 1; i <= m; i++)
	{
		read(x);
		read(y);
		y++;
		read(z);
		add(x, y, z);
	}
	for (int i = 1; i <= n; i++)
	{
		add(i + 1, i, -1);
		add(i, i + 1, 0);
	}
	printf("%d\n", SPFA());
	return 0;
}