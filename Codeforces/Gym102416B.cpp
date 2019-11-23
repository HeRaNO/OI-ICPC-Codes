#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x7fffffff,MAXM=2e6+10,MAXN=2e5+10;
const int MOD=1e9+7;
const ll llINF=~(1ll<<63);

double dp[55][1005][3];
double a[55][1005];

int main()
{
	int n,m;
	double d;
	cin>>n>>m>>d;
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			scanf("%lf",&a[i][j]);
	double maxn=d;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j][2]=maxn;
			for(int k=1;k<i;k++)
				dp[i][j][2]=max(dp[i][j][2],dp[k][j][1]*a[i][j]/a[k][j]);
		}
		for(int j=1;j<=m;j++)
			maxn=max(maxn,dp[i][j][2]);
		for(int j=1;j<=m;j++)
			dp[i][j][1]=maxn;
	}
	printf("%.2lf",maxn);
	return 0;
}

/*
4 2 10.00
1 10 10 10
2 5 100 100
*/