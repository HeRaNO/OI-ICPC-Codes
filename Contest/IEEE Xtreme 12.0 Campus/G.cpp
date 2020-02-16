#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

int n,k;
long long a[MAXN],dp[MAXN],ans=~(1LL<<63);

int main()
{
	scanf("%d %d",&n,&k);memset(dp,0x3f,sizeof dp);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=k+1&&i<=n;i++)
	{
		dp[i]=a[i];
		if (i+k>=n) ans=min(ans,dp[i]);
	}
	for (int i=(k<<1)+2;i<=n;i++)
	{
		dp[i]=min(dp[i],dp[i-2*k-1]+a[i]);
		if (i+k>=n) ans=min(ans,dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}