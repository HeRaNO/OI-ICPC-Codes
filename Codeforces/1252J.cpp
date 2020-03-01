#include <bits/stdc++.h>
#define MAXK 55
#define MAXN 100005
using namespace std;

int n,K,a,b,c,cnt=1,A[MAXK];
int dp[MAXK][MAXN][2],ans;
char s[MAXN];

inline void chkmax(int &a,int b){if (a<b) a=b;return ;}

int main()
{
	memset(dp,-1,sizeof dp);
	scanf("%d %d %d %d %d",&n,&K,&a,&b,&c);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='#') ++cnt;
		else ++A[cnt];
	}
	while (cnt&&!A[cnt]) --cnt;
	dp[0][0][0]=0;
	for (int i=1;i<=cnt;i++)
		for (int j=0;j<=K;j++)
			for (int k=0,p=min(A[i],j);k<=p;k++)
			{
				if (A[i]>=k&&~dp[i-1][j-k][0]) chkmax(dp[i][j][0],dp[i-1][j-k][0]+(A[i]-k)/2*b+k*a);
				if (A[i]>=k+1&&~dp[i-1][j-k][1]) chkmax(dp[i][j][0],dp[i-1][j-k][1]+(A[i]-k-1)/2*b+c+k*a);
				if (A[i]>=k+1&&~dp[i-1][j-k][0]) chkmax(dp[i][j][1],dp[i-1][j-k][0]+(A[i]-k-1)/2*b+k*a);
				if (A[i]>=k+2&&~dp[i-1][j-k][1]) chkmax(dp[i][j][1],dp[i-1][j-k][1]+(A[i]-k-2)/2*b+c+k*a);
			}
	for (int i=0;i<=K;i++) chkmax(ans,dp[cnt][i][0]);
	printf("%d\n",ans);
	return 0;
}