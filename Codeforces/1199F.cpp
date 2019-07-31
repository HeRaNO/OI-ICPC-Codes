#include <bits/stdc++.h>
#define MAXN 55
using namespace std;

char a[MAXN][MAXN];
int n,dp[MAXN][MAXN][MAXN][MAXN];

int dfs(int lx,int ly,int rx,int ry)
{
	if (~dp[lx][ly][rx][ry]) return dp[lx][ly][rx][ry];
	if (lx==rx&&ly==ry) return a[lx][ly]=='#';
	int ans=max(rx-lx+1,ry-ly+1);
	for (int i=lx;i<rx;i++) ans=min(ans,dfs(lx,ly,i,ry)+dfs(i+1,ly,rx,ry));
	for (int i=ly;i<ry;i++) ans=min(ans,dfs(lx,ly,rx,i)+dfs(lx,i+1,rx,ry));
	return dp[lx][ly][rx][ry]=ans;
}

int main()
{
	memset(dp,-1,sizeof dp);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	printf("%d\n",dfs(1,1,n,n));
	return 0;
}