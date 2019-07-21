#include <bits/stdc++.h>
#define MAXN 155
using namespace std;

const long long M=1e9+7;

int n,m,k,u,v,w;

struct matrix
{
	long long m[MAXN][MAXN],a[MAXN][MAXN];
	matrix operator * (const matrix &p)const{
		matrix res;
		memset(res.m,0x3f,sizeof res.m);
		memset(res.a,0,sizeof res.a);
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
				{
					if (res.m[i][j]>m[i][k]+p.m[k][j])
					{
						res.m[i][j]=m[i][k]+p.m[k][j];
						res.a[i][j]=(a[i][k]*p.a[k][j])%M;
					}
					else if (res.m[i][j]==m[i][k]+p.m[k][j])
						(res.a[i][j]+=(a[i][k]*p.a[k][j])%M)%=M;
				}
		return res;
	}
}r,g;

int main()
{
	memset(g.m,0x3f,sizeof g.m);memset(g.a,0,sizeof g.a);
	scanf("%d %d %d",&n,&m,&k);
	r=g;for (int i=1;i<=n;i++) r.a[i][i]=1,r.m[i][i]=0;
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		g.m[u][v]=g.m[v][u]=w;
		g.a[u][v]=g.a[v][u]=1;
	}
	for (;k;k>>=1,g=g*g) if (k&1) r=r*g;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			if (!r.a[i][j])
			{
				printf("X 0%c",j==n?'\n':' ');
			}
			else
			{
				printf("%lld %lld%c",r.m[i][j],r.a[i][j],j==n?'\n':' ');
			}
		}
	return 0;
}