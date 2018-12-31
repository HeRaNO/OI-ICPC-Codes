#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 30000
#define MAXM 5500000
using namespace std;
struct link
{
	int to, val, nxt;
};
struct doge
{
	int b, p;
};
struct node
{
	int d, u;
	__attribute__((__optimize__("-O2"))) bool operator < (const node &a)const
	{
		return d > a.d;
	}
};
link e[MAXM << 1];
doge a[MAXN];
int n, m, S, T;
int edge_num[MAXN], cnt;
int dis[MAXN], v[MAXN];
bool vis[MAXN], have[MAXN];
//queue <int> q;
priority_queue <node> q;
__attribute__((__optimize__("-O2"))) inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
}
__attribute__((__optimize__("-O2"))) bool cmp1(doge a, doge b)
{
	return a.p == b.p ? a.b > b.b : a.p < b.p;
}
__attribute__((__optimize__("-O2"))) bool cmp2(doge a, doge b)
{
	return a.p == b.p ? a.b < b.b : a.p < b.p;
}
__attribute__((__optimize__("-O2"))) inline void Make_Graph()
{
	sort(a, a + m, cmp1);
	for (int i = 0; i < m; i++)
	{
		int b = a[i].b, p = a[i].p;
		if (v[b] == p) continue;
		v[b] = p;
		for (int j = 1; b + j * p < n; j++)
			if (have[b + j * p])
			{
				add(b, b + j * p, j);
				if (v[b + j * p] == p) break;
			}
	}
	sort(a, a + m, cmp2);
	memset(v, 0, sizeof v);
	for (int i = 0; i < m; i++)
	{
		int b = a[i].b, p = a[i].p;
		if (v[b] == p) continue;
		v[b] = p;
		for (int j = 1; b - j * p >= 0; j++)
			if (have[b - j * p])
			{
				add(b, b - j * p, j);
				if (v[b - j * p] == p) break;
			}
	}
	return ;
}
/*  inline int SPFA()
    {
    memset(dis,0x7f,sizeof dis);
    q.push(S);dis[S]=0;vis[S]=true;
    while (!q.empty())
    {
        int u=q.front();q.pop();vis[u]=false;
        for (int i=edge_num[u];~i;i=e[i].nxt)
            if (dis[e[i].to]>dis[u]+e[i].val)
            {
                dis[e[i].to]=dis[u]+e[i].val;
                if (!vis[e[i].to])
                {
                    vis[e[i].to]=true;
                    q.push(e[i].to);
                }
            }
    }
    return dis[T]==0x7f7f7f7f?-1:dis[T];
    }*/
__attribute__((__optimize__("-O2"))) inline int Dijkstra()
{
	memset(dis, 0x7f, sizeof dis);
	q.push((node)
	{
		0, S
	});
	dis[S] = 0;
	while (!q.empty())
	{
		node x = q.top();
		q.pop();
		if (vis[x.u]) continue;
		vis[x.u] = true;
		for (int i = edge_num[x.u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > dis[x.u] + e[i].val)
			{
				dis[e[i].to] = dis[x.u] + e[i].val;
				q.push((node)
				{
					dis[e[i].to], e[i].to
				});
			}
	}
	return dis[T] == 0x7f7f7f7f ? -1 : dis[T];
}
__attribute__((__optimize__("-O2"))) inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}
__attribute__((__optimize__("-O2"))) int main()
{
	memset(edge_num, -1, sizeof edge_num);
	read(n);
	read(m);
	for (int i = 0; i < m; i++)
	{
		read(a[i].b);
		read(a[i].p);
		have[a[i].b] = true;
	}
	S = a[0].b;
	T = a[1].b;
	Make_Graph();
	//printf("%d\n",SPFA());
	printf("%d\n", Dijkstra());
	return 0;
}
