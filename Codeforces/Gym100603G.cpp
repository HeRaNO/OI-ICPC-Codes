#include <bits/stdc++.h>
#define MAXN 605
using namespace std;

int n,k,a[MAXN][MAXN],dp[MAXN][MAXN],pre[MAXN][MAXN];
vector <int> ans;

int sum(int x,int y,int p,int q)
{
	return a[p][q]-a[x-1][q]-a[p][y-1]+a[x-1][y-1];
}

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j]+=a[i][j-1];
	for (int j=1;j<=n;j++)
		for (int i=1;i<=n;i++)
			a[i][j]+=a[i-1][j];
	for (int j=1;j<=n;j++) dp[1][j]=sum(1,j,j-1,n);
	for (int i=1;i<=k;i++)
		for (int j=i+1;j<=n;j++)
			for (int p=2;p<j;p++)
			{
				if (dp[i][j]<=dp[i-1][p]+sum(p,j,j-1,n))
				{
					dp[i][j]=dp[i-1][p]+sum(p,j,j-1,n);
					pre[i][j]=p;
				}
			}
	int mx=0;
	for (int i=1;i<=n;i++) if (dp[k][i]>=dp[k][mx]) mx=i;
	for (int i=k;i;i--)
	{
		ans.push_back(mx);
		mx=pre[i][mx];
	}
	sort(ans.begin(),ans.end());
	for (auto i:ans) printf("%d ",i-1);puts("");
	return 0;
}