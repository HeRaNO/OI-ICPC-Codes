#include <bits/stdc++.h>
#define MAXN 15
using namespace std;

const long long M=1e9+7;

int T,n,m,a[MAXN][5];
bool vis[MAXN];

inline long long fpow(long long a,long long b)
{
	long long r=1;
	if (a==1) return 1LL;
	for (;b;b>>=1,a=(a*a)%M) if (b&1) r=(r*a)%M;
	return r;
}

inline long long getDet()
{
	memset(vis,0,sizeof vis);
	long long det=1;
	for (int i=1;i<=n;i++)
	{
		int now=0;
		for (int j=1;j<=m&&!now;j++) if (!vis[j]&&a[j][i]) now=j;
		if (!now) continue;
		if (now!=i) det=-det;
		vis[i]=true;
		for (int j=1;j<=m;j++) swap(a[now][j],a[i][j]);
		long long t=fpow(a[i][i],M-2);
		for (int j=1;j<=m;j++)
			if (j!=i)
			{
				long long x=a[j][i]*t%M;
				for (int k=1;k<=m;k++) 
				{
					a[j][k]-=x*a[i][k]%M;(a[j][k]+=M)%=M;
				}
			}
	}
	det=(det+M)%M;
	for (int i=1;i<=n;i++) (det*=a[i][i])%=M;
	return det;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				scanf("%d",&a[j][i]);
		if (n>m) puts("YES");
		else puts(getDet()?"NO":"YES");
	}
	return 0;
}