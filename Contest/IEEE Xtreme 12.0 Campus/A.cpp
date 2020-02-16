#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

const long long M=1e9+7;

long long a,m,inv[MAXN*2],fac[MAXN*2],invfac[MAXN*2],ans;
int n,T,kas;

long long fpow(long long a,long long b)
{
	long long res=1,base=a;
	while (b)
	{
		if (b&1) res=(res*base)%M;
		base=(base*base)%M;
		b>>=1;
	}
	return res%M;
}

inline long long C(int n,int m)
{
	if (n<m) return 0LL;
	return fac[n]*invfac[m]%M*invfac[n-m]%M;
}

int main()
{
	inv[1]=fac[1]=invfac[0]=invfac[1]=1LL;
	for (int i=2;i<MAXN*2;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	for (int i=2;i<MAXN*2;i++) fac[i]=(fac[i-1]*i)%M,invfac[i]=(invfac[i-1]*inv[i])%M;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld %d",&a,&n);ans=0;
		if (n==1)
		{
			scanf("%lld",&m);
			scanf("%lld",&m);
			printf("case %d: %lld\n",++kas,m);
			continue;
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%lld",&m);
			if (i==1) continue;
			ans+=m*C(2*n-i-2,n-i)%M*fpow(a,2*n-i-1)%M;
			ans%=M;
		}
		for (int i=1;i<=n;i++)
		{
			scanf("%lld",&m);
			if (i==1) continue;
			ans+=m*C(2*n-i-2,n-i)%M*fpow(a,2*n-i-1)%M;
			ans%=M;
		}
		printf("case %d: %lld\n",++kas,ans);
	}
	return 0;
}