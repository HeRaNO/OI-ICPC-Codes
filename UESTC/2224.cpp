#include <bits/stdc++.h>
#define MAXN 10010
#define MAXM 200010
#define MAXK 21
using namespace std;

struct link
{
	int to;long long val;int nxt;
};

struct node
{
	long long d;int u,k;
	bool operator < (const node &a)const{
		return d>a.d;
	}
};

link e[MAXM<<1];
int head[MAXN],cnt;
int n,m,k,s,t,u,v,w;
long long dis[MAXN][MAXK];
bool vis[MAXN][MAXK];
priority_queue <node> q;

inline void add(int u,int v,long long w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,head[v]};head[v]=cnt++;
}

inline long long Dijkstra(int s,int t)
{
	for (int i=1;i<=n;i++)
		for (int j=0;j<=k;j++)
			dis[i][j]=1e18;
	q.push((node){0,s,0});dis[s][0]=0;
	while (!q.empty())
	{
		node x=q.top();q.pop();
		if (vis[x.u][x.k]) continue;
		vis[x.u][x.k]=true;
		for (int i=head[x.u];~i;i=e[i].nxt)
		{
			if (dis[e[i].to][x.k]>dis[x.u][x.k]+e[i].val)
			{
				dis[e[i].to][x.k]=dis[x.u][x.k]+e[i].val;
				q.push((node){dis[e[i].to][x.k],e[i].to,x.k});
			}
			if (x.k==k) continue;
			if (dis[e[i].to][x.k+1]>dis[x.u][x.k])
			{
				dis[e[i].to][x.k+1]=dis[x.u][x.k];
				q.push((node){dis[e[i].to][x.k+1],e[i].to,x.k+1});
			}
		}
	}
	return dis[t][k];
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	read(n);read(m);read(k);read(s);read(t);
	for (int i=1;i<=m;i++)
	{
		read(u);read(v);read(w);
		add(u,v,w);
	}
	printf("%lld\n",Dijkstra(s,t));
	return 0;
}