#include <bits/stdc++.h>
#define MAXN 2000005
using namespace std;

const long long M=998244353;
long long fac[MAXN];
int n;

inline long long sqr(long long x){return x*x%M;}
inline long long inv(long long a)
{
	long long b=M-2,r=1;
	for (;b;b>>=1,(a*=a)%=M) if (b&1) (r*=a)%=M;
	return r;
}

int main()
{
	fac[0]=1;
	for (int i=1;i<=2000002;i++) fac[i]=fac[i-1]*i%M;
	while (scanf("%d",&n)==1) printf("%lld\n",sqr(fac[n])*inv(fac[n<<1|1])%M);
	return 0;
}