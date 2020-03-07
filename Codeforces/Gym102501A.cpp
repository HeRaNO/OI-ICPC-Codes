#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pb(x) push_back(x)
using namespace std;
const int N=1050;
const int inf=0x3f3f3f3f;
int T,B,n;
int ans;
int C[150];
int dp[N][150];
int xs,ys,xd,yd;
int d[N][N];
int c[N][N];
struct stations
{
	int x,y;
}a[N];
inline int dist(stations X,stations Y)
{
	int X1=X.x,X2=Y.x,Y1=X.y,Y2=Y.y;
	return ceil(sqrt(1.0*(X1-X2)*(X1-X2)+1.0*(Y1-Y2)*(Y1-Y2)));
}

void input()
{
	scanf("%d%d%d%d",&xs,&ys,&xd,&yd);
	scanf("%d",&B);
	scanf("%d",&C[0]);
	scanf("%d",&T);
	for(int i=1;i<=T;++i)scanf("%d",&C[i]);
	scanf("%d",&n);
	a[1].x=xs,a[1].y=ys;
	a[n+2].x=xd,a[n+2].y=yd;
	mem(c,inf);
	for(int i=2;i<=n+2;++i)c[1][i]=C[0];
	for(int i=2;i<=n+1;++i)c[i][n+2]=C[0];
	for(int i=2;i<=n+1;++i)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		int l;scanf("%d",&l);
		while(l--)
		{
			int j,mj;
			scanf("%d%d",&j,&mj);
			j+=2;
			c[i][j]=c[j][i]=min(c[i][j],C[mj]);
		}
	}
}
struct edge
{
	int v,dis,cost,nxt;
}e[3000050];
int head[N],ecnt;
inline void ad(int u,int v,int dis,int cost)
{
	e[++ecnt].v=v;e[ecnt].dis=dis;e[ecnt].cost=cost;
	e[ecnt].nxt=head[u];head[u]=ecnt;
}
struct nodes
{
	int u,fa,dis,cost;
};
queue <nodes> q;

void bfs()
{
	q.push(nodes{1,0,0,0});
	while(!q.empty())
	{
		nodes now=q.front();q.pop();
		int u=now.u,dis=now.dis,cost=now.cost,fa=now.fa;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(v==fa)continue;
			if(dis+e[i].dis<=B)
			{
				if(v==n)
				{
					ans=min(ans,cost+e[i].cost);
					continue;
				}
				if(dp[v][dis+e[i].dis]>cost+e[i].cost)
				{
					dp[v][dis+e[i].dis]=cost+e[i].cost;
					q.push(nodes{v,u,dis+e[i].dis,cost+e[i].cost});
				}
			}
		}
	}
}

void work()
{
	n+=2;ans=inf;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			d[i][j]=d[j][i]=dist(a[i],a[j]);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(i==j||c[i][j]==inf)continue;
			ad(i,j,d[i][j],c[i][j]*d[i][j]);
		}
	}
	mem(dp,inf);
	dp[1][0]=0;
	bfs();
	if(ans==inf)ans=-1;
	printf("%d\n",ans);
}

int main()
{
	input();
	work();
	return 0;
}
