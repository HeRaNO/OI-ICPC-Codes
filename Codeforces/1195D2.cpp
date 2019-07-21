#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
 
const long long M=998244353LL;
 
int n,p[MAXN],bu[20];
long long a[MAXN],f[MAXN][11],pre[20],suf[20];
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
		p[i]=cnt;
		++bu[cnt];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=10;j++)
		{
			if (p[i]<=j)
			{
				for (int k=0;k<j;k++)
				{
					ans=(ans+f[i][k]*_10[k<<1]%M*bu[j]%M)%M;
					ans=(ans+f[i][k]*_10[k<<1|1]%M*bu[j]%M)%M;
				}
			}
			else
			{
				int k=j,kk=0;long long t=a[i];
				while (k--)
				{
					long long x=t%10;
					ans=(ans+x*_10[kk]%M*bu[j]%M)%M;
					ans=(ans+x*_10[kk+1]%M*bu[j]%M)%M;
					kk+=2;t/=10;
				}
				while (t)
				{
					long long x=t%10;
					ans=(ans+x*_10[kk]%M*bu[j]%M)%M;
					ans=(ans+x*_10[kk]%M*bu[j]%M)%M;
					kk++;t/=10;
				}
			}
		}
	}
	printf("%lld\n",ans%M);
	return 0;
}