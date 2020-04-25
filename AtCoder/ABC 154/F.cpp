#include <bits/stdc++.h>
#define MAXN 2000005
using namespace std;

const long long M=1e9+7;

int a,b,c,d;
long long inv[MAXN],fac[MAXN],invfac[MAXN],ans;

inline void fadd(long long &a,long long b){a+=b;if (a>=M) a-=M;return ;}

inline long long C(int n,int m)
{
	return fac[n]*invfac[m]%M*invfac[n-m]%M;
}

int main()
{
	inv[0]=inv[1]=invfac[0]=fac[0]=1LL;
	for (int i=1;i<MAXN;i++) fac[i]=fac[i-1]*i%M;
	for (int i=2;i<MAXN;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	for (int i=1;i<MAXN;i++) invfac[i]=invfac[i-1]*inv[i]%M;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	for (int i=b;i<=d;i++)
	{
		long long t=C(i+c+1,i+1);
		fadd(t,M-C(i+a,i+1));
		fadd(ans,t);
	}
	printf("%lld\n",ans);
	return 0;
}