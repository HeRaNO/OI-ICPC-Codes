#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n,L,R,x,dp[MAXN][MAXN][MAXN],s[MAXN];

int main()
{
	while (~scanf("%d %d %d",&n,&L,&R))
	{
		memset(dp,0x3f,sizeof dp);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&x);s[i]=s[i-1]+x;
			dp[i][i][1]=0;
		}
		for (int l=2;l<=n;l++)
			for (int i=1;i+l-1<=n;i++)
				for (int j=2;j<=l;j++)
				{
					for (int k=i;k<=i+l-2;k++)
						dp[i][i+l-1][j]=min(dp[i][i+l-1][j],dp[i][k][j-1]+dp[k+1][i+l-1][1]);
					if (L<=j&&j<=R) dp[i][i+l-1][1]=min(dp[i][i+l-1][1],dp[i][i+l-1][j]+s[i+l-1]-s[i-1]);
				}
		printf("%d\n",dp[1][n][1]==0x3f3f3f3f?0:dp[1][n][1]);
	}
	return 0;
}