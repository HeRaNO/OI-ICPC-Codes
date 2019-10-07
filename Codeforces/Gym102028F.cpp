#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
const int N=2000005;
const int inf=0x3f3f3f3f;
int r,c,n,m;
char s[5000][7000];
int x[N],y[N];
int S,T;
int dis[N];bool vis[N];
struct edge
{
	int v,nxt;
}e[N<<3];
int head[N],etot;
inline void ad(int u,int v)
{
	e[++etot].v=v;e[etot].nxt=head[u];head[u]=etot;
	e[++etot].v=u;e[etot].nxt=head[v];head[v]=etot;
}
void sp()
{
	queue <int> q;
	vis[S]=1;q.push(S);
	memset(vis,0,r*(c+1)*sizeof(int));
	memset(dis,inf,r*(c+1)*sizeof(int));
	dis[S]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();vis[u]=0;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}

int main()
{
	int Test;scanf("%d",&Test);
	while(Test--)
	{
		etot=0;
		scanf("%d%d",&r,&c);
		memset(head,0,r*(c+1)*sizeof(int));
		memset(e,0,r*(c+1)*6*sizeof(int));
		getchar();
		n=4*r+3;m=6*c+3;
		for(int i=0;i<n;++i)
		{
			gets(s[i]);
		}
		int cnt=0;
		for(int i=1;i<=r*c;++i)
		{
			cnt++;
			if(i%c==1)
			{
				cnt=1;
				x[i]=2+4*(i/c);
				y[i]=4;
				if(s[x[i]][y[i]]=='S')S=i;
				if(s[x[i]][y[i]]=='T')T=i;
				int downx=x[i]+2,downy=y[i];
				if(s[downx][downy]==' ')
					ad(i,i+c);
				int L1x=x[i]+1,L1y=y[i]+3;
				if(s[L1x][L1y]==' ')
					ad(i,i+1);
				int L2x=x[i]-1,L2y=y[i]+3;
				if(s[L2x][L2y]==' ')
					ad(i,i-c+1);
				continue;
			}
			else if(cnt&1)
			{
				x[i]=x[i-1]-2;
				y[i]=y[i-1]+6;
				if(s[x[i]][y[i]]=='S')S=i;
				if(s[x[i]][y[i]]=='T')T=i;
				int downx=x[i]+2,downy=y[i];
				if(s[downx][downy]==' ')
					ad(i,i+c);
				int L1x=x[i]+1,L1y=y[i]+3;
				if(s[L1x][L1y]==' ')
					ad(i,i+1);
				int L2x=x[i]-1,L2y=y[i]+3;
				if(s[L2x][L2y]==' ')
					ad(i,i-c+1);
				continue;
			}
			else
			{
				x[i]=x[i-1]+2;
				y[i]=y[i-1]+6;
				if(s[x[i]][y[i]]=='S')S=i;
				if(s[x[i]][y[i]]=='T')T=i;
				int downx=x[i]+2,downy=y[i];
				if(s[downx][downy]==' ')ad(i,i+c);
				int L1x=x[i]+1,L1y=y[i]+3;
				if(s[L1x][L1y]==' ')ad(i,i+c+1);
				int L2x=x[i]-1,L2y=y[i]+3;
				if(s[L2x][L2y]==' ')ad(i,i+1);
				continue;
			}
		}
		sp();
		int ans=dis[T];
		if(ans==inf)ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}