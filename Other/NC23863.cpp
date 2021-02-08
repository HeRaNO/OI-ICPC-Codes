#include <bits/stdc++.h>
#define MAXN 18
using namespace std;

int n,ans,a[MAXN][MAXN],dp[1<<MAXN][MAXN];

inline void max(int &x,int y){if (x<y) x=y;return ;}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for (int i=0;i<n;i++) dp[1<<i][i]=a[i][i];
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<n;j++)
			if (i&(1<<j))
			{
				for (int k=0;k<n;k++)
					if (!(i&(1<<k)))
						max(dp[i|(1<<k)][k],dp[i][j]+a[k][j]);
			}
	for (int i=0;i<n;i++)
		max(ans,dp[(1<<n)-1][i]);
	printf("%d\n",ans);
	return 0;
}