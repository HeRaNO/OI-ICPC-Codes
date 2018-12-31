#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 1010
#define MAXM 100010
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

struct Kth_Shortest_Path
{
	int h, g, pos;
	bool operator < (const Kth_Shortest_Path &a)const
	{
		return h + g > a.h + a.g;
	}
};

link e[MAXM], reve[MAXM];
int edge_num[MAXN], cnt, revedge_num[MAXN], revcnt;
int n, m, k, u, v, w, S, T;
int dis[MAXN], appear[MAXN];
bool vis[MAXN];
queue <int> q;
priority_queue <Kth_Shortest_Path> Q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
	reve[revcnt] = (link)
	{
		u, w, revedge_num[v]
	};
	revedge_num[v] = revcnt++;
}

inline void SPFA(int S, int T)
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
		for (int i = revedge_num[u]; ~i; i = reve[i].nxt)
			if (dis[reve[i].to] > dis[u] + reve[i].val)
			{
				dis[reve[i].to] = dis[u] + reve[i].val;
				if (!vis[reve[i].to])
				{
					vis[reve[i].to] = true;
					q.push(reve[i].to);
				}
			}
	}
	return ;
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
		for (int i = edge_num[u.pos]; ~i; i = e[i].nxt)
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
	memset(edge_num, -1, sizeof edge_num);
	memset(revedge_num, -1, sizeof revedge_num);
	read(n);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(u);
		read(v);
		read(w);
		add(u, v, w);
	}
	read(S);
	read(T);
	read(k);
	SPFA(T, S);
	printf("%d\n", Astar(S, T, k));
	return 0;
}
