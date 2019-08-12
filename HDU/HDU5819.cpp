#include <bits/stdc++.h>
typedef long long ll;
const int MAXN=1505;
using namespace std;

const int inv2=5e8+4,MOD=1e9+7;

ll dp[MAXN][MAXN];

int main()
{
	int T;
	cin>>T;
	int kase=T;
	while(kase--)
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int dir;
			scanf("%d",&dir);
			if(i==1)dir=1;
			if(i==n)dir=0;
			if(dir)
			{
				for(int j=1;j<=i;j++)
					dp[i][j]=dp[i-1][j-1];
			}
			else
			{
				for(int j=i-1;j>1;j--)
					dp[i][j]=(dp[i][j+1]+dp[i-1][j])%MOD*inv2%MOD;
				dp[i][1]=(dp[i][2]+dp[i-1][1])%MOD;
			}
		}
		printf("Case #%d: %lld\n",T-kase,dp[n][1]*inv2%MOD);
	}
	return 0;
}