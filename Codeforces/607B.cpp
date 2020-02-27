#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int dp[505][505];
int a[505];
int n;

int main()
{
	memset(dp,127,sizeof dp);
	scanf("%d",&n);
	for (int i=0;i<n;i++) 
	{
		scanf("%d",&a[i]);
		dp[i][i]=1;
	}
	for (int l=2;l<=n;l++)
	{
		for (int i=0;i<=n-l;i++) 
		{
			int j=i+l-1;
			if (a[i]==a[j] && l>2) dp[i][j]=dp[i+1][j-1];
			else if (a[i]==a[j]) dp[i][j]=1;
			for (int k=i;k<j;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
	}
	printf("%d",dp[0][n-1]);
	return 0;
}