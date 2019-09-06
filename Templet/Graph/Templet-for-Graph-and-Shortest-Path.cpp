#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 100010//N is the number of point.
#define MAXM 100010//M is the number of edge.
#define MAXP 500//P is the number of point when using Floyed algorithm.
//The kth shortest path has a more effective algorithm.You can refer to the blog http://blog.csdn.net/wyfcyx_forever/article/details/45875055
//wyfcyx%%%
using namespace std;

struct link
{
	int to, val, nxt;
};

struct node
{
	int d, u;
	bool operator < (const node &a)const
	{
		return d > a.d;
	}
};

struct Kth_Shortest_Path
{
	int h, g, pos;
	bool operator < (const Kth_Shortest_Path &a)const
	{
		return h + g > a.h + a.g;
	}
};

link e[MAXM << 1];
int head[MAXN], cnt;
int n, m, k, u, v, w, ans = ~(1 << 31);
int dis[MAXN], dis1[MAXP][MAXP], appear[MAXN];
//dis1 is for Floyed algorithm.n must be small enough.
bool vis[MAXN];
queue <int> q;
priority_queue <node> q1;
priority_queue <Kth_Shortest_Path> Q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

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
	memset(vis, false, sizeof vis);
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

inline int Dijkstra(int S, int T)
{
	memset(dis, 0x7f, sizeof dis);
	memset(vis, false, sizeof vis);
	q1.push((node)
	{
		0, S
	});
	dis[S] = 0;
	while (!q1.empty())
	{
		node x = q1.top();
		q1.pop();
		if (vis[x.u]) continue;
		vis[x.u] = true;
		for (int i = head[x.u]; ~i; i = e[i].nxt)
		{
			if (dis[e[i].to] > dis[x.u] + e[i].val)
			{
				dis[e[i].to] = dis[x.u] + e[i].val;
				q1.push((node)
				{
					dis[e[i].to], e[i].to
				});
			}
		}
	}
	return dis[T];
}

inline int Floyed(int S, int T)
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis1[i][j] = mymin(dis1[i][j], dis1[i][k] + dis1[k][j]);
	return dis1[S][T];
}

inline int Astar(int S, int T, int k)
{
	if (S == T) k++;
	if (dis[T] == 0x7f7f7f7f) return -1;
	Q.push((Kth_Shortest_Path)
	{
		dis[S], 0, S
	});
	while (!Q.empty())
	{
		Kth_Shortest_Path u = Q.top();
		Q.pop();
		appear[u.pos]++;
		if (appear[T] == k && u.pos == T) return u.g;
		if (appear[u.pos] > k) continue;
		for (int i = head[u.pos]; ~i; i = e[i].nxt)
			Q.push((Kth_Shortest_Path)
		{
			dis[e[i].to], u.g + e[i].val, e[i].to
		});
	}
	return -1;
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	memset(head, -1, sizeof head);
	read(n);
	read(m);
	read(k);//k means get the kth shortest path.
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) dis1[i][j] = 1e6;
		dis1[i][i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		read(w);
		add(u, v, w);
		dis1[u][v] = dis1[v][u] = mymin(dis1[u][v], w);
		//When you use Floyed algorithm,please use the code above.
	}
	printf("%d\n", SPFA(1, n));
	printf("%d\n", Dijkstra(1, n));
	printf("%d\n", Floyed(1, n));
	SPFA(n, 1);
	printf("%d\n", Astar(1, n, k));
	return 0;
}
