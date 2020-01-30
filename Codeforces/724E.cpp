#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;

int n,c,p[MAXN],s[MAXN];
long long dp[2][MAXN],ans=~(1LL<<63);

int main()
{
	scanf("%d %d",&n,&c);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++) scanf("%d",&s[i]);
	for (int i=1;i<=n;i++)
	{
		memset(dp[i&1],0x3f,sizeof dp[i&1]);
		for (int j=0;j<=i;j++)
		{
			if (j) dp[i&1][j]=min(dp[(i-1)&1][j]+p[i]+1LL*j*c,dp[(i-1)&1][j-1]+s[i]);
			else dp[i&1][j]=dp[(i-1)&1][j]+p[i];
		}
	}
	for (int i=0;i<=n;i++) ans=min(ans,dp[n&1][i]);
	printf("%lld\n",ans);
	return 0;
}