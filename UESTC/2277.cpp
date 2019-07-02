#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

long long n,m,f[MAXN],a[MAXN];
int p,q,x;
vector <long long> fac[MAXN];

long long qpow(long long a,long long b,long long m)
{
	long long r=1LL;
	for (;b;a=(a*a)%m,b>>=1LL) if (b&1) r=(r*a)%m;
	return r%m;
}

inline long long C(long long n,long long m,long long p)
{
	if (n<m) return 0LL;
	return fac[p][n]*qpow(fac[p][n-m]*fac[p][m]%f[p],f[p]-2,f[p])%f[p];
}

inline long long Lucas(long long n,long long m,long long p)
{
	if (!m) return 1LL;
	return Lucas(n/f[p],m/f[p],p)*C(n%f[p],m%f[p],p)%f[p];
}

long long exgcd(long long a, long long b, long long &x, long long &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long res = exgcd(b, a % b, x, y);
	long long t = x;
	x = y;
	y = t - (a / b) * y;
	return res;
}

inline long long CRT(int n)
{
	long long M = 1, ans = 0;
	for (int i = 1; i <= n; i++) M *= f[i];
	for (int i = 1; i <= n; i++)
	{
		long long w = M / f[i], x, y;
		exgcd(w, f[i], x, y);
		ans = (ans + x * w * a[i]) % M;
	}
	return (ans + M) % M;
}

int main()
{
	scanf("%lld %lld %d",&n,&m,&p);m%=p;x=p-1;q=x;
	for (int i=2;i*i<=x;i++)
		if (!(q%i))
		{
			f[++f[0]]=i;
			q/=i;
		}
	if (q!=1) f[++f[0]]=q;
	for (int i=1;i<=f[0];i++)
	{
		fac[i].push_back(1);
		for (int j=1;j<=f[i];j++) fac[i].push_back(1LL*fac[i][j-1]*j%f[i]);
	}
	for (int i=1;i*i<=n;i++)
		if (n%i==0)
		{
			for (int j=1;j<=f[0];j++)
			{
				a[j]=(a[j]+Lucas(n,i,j))%f[j];
				if (i*i!=n) a[j]=(a[j]+Lucas(n,n/i,j))%f[j];
			}
		}
	printf("%lld\n",qpow(m,CRT(f[0]),p));
	return 0;
}