#include <bits/stdc++.h>
#define MAXN 16
using namespace std;

int n,a[MAXN],r[MAXN],b[MAXN],ans=~(1<<31);
int sr,sb,cr[1<<MAXN],cb[1<<MAXN],dp[1<<MAXN][240];
char s[3];

int main()
{
	scanf("%d",&n);memset(dp,-1,sizeof dp);dp[0][0]=0;
	for (int i=0;i<n;i++)
	{
		scanf("%s %d %d",s,&r[i],&b[i]);
		a[i]=s[0]=='R'?0:1;
		sr+=r[i];sb+=b[i];
	}
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<n;j++)
			if (i&(1<<j))
				a[j]?++cb[i]:++cr[i];
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<=120;j++)
		{
			if (!~dp[i][j]) continue;
			for (int k=0;k<n;k++)
				if (!(i&(1<<k)))
					dp[i|(1<<k)][j+min(r[k],cr[i])]=max(dp[i|(1<<k)][j+min(r[k],cr[i])],dp[i][j]+min(b[k],cb[i]));
		}
	for (int j=0;j<=120;j++)
		if (~dp[(1<<n)-1][j])
			ans=min(ans,max(sr-j,sb-dp[(1<<n)-1][j]));
	printf("%d\n",ans+n);
	return 0;
}