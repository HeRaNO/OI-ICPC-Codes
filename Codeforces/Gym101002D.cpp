#include <bits/stdc++.h>
#define MAXN 2505
using namespace std;

const double eps=1e-5;

struct link
{
	int to,nxt;
};

link e[MAXN];
int head[MAXN],cnt;
int n,k,x,a[MAXN][2],siz[MAXN],id[MAXN],R;
double dp[MAXN][MAXN],l,r,m,v[MAXN];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
}

void dfs(int x)
{
	id[R++]=x;siz[x]=1;
	for (int i=head[x];~i;i=e[i].nxt) dfs(e[i].to),siz[x]+=siz[e[i].to];
	return ;
}

bool check(double m)
{
	for (int i=1;i<=n+1;i++)
	{
		v[i]=(double)a[id[i]][1]-(double)a[id[i]][0]*m;
		for (int j=0;j<=k+1;j++)
			dp[i][j]=-1e18;
	}
	for (int i=0;i<=n;i++)
		for (int j=0;j<=k+1&&j<=i;j++)
		{
			dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+v[i]);
			dp[i+siz[id[i]]][j]=max(dp[i+siz[id[i]]][j],dp[i][j]);
		}
	return dp[n+1][k+1]>=0;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d %d",&k,&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&a[i][0],&a[i][1],&x);
		add(x,i);
	}
	dfs(0);
	l=0;r=1e4;
	while (r-l>eps)
	{
		m=(l+r)/2.0;
		if (check(m)) l=m;
		else r=m;
	}
	printf("%.3f\n",l);
	return 0;
}