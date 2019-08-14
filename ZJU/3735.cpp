#include <bits/stdc++.h>
#define MAXM 130
#define MAXN 10005
using namespace std;

const int C[]={0,0,0,1,4,10,20,35,56,84,120};

int n,m;
double a[MAXM][MAXM],dp[MAXN][MAXM];
int p[MAXN];

int main()
{
	while (~scanf("%d",&n))
	{
		memset(dp,0,sizeof dp);
		for (int i=0;i<C[n];i++)
			for (int j=0;j<C[n];j++)
				scanf("%lf",&a[i][j]);
		scanf("%d",&m);
		for (int i=1;i<=m;i++) scanf("%d",&p[i]);
		for (int i=0;i<C[n];i++) dp[0][i]=1;
		for (int i=1;i<=m;i++)
			for (int j=0;j<C[n];j++)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j]*a[j][p[i]]);
				dp[i][p[i]]=max(dp[i][p[i]],dp[i-1][j]*a[j][p[i]]);
			}
		double ans=0.0;
		for (int i=0;i<C[n];i++) ans=max(ans,dp[m][i]);
		printf("%.8lf\n",ans);
	}
	return 0;
}