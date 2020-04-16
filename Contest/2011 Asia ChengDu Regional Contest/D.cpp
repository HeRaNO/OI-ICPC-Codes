#include <bits/stdc++.h>
#define MAXK 8
#define MAXN 50
using namespace std;

int T,n,m,k,u,v,w,g[MAXN][MAXN];
int p[MAXK],t[MAXK],ft[MAXK],a[MAXN];
int dp[1<<MAXK][1<<MAXK][MAXN];

inline void Floyd()
{
	for (int k=0;k<n;k++)
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	return ;
}

inline int DP()
{
	memset(dp,0x3f,sizeof dp);int inf=dp[0][0][0];
	dp[0][0][0]=0;
	for (int i=0;i<(1<<k);i++)
		for (int j=0;j<(1<<k);j++)
			for (int x=0;x<n;x++)
				if (dp[i][j][x]!=inf)
				{
					for (int pt=0;pt<k;pt++)
						if (!(i&(1<<pt)))
						{
							int w=g[x][p[pt]],v=p[pt];
							if (!(j&(1<<pt))) w+=t[pt];
							else w+=ft[pt];
							dp[i|(1<<pt)][j|a[v]][v]=min(dp[i|(1<<pt)][j|a[v]][v],dp[i][j][x]+w);
						}
					for (int y=0;y<n;y++)
						dp[i][j|a[y]][y]=min(dp[i][j|a[y]][y],dp[i][j][x]+g[x][y]);
				}
	int fin=(1<<k)-1,ans=inf;
	for (int i=0;i<(1<<k);i++) ans=min(ans,dp[fin][i][0]);
	return ans;
}

int main()
{
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		
		scanf("%d %d %d",&n,&m,&k);
		memset(g,0x3f,sizeof g);
		memset(a,0,sizeof a);
		for (int i=0;i<n;i++) g[i][i]=0;
		for (int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			--u;--v;
			g[u][v]=g[v][u]=min(g[u][v],w);
		}
		for (int i=0,x,y;i<k;i++)
		{
			scanf("%d %d %d",&p[i],&t[i],&ft[i]);--p[i];
			scanf("%d",&x);
			while (x--)
			{
				scanf("%d",&y);--y;
				a[y]|=(1<<i);
			}
		}
		Floyd();
		printf("Case #%d: %d\n",cas,DP());
	}
	return 0;
}