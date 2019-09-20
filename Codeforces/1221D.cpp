#include <bits/stdc++.h>
#define MAXN 300005
using namespace std;

int T,n,a[MAXN];
long long dp[MAXN][3],b[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);dp[0][1]=dp[0][2]=~(1LL<<63);
		for (int i=1;i<=n;i++) dp[i][0]=dp[i][1]=dp[i][2]=0;
		for (int i=1;i<=n;i++) scanf("%d %lld",&a[i],&b[i]);
		for (int i=n;i;i--) a[i]-=a[i-1];
		for (int i=1;i<=n;i++)
		{
			if (a[i]==0)
			{
				dp[i][0]=min(dp[i-1][1],dp[i-1][2]);
				dp[i][1]=min(dp[i-1][0],dp[i-1][2])+b[i];
				dp[i][2]=min(dp[i-1][0],dp[i-1][1])+b[i]*2;
			}
			else if (a[i]==1)
			{
				dp[i][0]=min(dp[i-1][0],dp[i-1][2]);
				dp[i][1]=min(dp[i-1][0],dp[i-1][1])+b[i];
				dp[i][2]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+b[i]*2;
			}
			else if (a[i]==2)
			{
				dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
				dp[i][1]=dp[i][2]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]));
				dp[i][1]+=b[i];
				dp[i][2]+=b[i]*2;
			}
			else if (a[i]==-1)
			{
				dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]));
				dp[i][1]=min(dp[i-1][1],dp[i-1][2])+b[i];
				dp[i][2]=min(dp[i-1][0],dp[i-1][2])+b[i]*2;
			}
			else if (a[i]==-2)
			{
				dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]));
				dp[i][1]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+b[i];
				dp[i][2]=min(dp[i-1][1],dp[i-1][2])+b[i]*2;
			}
			else
			{
				dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]));
				dp[i][1]=dp[i][0]+b[i];
				dp[i][2]=dp[i][1]+b[i];
			}
		}
		printf("%lld\n",min(dp[n][0],min(dp[n][1],dp[n][2])));
	}
	return 0;
}