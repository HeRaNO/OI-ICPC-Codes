#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

const long long M=1e9+7;

int n,m,k;long long p,q;
long long fac[MAXN],inv[MAXN],invfac[MAXN];

inline long long qpow(long long a,long long b)
{
	if (a==1) return 1;
	if (!a) return 0;
	long long r=1;
	for (;b;a=(a*a)%M,b>>=1) if (b&1) r=(r*a)%M;
	return r;
}

inline void Get_Factor_and_Inv(int n)
{
	inv[1] = fac[0] = fac[1] = invfac[0] = invfac[1] = 1LL;
	for (int i = 2; i <= n; i++) inv[i] = (M - M / i) * inv[M % i] % M;
	for (int i = 2; i <= n; i++) fac[i] = (fac[i - 1] * i) % M, invfac[i] = (invfac[i - 1] * inv[i]) % M;
	return ;
}

inline long long stirling(int n,int m)
{
	if (n<m) return 0LL;
	long long ans=0LL;
	for (int k=0;k<=m;k++)
	{
		long long r=qpow(m-k,n);
		r=r*invfac[k]%M;
		r=r*invfac[m-k]%M;
		if (k&1) ans=(ans-r+M)%M;
		else (ans+=r)%=M;
	}
	return ans;
}

int main()
{
	Get_Factor_and_Inv(1000000);
	scanf("%d %d %d",&n,&m,&k);
	q=qpow(n*m,k-1)%M;
	p=stirling(k-1,n*m-1)*fac[n*m-1]%M;
	p+=stirling(k-1,n*m)*fac[n*m]%M;p%=M;
	printf("%lld\n",p*qpow(q,M-2)%M);
	return 0;
}