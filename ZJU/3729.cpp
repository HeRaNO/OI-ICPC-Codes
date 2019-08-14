#include <bits/stdc++.h>
#define MAXN 400005
using namespace std;

unsigned long long n;

struct Matrix
{
	unsigned long long m[2][2];
	Matrix(){
		m[0][0]=1;m[0][1]=0;
		m[1][0]=0;m[1][1]=1;
	}
};

Matrix A;
unsigned long long prime[MAXN],p[MAXN],cnt[MAXN],tot,fac[MAXN],l;
bool not_prime[MAXN];

unsigned long long gcd(unsigned long long a,unsigned long long b)
{
	return !b?a:gcd(b,a%b);
}

Matrix mul (Matrix &a,Matrix &b,unsigned long long p)
{
	Matrix res;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
		{
			res.m[i][j]=0;
			for (int k=0;k<2;k++) (res.m[i][j]+=a.m[i][k]*b.m[k][j]%p)%=p;
		}
	return res;
}

inline Matrix fpow(Matrix a,unsigned long long b,unsigned long long p)
{
	Matrix r;
	for (;b;b>>=1,a=mul(a,a,p)) if (b&1) r=mul(r,a,p);
	return r;
}

inline unsigned long long fpow(unsigned long long a,unsigned long long b,unsigned long long p)
{
	long long r=1;
	for (;b;b>>=1,a=(a*a)%p) if (b&1) r=(r*a)%p;
	return r%p;
}

inline void linearShaker()
{
	int n=4e5;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i;
		for (int j=1;i*prime[j]<=n;j++)
		{
			 not_prime[i*prime[j]]=true;
			 if (!(i%prime[j])) break;
		}
	}
	return ;
}

inline bool legendre(unsigned long long a,unsigned long long p)
{
	return fpow(a,(p-1)>>1,p)==1;
}

inline void fact(unsigned long long n)
{
	p[0]=0;unsigned long long x=n;
	for (int i=1;prime[i]*prime[i]<=x;i++)
	{
		if (n%prime[i]) continue;
		unsigned long long c=0;
		while (!(n%prime[i])) n/=prime[i],++c;
		p[++p[0]]=prime[i];
		cnt[p[0]]=c;
		if (n==1) break;
	}
	if (n!=1)
	{
		p[++p[0]]=n;
		cnt[p[0]]=1;
	}
	return ;
}

inline void get(unsigned long long n)
{
	l=0;
	for (long long i=1;i*i<=n;i++)
		if (!(n%i))
		{
			if (i*i==n) fac[++l]=i;
			else
			{
				fac[++l]=i;fac[++l]=n/i;
			}
		}
	sort(fac+1,fac+l+1);
	return ;
}

inline unsigned long long findLoop(unsigned long long n)
{
	fact(n);unsigned long long ans=1;
	for (int i=1;i<=p[0];i++)
	{
		unsigned long long t=1;
		if (p[i]==2) t=3;
		else if (p[i]==3) t=8;
		else if (p[i]==5) t=20;
		else
		{
			if (legendre(5,p[i])) get(p[i]-1);
			else get(2*(p[i]+1));
			for (int j=1;j<=l;j++)
			{
				Matrix a=fpow(A,fac[j]-1,p[i]);
				long long x=(a.m[0][0]%p[i]+a.m[0][1]%p[i])%p[i];
				long long y=(a.m[1][0]%p[i]+a.m[1][1]%p[i])%p[i];
				if (x==1&&y==0)
				{
					t=fac[j];break;
				}
			}
		}
		for (int j=1;j<cnt[i];j++) t*=p[i];
		ans=ans/gcd(ans,t)*t;
	}
	return ans;
}

int main()
{
	A.m[0][0]=1;A.m[0][1]=1;A.m[1][0]=1;A.m[1][1]=0;
	linearShaker();
	while (~scanf("%llu",&n)) printf("%llu\n",findLoop(n)>>1);
	return 0;
}
