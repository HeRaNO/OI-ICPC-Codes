#include <bits/stdc++.h>
#define MAXN 16
using namespace std;

int n,k,w[MAXN],h[MAXN],q[MAXN];
long long dp[MAXN][1<<MAXN],mw[1<<MAXN],mh[1<<MAXN],cnt[1<<MAXN],all[1<<MAXN];
long long v[1<<MAXN],ans=~(1LL<<63);

int main()
{
	memset(dp,0x3f,sizeof dp);dp[0][0]=0;
	scanf("%d %d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d %d %d",&w[i],&h[i],&q[i]);
	for (int i=0;i<(1<<n);i++)
	{
		for (int j=0;j<n;j++)
			if (i&(1<<j))
			{
				mw[i]=max(mw[i],(long long)w[j]);
				mh[i]=max(mh[i],(long long)h[j]);
				all[i]+=1LL*w[j]*h[j]*q[j];
				cnt[i]+=q[j];
			}
		v[i]=mw[i]*mh[i]*cnt[i]-all[i];
	}
	for (int i=1;i<=k;i++)
		for (int sta=0;sta<(1<<n);sta++)
		{
			long long t=0x3f3f3f3f3f3f3f3fLL;
			for (int j=sta;j;j=(j-1)&sta) t=min(t,dp[i-1][sta-j]+v[j]);
			dp[i][sta]=t;
		}
	for (int i=0;i<=k;i++) ans=min(ans,dp[i][(1<<n)-1]);
	printf("%lld\n",ans);
	return 0;
}