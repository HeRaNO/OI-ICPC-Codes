#include <cmath>
#include <cstdio>
#define MAXN 55
using namespace std;

int n;long long MOD;

inline long long mul(long long a,long long b,long long P)
{
	long long r=0LL;
	for (;b;(a<<=1LL)%=P,b>>=1LL) if (b&1) (r+=a)%=P;
	return r;
}

inline long long Quick_MOD(long long a,long long b,long long P)
{
	long long r=1LL;
	for (;b;a=mul(a,a,P),b>>=1LL) if (b&1) r=mul(r,a,P);
	return r;
}

inline long long phi(long long x)
{
	long long res=x;
	for (long long i=2;i*i<=x;i++)
		if (!(x%i)){res/=i;res*=(i-1);while (!(x%i)) x/=i;}
	if (x!=1) res/=x,res*=(x-1);
	return res;
}

inline long long Solve(int x,long long P)
{
	if (P==1) return 0LL;
	if (x==5) return Quick_MOD(5,262144,P);
	long long m=phi(P);
	return Quick_MOD(x,Solve(x-1,m)+m,P);
}

int main()
{
	scanf("%d",&n);scanf("%lld",&MOD);
	if (n==1) printf("%lld\n",1%MOD);
	else if (n==2) printf("%lld\n",2%MOD);
	else if (n==3) printf("%lld\n",9%MOD);
	else if (n==4) printf("%lld\n",262144%MOD);
	else printf("%lld\n",Solve(n,MOD));
	return 0;
}