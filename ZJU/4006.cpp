#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

const int Z=1e5;
const long long M=1e9+7;

int T,n,m;
long long _2fac[MAXN],_4fac[MAXN],ans;
long long fac[MAXN],inv[MAXN],invfac[MAXN];

long long qpow(long long a,long long b)
{
	long long r=1;
	for (;b;a=(a*a)%M,b>>=1) if (b&1) r=(r*a)%M;
	return r;
}

inline long long C(int n,int m)
{
	return fac[n]*invfac[m]%M*invfac[n-m]%M;
}

int main()
{
	scanf("%d",&T);fac[0]=fac[1]=inv[1]=invfac[0]=invfac[1]=1LL;
	_2fac[0]=1;_2fac[1]=qpow(2,M-2);
	_4fac[0]=1;_4fac[1]=qpow(4,M-2);
	for (int i=2;i<=100000;i++)
	{
		fac[i]=(fac[i-1]*i)%M;
		inv[i]=(M-M/i)*inv[M%i]%M;
		invfac[i]=invfac[i-1]*inv[i]%M;
		_2fac[i]=_2fac[i-1]*_2fac[1]%M;
		_4fac[i]=_4fac[i-1]*_4fac[1]%M;
	}
	while (T--)
	{
		scanf("%d %d",&n,&m);
		if (m<0) m=-m;ans=0LL;
		for (int i=m;i<=(n+m)>>1;i++)
		{
			long long r=C(n,i)*_4fac[i]%M;
			r=(r*C(n-i,i-m)%M*_4fac[i-m])%M;
			r=(r*_2fac[n+m-i-i])%M;
			(ans+=r)%=M;
		}
		printf("%d\n",ans);
	}
	return 0;
}