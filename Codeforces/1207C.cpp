#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

const long long INF=1e18;

int T,n,a,b;
char s[MAXN];
long long f[MAXN][2];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&n,&a,&b);
		scanf("%s",s+1);
		f[0][0]=b;f[0][1]=INF;
		for (int i=1;i<=n;i++)
		{
			if (s[i]&1)
			{
				f[i][0]=INF;
				f[i][1]=f[i-1][1]+a+(b<<1);
			}
			else
			{
				f[i][0]=min(f[i-1][0]+a,f[i-1][1]+(a<<1))+b;
				f[i][1]=min(f[i-1][1]+a,f[i-1][0]+(a<<1))+(b<<1);
			}
		}
		printf("%lld\n",f[n][0]);
	}
	return 0;
}