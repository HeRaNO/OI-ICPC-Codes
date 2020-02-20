#include <bits/stdc++.h>
#define MAXK 100005
using namespace std;

const long long M=1e9+9;
const long long _is5=276601605;
const long long a=691504013;
const long long b=308495997;
const long long _s5=383008016;

long long n,ans;
long long fac[MAXK],inv[MAXK],invfac[MAXK],_5[MAXK];
long long A[MAXK],B[MAXK];
int T,k;

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

inline void init()
{
	fac[0]=inv[1]=invfac[0]=1;A[0]=B[0]=_5[0]=1;int n=1e5;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%M;
	for (int i=2;i<=n;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	for (int i=1;i<=n;i++) invfac[i]=invfac[i-1]*inv[i]%M;
	for (int i=1;i<=n;i++) A[i]=A[i-1]*a%M,B[i]=B[i-1]*b%M,_5[i]=_5[i-1]*_is5%M;
	return ;
}

int main()
{
	init();scanf("%d",&T);
	while (T--)
	{
		scanf("%lld %d",&n,&k);ans=0;
		for (int i=0;i<=k;i++)
		{
			long long now=C(k,i);if (i&1) now=M-now;
			long long q=A[k-i]*B[i]%M;
			if (q==1) (now*=n%M)%=M;
			else
			{
				long long r=fpow(q,n+1);
				r=(r-q+M)%M;(r*=fpow(q-1,M-2))%=M;
				(now*=r)%=M;
			}
			ans+=now;if (ans>=M) ans-=M;
		}
		printf("%lld\n",ans*_5[k]%M);
	}
	return 0;
}