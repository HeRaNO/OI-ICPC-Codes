#include <bits/stdc++.h>
#define MAXW 10005
using namespace std;

int n,m,x,p;
long long dp[MAXW];

int main()
{
	while (~scanf("%d %d",&n,&m))
	{
		memset(dp,0x3f,sizeof dp);dp[0]=0;
		long long ans1=dp[1];int ans2=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d",&x,&p);
			for (int j=p;j<=10000;j++)
				dp[j]=min(dp[j],dp[j-p]+x);
		}
		for (int i=10000;i>=m;i--)
			if (ans1>dp[i])
			{
				ans1=dp[i];ans2=i;
			}
		printf("%lld %d\n",ans1,ans2);
	}
	return 0;
}