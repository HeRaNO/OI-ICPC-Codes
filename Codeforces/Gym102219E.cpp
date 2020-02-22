#include <bits/stdc++.h>
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
ll dp[55][1005];
int pre[55][1005];
ll ans[55];
ll a[55];
int n;ll T;

int main()
{
	while(scanf("%lld",&T)==1&&T)
	{
		scanf("%d",&n);
		for(int i=n;i>=1;--i)scanf("%lld",&a[i]);
		mem(dp,0);mem(pre,0);
		for(int i=1;i<=n;++i)
		{
			for(int j=T;j>=0;--j)
			{
				dp[i][j]=dp[i-1][j];
				if(j>=a[i])
				if(dp[i-1][j-a[i]]+a[i]>=dp[i][j])
				{
					dp[i][j]=dp[i-1][j-a[i]]+a[i];
					pre[i][j]=1;
				}
			}
		}
		ll V=T,sum=0;
		for(int i=n;i>=1;--i)
		{
			if(pre[i][V])
			{
				printf("%lld ",a[i]);
				V-=a[i];
				sum+=a[i];
			}
		}
		printf("%lld",sum);
		puts("");
	}
	return 0;
}