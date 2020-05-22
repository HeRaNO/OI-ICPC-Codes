#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

const long long M=998244353;

int n;
long long ans,inv[MAXN],fac[MAXN],invfac[MAXN],_3[MAXN];
long long ans2;

inline long long C(int n,int m)
{
	return fac[n]*invfac[m]%M*invfac[n-m]%M;
}

inline long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,(a*=a)%=M) if (b&1) (r*=a)%=M;
	return r;
}

int main()
{
	scanf("%d",&n);fac[0]=inv[1]=invfac[0]=_3[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%M;
	for (int i=2;i<=n;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	for (int i=1;i<=n;i++) invfac[i]=invfac[i-1]*inv[i]%M;
	for (int i=1;i<=n;i++) _3[i]=_3[i-1]*3%M;
	for (int i=0;i<n;i++)
	{
		long long t=C(n,i);
		if (!(i&1)) t=M-t;
		long long q=fpow((1+M-_3[i])%M,n);
		q=q+M-fpow(M-_3[i],n);q%=M;
		(ans+=t*q%M)%=M;
	}
	(ans*=3)%=M;
	for (int i=1;i<=n;i++)
	{
		long long t=C(n,i);
		if (!(i&1)) t=M-t;
		long long q=fpow(3,1LL*n*n-1LL*n*i+i);
		(ans2+=t*q%M)%=M;
	}
	(ans2<<=1)%=M;
	printf("%lld\n",(ans+ans2)%M);
	return 0;
}