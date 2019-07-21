#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
 
const long long M=998244353LL;
 
int n,p;
long long a[MAXN],f[MAXN][11];
long long _10[20],ans;
 
int main()
{
	_10[0]=1;
	for (int i=1;i<=19;i++) _10[i]=_10[i-1]*10%M;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		int x=a[i],cnt=0;
		while (x)
		{
			f[i][cnt++]=x%10;
			x/=10;
		}
		p=cnt;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<p;j++)
		{
			ans=(ans+f[i][j]*_10[j<<1]%M)%M;
			ans=(ans+f[i][j]*_10[j<<1|1]%M)%M;
		}
	}
	printf("%llu\n",ans*n%M);
	return 0;
}