#include <bits/stdc++.h>
#define MAXN 100005
#define MAXK 101
using namespace std;

const long long INF=1e15;

struct link
{
	int to,val,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int cas,k,T,n,u,v,w,siz[MAXN];
long long dp[MAXN][MAXK],ans;

inline void add(int u,int v,int w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,head[v]};head[v]=cnt++;
}

void dfs(int x,int f)
{
	for (int i=1;i<=k;i++) dp[x][i]=INF;
	dp[x][0]=0;siz[x]=0;bool ff=true;
	if (~head[x]&&!~e[head[x]].nxt)
	{
		dp[x][1]=0;
		siz[x]=1;
	}
	for (int r=head[x];~r;r=e[r].nxt)
		if (e[r].to!=f)
		{
			ff=false;
			dfs(e[r].to,x);
			for (int i=min(siz[x],k);i>=0;i--)
				for (int j=min(siz[e[r].to],k-i);j>=0;j--)
					dp[x][i+j]=min(dp[x][i+j],dp[x][i]+dp[e[r].to][j]+1LL*j*(k-j)*e[r].val);
			siz[x]+=siz[e[r].to];
		}
	ans=min(ans,dp[x][k]);
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(head,-1,sizeof head);cnt=0;
		scanf("%d %d",&n,&k);ans=~(1LL<<63);
		for (int i=1;i<n;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			add(u,v,w);
		}
		dfs(1,-1);
		printf("Case #%d: %lld\n",++cas,ans);
	}
	return 0;
}