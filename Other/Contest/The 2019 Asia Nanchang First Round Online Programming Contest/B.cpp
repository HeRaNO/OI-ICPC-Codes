#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e6+10;
const int INF=0x7fffffff;
const int MOD=20100403;

int head[MAXN],_next[MAXN],to[MAXN],cnt,val[MAXN];
int a[MAXN],dis[MAXN],dis2[MAXN];

void add_edge(int u,int v,int w)
{
	_next[++cnt]=head[u];
	to[cnt]=v;
	val[cnt]=w;
	head[u]=cnt;
}


void init()
{
	memset(head,0,sizeof(head));
	memset(dis,0x3f,sizeof(dis));
	memset(dis2,0x3f,sizeof(dis2));
	cnt=0;
}

void dijkstra(int s)
{
	dis[s]=0;
	priority_queue<pii> pq;
	pq.push({0,s});
	while(!pq.empty())
	{
		pii cur=pq.top();
		pq.pop();
		int now=cur.second;
		for(int i=head[now];i;i=_next[i])
		{
			int v=to[i];
			if(dis[v]>dis[now]+val[i])
			{
				dis[v]=dis[now]+val[i];
				pq.push({dis[v],v});
			}
		}
	}
}

void dijkstra2(int s)
{
	dis2[s]=0;
	priority_queue<pii> pq;
	pq.push({0,s});
	while(!pq.empty())
	{
		pii cur=pq.top();
		pq.pop();
		int now=cur.second;
		for(int i=head[now];i;i=_next[i])
		{
			int v=to[i];
			if(dis2[v]>dis2[now]+val[i])
			{
				dis2[v]=dis2[now]+val[i];
				pq.push({dis2[v],v});
			}
		}
	}
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		init();
		int n,m,s,k,c;
		scanf("%d%d%d%d%d",&n,&m,&s,&k,&c);
		for(int i=1;i<=k;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
		dijkstra(s);
		for(int i=1;i<=k;i++)
			dijkstra2(a[i]);
		int ans1=0,ans2=0;
		for(int i=1;i<=n;i++)ans1=max(ans1,dis[i]);
		for(int i=1;i<=n;i++)ans2=max(ans2,dis2[i]);
		if(ans1<=ans2*c)printf("%d\n",ans1);
		else printf("%d\n",ans2);
	}
}