#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

const long long M=1e9+7;

long long c[MAXN][MAXN],f[MAXN][MAXN],g[MAXN][MAXN],fac[MAXN];
int n,m,k;

inline void prework()
{
	c[0][0]=1;
	for (int i=1;i<=1000;i++)
	{
		c[i][0]=c[i][i]=1LL;
		for (int j=1;j<i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%M;
	}
	f[0][0]=g[0][0]=1LL;
	for (int i=1;i<=1000;i++)
	{
		f[i][0]=0;f[i][i]=1;
		for (int j=1;j<i;j++) f[i][j]=(f[i-1][j-1]+j*f[i-1][j]%M)%M;
	}
	for (int i=1;i<=1000;i++)
	{
		//g[i][i]=1;
		for (int j=1;j<=1000;j++)
		{
			if (j<=i) g[i][j]=(g[i-1][j-1]+g[i-j][j])%M;
			else g[i][j]=g[i-1][j-1];
		}
	}
	fac[0]=fac[1]=1;
	for (int i=2;i<=1000;i++) fac[i]=fac[i-1]*i%M;
	return ;
}

int main()
{
	prework();
	while (scanf("%d %d %d",&n,&m,&k)!=-1)
	{
		if (n*m>k) printf("0 0 0 0\n");
		else printf("%lld %lld %lld %lld\n",fac[m*n]*f[k][m*n]%M,c[k-1][n*m-1],f[k][n*m],g[k][n*m]);
	}
	return 0;
}
