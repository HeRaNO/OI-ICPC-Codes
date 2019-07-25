#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

struct link
{
	int to,val,nxt;
};

struct node
{
	int d, u;
	bool operator < (const node &a)const
	{
		return d > a.d;
	}
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,m,s,t,u,v,ans;
int dis1[MAXN],dis2[MAXN];
bool a[MAXN][MAXN],vis[MAXN];
priority_queue <node> q;

inline void add(int u,int v)
{
	a[u][v]=a[v][u]=true;
	e[cnt]=(link){v,1,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,1,head[v]};head[v]=cnt++;
}

inline void Dijkstra(int S, int dis[])
{
	memset(vis, false, sizeof vis);
	q.push((node){0, S}); dis[S] = 0;
	while (!q.empty())
	{
		node x = q.top();
		q.pop();
		if (vis[x.u]) continue;
		vis[x.u] = true;
		for (int i = head[x.u]; ~i; i = e[i].nxt)
		{
			if (dis[e[i].to] > dis[x.u] + e[i].val)
			{
				dis[e[i].to] = dis[x.u] + e[i].val;
				q.push((node){dis[e[i].to], e[i].to});
			}
		}
	}
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	memset(dis1,0x3f,sizeof dis1);
	memset(dis2,0x3f,sizeof dis2);
	scanf("%d %d %d %d",&n,&m,&s,&t);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		add(u,v);
	}
	Dijkstra(s,dis1);
	Dijkstra(t,dis2);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (!a[i][j])
			{
				if (dis1[i]+1+dis2[j]>=dis1[t]&&dis2[i]+1+dis1[j]>=dis2[s])
					++ans;
			}
	printf("%d\n",ans);
	return 0;
}