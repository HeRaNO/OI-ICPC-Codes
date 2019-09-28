#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1e4+10,MAXM=1e6+10;
const int MOD=1e8+7,INF=~(1<<31);
const ll llINF=((1ll<<61));

ll dp[MAXN][3][3];
int a[MAXN];
char s[MAXN];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;i++)
			a[i]=s[i]-'0';
		memset(dp,0,sizeof(dp));
		if(a[1]==0)
			dp[2][0][0]=1;
		if(a[1]==1)
			dp[2][0][1]=dp[2][1][0]=2;
		if(a[1]==2)
			dp[2][0][2]=dp[2][2][0]=1,dp[2][1][1]=4;
		if(a[1]==3)
			dp[2][1][2]=dp[2][2][1]=2;
		if(a[1]==4)dp[2][2][2]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<=2;j++)
				for(int k=0;k<=2;k++)
					for(int p=0;p<=2;p++)
						if(j+k+p==a[i])
							dp[i+1][j][k]=dp[i][p][j];
			(dp[i+1][0][1]*=2)%=MOD;
			(dp[i+1][1][1]*=2)%=MOD;
			(dp[i+1][2][1]*=2)%=MOD;
		}
		printf("%lld\n",((dp[n+1][0][0]+dp[n+1][1][0])%MOD+dp[n+1][2][0])%MOD);
	}
	return 0;
}
