#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n,m,u,v,g[MAXN][MAXN];
char c;
int dp[MAXN][MAXN][27];

inline int dfs(int a,int b,int c)
{
	if (~dp[a][b][c]) return dp[a][b][c];
	for (int i=1;i<=n;i++)
		if (g[a][i]&&g[a][i]>=c&&!dfs(b,i,g[a][i]))
			return dp[a][b][c]=1;
	return dp[a][b][c]=0;
}

int main()
{
	scanf("%d %d",&n,&m);memset(dp,-1,sizeof dp);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d %c",&u,&v,&c);
		g[u][v]=c-'a'+1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			dfs(i,j,0);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) putchar(dp[i][j][0]?'A':'B');
		putchar('\n');
	}
	return 0;
}