#include <bits/stdc++.h>
#define MAXN 45005
using namespace std;

const long long M=1e9+7;

int T,n;
int ans[]={1,1,2,3,4,6,8,12};
long long inv[MAXN],fac[MAXN],invfac[MAXN];

inline long long f(long long m){return m*(m+1)/2;}

int main()
{
	inv[1]=1;fac[1]=1;fac[0]=1;invfac[0]=1;
	for (int i=2;i<=45000;i++)
	{
		inv[i]=(M-M/i)*inv[M%i]%M;
		fac[i]=fac[i-1]*i%M;
	}
	for (int i=1;i<=45000;i++) invfac[i]=invfac[i-1]*inv[i]%M;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		if (n<=7) printf("%d\n",ans[n]);
		else
		{
			int l=1,r=45000,p;
			while (l<=r)
			{
				int m=l+r>>1;
				if (f(m)<=n){p=m;l=m+1;}
				else r=m-1;
			}
			l=n-f(p);
			if (l<=p-2) printf("%lld\n",fac[p+1]*inv[p-l]%M);
			else if (l==p-1) printf("%lld\n",fac[p]*(p+2)%M*inv[2]%M);
			else printf("%lld\n",fac[p+1]);
		}
	}
	return 0;
}