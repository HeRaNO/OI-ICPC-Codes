#include <bits/stdc++.h>
#define MAXN 11
using namespace std;

const long long M=1e9+7;

int T,n,m;
long long f[MAXN][MAXN],C[MAXN][MAXN],_3[MAXN*MAXN];

inline void init()
{
	int n=10;_3[0]=1LL;
	for (int i=0;i<=n;i++)
	{
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
	}
	for (int i=1,p=n*n;i<=p;i++) _3[i]=_3[i-1]*3%M;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=n;j++)
		{
			f[i][j]=_3[i*j];long long r=0;
			for (int x=1;x<=i;x++)
				for (int y=0;y<=j;y++)
					if (i+j!=x+y)
					{
						r+=C[i-1][x-1]*C[j][y]*_3[(i-x)*(j-y)]%M*f[x][y]%M;
						if (r>=M) r-=M;
					}
			f[i][j]=f[i][j]+M-r;
			if (f[i][j]>=M) f[i][j]-=M;
		}
	return ;
}

int main()
{
	init();
	while (scanf("%d %d",&n,&m)==2) printf("%lld\n",f[n][m]);
	return 0;
}