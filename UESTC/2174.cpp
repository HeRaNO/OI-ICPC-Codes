#include <bits/stdc++.h>
#define MAXN 505
using namespace std;

int n,m,a[MAXN][MAXN],b[MAXN][MAXN],dp[MAXN][MAXN],s[2][MAXN][MAXN],ans;
/*
		B
	----------
	|
R	|
	|
	|
	|
*/

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]),s[0][i][j]=s[0][i][j-1]+a[i][j];//Red
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&b[i][j]),s[1][i][j]=s[1][i-1][j]+b[i][j];//Black
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			dp[i][j]=max(dp[i][j-1]+s[1][i][j],dp[i-1][j]+s[0][i][j]);
	printf("%d\n",dp[n][m]);
	return 0;
}