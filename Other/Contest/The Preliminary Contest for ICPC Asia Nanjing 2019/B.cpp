#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

int T,p,b,n,pt;
long long MOD,a[MAXN];

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
	if (x==pt+1) return Quick_MOD(a[x],a[x-1],P);
	long long m=phi(P);
	return Quick_MOD(a[x],Solve(x-1,m)+m,P);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %lld",&p,&b,&MOD);
		if (MOD==1){puts("0");continue;}
		if (!b){puts("1");continue;}
		for (int i=1;i<=b;i++) a[i]=p;pt=1;
		while (pt<=b)
		{
			double p=a[pt],q=a[pt+1];
			if (p*log(q)<=13.00) a[pt+1]=Quick_MOD(a[pt+1],a[pt],1e18);
			else break;
			++pt;
		}
		if (pt==b+1) printf("%lld\n",a[b]%MOD);
		else printf("%lld\n",Solve(b,MOD));
	}
	return 0;
}