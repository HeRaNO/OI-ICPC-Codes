#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;

const long long M=1e9+7;

long long dp[MAXN][MAXN],ans,inv[MAXN];
int n,m;

inline void init()
{
	int n=5000;inv[1]=1LL;
	for (int i=2;i<=n;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		long long p=dp[i-1][i-1],q=dp[i-1][i-1]*(i-1)%M;
		for (int j=i;j<=n;j++)
		{
			dp[i][j]=(j*p-q+M)%M;
			(p+=dp[i-1][j])%=M;(q+=j*dp[i-1][j]%M)%=M;
		}
	}
	return ;
}

int main()
{
	init();
	while (~scanf("%d %d",&n,&m))
	{
		if (n<m) swap(n,m);ans=0;
		for (int i=1;i<=m;i++) ans=(ans+dp[i][n]*dp[i][m]%M*inv[i]%M)%M;
		printf("%lld\n",ans*(n+m)%M);
	}
	return 0;
}