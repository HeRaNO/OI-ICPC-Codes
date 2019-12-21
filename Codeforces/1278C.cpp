#include <bits/stdc++.h>
#define MAXN 2000005
using namespace std;

int T,n,a[MAXN],b[MAXN];
int dp[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		memset(dp,0x3f,n*40);int _1=0;
		for (int i=1;i<=n*2;i++)
		{
			scanf("%d",&a[i]);
			if (a[i]==1) ++_1;
			else --_1;
		}
		int ans=~(1<<31),now=0;
		for(int i=n+1;i<=n*2;i++)
		{
			dp[now+_1+n*3]=min(dp[now+_1+n*3],i-n-1);
			if (a[i]==2) ++now;
			else --now;
		}
		dp[now+_1+n*3]=min(dp[now+_1+n*3],n);now=0;
		for(int i=n;i;i--)
		{
			ans=min(ans,dp[now+n*3]+n-i);
			if (a[i]==1) ++now;
			else --now;
		}
		printf("%d\n",min(ans,dp[now+n*3]+n));
	}
	return 0;
}