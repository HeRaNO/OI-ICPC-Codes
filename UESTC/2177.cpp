#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

char a[MAXN];
int T,k,n,m,dp[MAXN][26],cnt[MAXN],ap[MAXN],ans;

inline int f(int x){return x?1:0;}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(ap,0,sizeof ap);memset(dp,0x7f,sizeof dp);ans=~(1<<31);
		scanf("%d",&k);scanf("%s",a);n=strlen(a);m=n/k;
		for (int i=0;i<n;i+=k)
		{
			for (int j=i;j<i+k;j++) ap[i/k]|=(1<<(a[j]-'a'));
			cnt[i/k]=__builtin_popcount(ap[i/k]);
		}
		for (int i=0;i<26;i++)
			if (ap[0]&(1<<i)) dp[0][i]=cnt[0];
		for (int i=1;i<m;i++)
		{
			if (cnt[i]==1)
			{
				int p=-1;
				for (int j=0;j<26&&!~p;j++) if (ap[i]&(1<<j)) p=j;
				for (int k=0;k<26;k++)
					if ((ap[i-1]&(1<<k)))
						dp[i][p]=min(dp[i][p],dp[i-1][k]+cnt[i]-f(ap[i]&(1<<k)));
			}
			for (int j=0;j<26;j++)
				if (ap[i]&(1<<j))
				{
					for (int k=0;k<26;k++)
						if ((ap[i-1]&(1<<k))&&k!=j)
							dp[i][j]=min(dp[i][j],dp[i-1][k]+cnt[i]-f(ap[i]&(1<<k)));
				}
		}
		for (int i=0;i<26;i++) ans=min(ans,dp[m-1][i]);
		printf("%d\n",ans);
	}
	return 0;
}