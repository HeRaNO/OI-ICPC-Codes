#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100005
using namespace std;

const long long s=723398404,r1=308495997,r2=691504013;
const int mod=1000000009;
const int modp1=1000000008;
const int pmod=31625;

int T,m;
long long n,c,inv[MAXN],invfac[MAXN],fac[MAXN],sk[MAXN];
long long pr1[pmod],qr1[pmod],pr2[pmod],qr2[pmod];

inline long long fpowr1(int x){return qr1[x/pmod]*pr1[x%pmod]%mod;}
inline long long fpowr2(int x){return qr2[x/pmod]*pr2[x%pmod]%mod;}
inline void fadd(long long &a,long long b){a+=b;if (a>=mod) a-=mod;return ;}
inline void faddc(long long &a,long long b){a+=b;if (a>=modp1) a-=modp1;return ;}

inline long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,(a*=a)%=mod) if (b&1) (r*=a)%=mod;
	return r;
}

inline long long acce(long long q,long long n)
{
	if (q==1) return n%mod;
	long long x=fpow(q,(n+1)%modp1);fadd(x,mod-q);
	return x*fpow(q-1,mod-2)%mod;
}

inline long long C(int n,int m)
{
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}

inline void init(int n)
{
	inv[1]=1;invfac[0]=1;fac[0]=1;sk[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	for (int i=2;i<=n;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for (int i=1;i<=n;i++) invfac[i]=invfac[i-1]*inv[i]%mod;
	for (int i=1;i<=n;i++) sk[i]=sk[i-1]*s%mod;
	pr1[0]=qr1[0]=1;
	for (int i=1;i<pmod;i++) pr1[i]=1LL*pr1[i-1]*r1%mod;
	long long r=pr1[pmod-1]*r1%mod;
	for (int i=1;i<pmod;i++) qr1[i]=1LL*qr1[i-1]*r%mod;
	pr2[0]=qr2[0]=1;
	for (int i=1;i<pmod;i++) pr2[i]=1LL*pr2[i-1]*r2%mod;
	r=1LL*pr2[pmod-1]*r2%mod;
	for (int i=1;i<pmod;i++) qr2[i]=1LL*qr2[i-1]*r%mod;
	return ;
}

int main()
{
	init(100000);
	scanf("%d",&T);
	while (T--)
	{
		long long ans=0;
		scanf("%lld%lld%d",&n,&c,&m);c%=modp1;
		long long x,y=0,z=m*c%modp1,q=modp1-c;
		for (int i=0;i<=m;i++)
		{
			x=C(m,i)*acce(fpowr1(y)*fpowr2(z)%mod,n)%mod;
			if ((m-i)&1) fadd(ans,mod-x);
			else fadd(ans,x);
			faddc(y,c);faddc(z,q);
		}
		printf("%lld\n",ans*sk[m]%mod);
	}
	return 0;
}