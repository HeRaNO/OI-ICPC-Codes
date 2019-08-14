#include <bits/stdc++.h>
#define MAXN 50005
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,x[2],v[MAXN],f,isFliped[MAXN],now[MAXN],dp[MAXN][2];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline void dfs(int x,int fa,int ff)
{
	ff^=isFliped[x];
	if (ff) v[x]*=-1;
	dp[x][0]=v[x];dp[x][1]=-v[x];
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa)
		{
			dfs(e[i].to,x,ff);
			dp[x][0]+=max(dp[e[i].to][0],dp[e[i].to][1]-::x[isFliped[e[i].to]]);
			dp[x][1]+=max(dp[e[i].to][1],dp[e[i].to][0]-::x[isFliped[e[i].to]]);
		}
	return ;
}

int main()
{
	while (~scanf("%d %d %d",&n,&x[0],&x[1]))
	{
		memset(dp,0,sizeof dp);
		memset(head,-1,sizeof head);cnt=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d %d %d",&v[i],&f,&isFliped[i],&now[i]);
			if(now[i]) v[i]=-v[i];
			add(i,f);
		}
		dfs(0,-1,0);
		if (dp[0][0]<0) puts("HAHAHAOMG");
		else printf("%d\n",dp[0][0]);
	}
	return 0;
}