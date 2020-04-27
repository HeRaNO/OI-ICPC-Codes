#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

const long long M=998244353;

int n;
long long k,ans,fac[MAXN],inv[MAXN],invfac[MAXN];

inline long long C(int n,int m)
{
	return fac[n]*invfac[m]%M*invfac[n-m]%M;
}

inline long long A(int n,int m)
{
	return fac[n]*invfac[n-m]%M;
}

inline long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,(a*=a)%=M) if (b&1) (r*=a)%=M;
	return r;
}

inline long long stirling(int n,int m)
{
	if (n<m) return 0LL;
	long long ans=0LL;
	for (int k=0;k<=m;k++)
	{
		long long r=fpow(m-k,n);
		r=r*invfac[k]%M;
		r=r*invfac[m-k]%M;
		if (k&1) ans=(ans-r+M)%M;
		else (ans+=r)%=M;
	}
	return ans;
}

int main()
{
	scanf("%d %lld",&n,&k);
	if (k>=n) return puts("0"),0;
	fac[0]=inv[0]=inv[1]=invfac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%M;
	for (int i=2;i<=n;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	for (int i=1;i<=n;i++) invfac[i]=invfac[i-1]*inv[i]%M;
	if (!k) return printf("%lld\n",fac[n]),0;
	ans=stirling(n,n-k);
	(ans*=A(n,n-k))%=M;
	printf("%lld\n",ans*2%M);
	return 0;
}