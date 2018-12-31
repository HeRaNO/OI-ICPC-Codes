#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 100010
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

link e[MAXN * 2];
int edge_num[MAXN], cnt;
int n, m, u, v;
int a[MAXN], dis[MAXN];
bool vis[MAXN];
queue <int> q;

inline int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
inline int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
inline int getdis(int u, int v)
{
	return lcm(a[u], a[v]);
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, w, edge_num[v]
	};
	edge_num[v] = cnt++;
}

inline int SPFA()
{
	q.push(1);
	dis[1] = 0;
	vis[1] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > mymax(dis[u], e[i].val))
			{
				dis[e[i].to] = mymax(dis[u], e[i].val);
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	return dis[n];
}

int main()
{
	memset(edge_num, -1, sizeof edge_num);
	memset(dis, 0x7f, sizeof dis);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		add(u, v, getdis(u, v));
	}
	printf("%d\n", SPFA());
	return 0;
}
