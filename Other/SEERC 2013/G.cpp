#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+10;
const int INF=0x7ffffff;

int n,a[MAXN],b[MAXN],c[MAXN];
int dp[MAXN][2][4];

inline void solve()
{
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	if(n==1)
	{
		printf("%d\n",a[1]);
		return ;
	}
	dp[1][0][1]=a[1];
	dp[1][0][2]=b[1];
	dp[1][0][3]=-INF;
	for(int j=0;j<=3;j++)
		dp[1][1][j]=-INF;
	for(int i=2;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			dp[i][0][0]=max(dp[i][0][0],dp[i-1][j][0]);
			dp[i][0][1]=max(dp[i][0][1],dp[i-1][j][0]+a[i]);
			dp[i][0][2]=max(dp[i][0][2],dp[i-1][j][0]+b[i]);
		}
		dp[i][1][0]=max(dp[i][1][0],dp[i-1][0][1]);
		dp[i][1][0]=max(dp[i][1][0],dp[i-1][1][2]);
		dp[i][1][2]=max(dp[i][1][2],dp[i-1][1][3]+b[i]);
		dp[i][1][3]=max(dp[i][1][3],dp[i-1][1][3]+c[i]);
		dp[i][1][3]=max(dp[i][1][3],dp[i-1][0][2]+c[i]);
	}
	dp[n][1][2]=max(dp[n][1][2],dp[n-1][1][3]);
	dp[n][1][2]=max(dp[n][1][2],dp[n-1][0][2]);
	dp[n][1][2]+=b[n];
	dp[n][0][1]=max(dp[n-1][1][0],dp[n][0][1]);
	dp[n][0][1]=max(dp[n-1][0][0],dp[n][0][1]);
	dp[n][0][1]+=a[n];
	dp[n][1][0]=max(dp[n][1][0],dp[n-1][0][1]);
	dp[n][1][0]=max(dp[n][1][0],dp[n-1][1][2]);
	printf("%d\n",max(max(dp[n][0][1],dp[n][1][2]),dp[n][1][0]));
	return ;
}

int main()
{
	while (~scanf("%d",&n)) solve();
	return 0;
}
