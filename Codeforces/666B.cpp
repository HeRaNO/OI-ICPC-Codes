#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=3050;
int a,b,c,d;
int A,B,C,D,ans;
const int inf=0x3f3f3f3f;
int n,m;
struct edge
{
	int v;
	int nxt;
}e[N+2005],g[N+2005];
int head[N],ecnt,gcnt,ghead[N];
void ad(int u,int v)
{
	e[++ecnt].v=v;e[ecnt].nxt=head[u];head[u]=ecnt;
	g[++gcnt].v=u;g[gcnt].nxt=ghead[v];ghead[v]=gcnt;
}
bool vis[N];
int dis[N][N],dis2[N][N];
void sp(int S)
{
	dis[S][S]=0;
	vis[S]=1;
	queue <int> q;
	q.push(S);
	while(!q.empty())
	{
		int u=q.front();q.pop();vis[u]=0;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(dis[S][v]>dis[S][u]+1)
			{
				dis[S][v]=dis[S][u]+1;
				if(!vis[v])vis[v]=1,q.push(v);
			}
		}
	}
}
void sp2(int S)
{
	dis2[S][S]=0;
	vis[S]=1;
	queue <int> q;
	q.push(S);
	while(!q.empty())
	{
		int u=q.front();q.pop();vis[u]=0;
		for(int i=ghead[u];i;i=g[i].nxt)
		{
			int v=g[i].v;
			if(dis2[S][v]>dis2[S][u]+1)
			{
				dis2[S][v]=dis2[S][u]+1;
				if(!vis[v])vis[v]=1,q.push(v);
			}
		}
	}
}
pair <int,int> p1[N][N],p2[N][N];
int cnt1[N],cnt2[N];

void work()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(dis[i][j]==inf)continue;
			cnt1[i]++;
			p1[i][cnt1[i]].first=dis[i][j];
			p1[i][cnt1[i]].second=j;
		}
		sort(p1[i]+1,p1[i]+cnt1[i]+1,greater< pair<int,int> >() );
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(dis2[i][j]==inf)continue;
			cnt2[i]++;
			p2[i][cnt2[i]].first=dis2[i][j];
			p2[i][cnt2[i]].second=j;
		}
		sort(p2[i]+1,p2[i]+cnt2[i]+1,greater< pair<int,int> >() );
	}
}

int main()
{
	mem(dis,inf);mem(dis2,inf);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;scanf("%d%d",&x,&y);
		ad(x,y);
	}
	for(int i=1;i<=n;++i)sp(i),sp2(i);
	work();
	for(b=1;b<=n;++b)
	{
		for(c=1;c<=n;++c)
		{
			if(b==c||dis[b][c]==inf)continue;
			for(int k1=1;k1<=min(4,cnt2[b]);++k1)
			{
				for(int k2=1;k2<=min(4,cnt1[c]);++k2)
				{
					a=p2[b][k1].second;
					d=p1[c][k2].second;
					if(a==b||a==c||a==d||c==d||b==d)continue;
					int tmp=dis[b][c]+dis[a][b]+dis[c][d];
					if(tmp>ans)
					{
						ans=tmp;
						A=a;B=b;C=c;D=d;
					}
				}
			}
		}
	}
	printf("%d %d %d %d\n",A,B,C,D);
	return 0;
}
