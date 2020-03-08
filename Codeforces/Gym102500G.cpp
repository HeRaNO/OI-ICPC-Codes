#include <bits/stdc++.h>
#define MAXN 505
using namespace std;

int n,k;
long double p[MAXN],C[MAXN][MAXN];

inline void init()
{
	for (int i=0;i<=n;i++)
	{
		C[i][0]=C[i][i]=1.0;
		for (int j=1;j<i;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	return ;
}

int main()
{
	scanf("%d %d",&n,&k);init();
	for (int i=0;i<n;i++) scanf("%Lf",&p[i]);
	for (int i=0;i<n;i++)
	{
		long double ans=0;
		for (int j=0;j<=n-k;j++)
			ans+=C[n-1-j][k-1]*p[(i-j+n)%n];
		printf("%.10Lf%c",ans/C[n][k],i==n-1?'\n':' ');
	}
	return 0;
}