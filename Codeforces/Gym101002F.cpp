#include <bits/stdc++.h>
#define MAXN 10005
#define MAXW 105
using namespace std;

const int M=1e9+7;
int n,w,h,dp[MAXW][MAXN],ans;

int main()
{
	scanf("%d %d %d",&n,&w,&h);
	dp[0][0]=1;
	for (int i=1;i<=w;i++)
		for (int j=0;j<=n;j++)
			if (dp[i-1][j])
			{
				for (int k=0;k<=h&&j+k<=n;k++)
					(dp[i][j+k]+=dp[i-1][j])%=M;
			}
	for (int i=0;i<=n;i++) (ans+=dp[w][i])%=M;
	for (int i=0;i<=h;i++) if (i*w<=n) --ans;
	printf("%d\n",(ans+M)%M);
	return 0;
}