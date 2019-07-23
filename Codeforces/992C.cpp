#include <bits/stdc++.h>
using namespace std;

const long long M=1e9+7;

long long x,k;

long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;a=(a*a)%M,b>>=1) if (b&1) r=(r*a)%M;
	return r;
}

int main()
{
	scanf("%lld %lld",&x,&k);
	if (!x) return puts("0"),0;
	x%=M;
	long long ans=fpow(2,k+1);
	ans=(ans*x)%M;
	long long p=fpow(2,k);
	ans=(ans-p+1+M)%M;
	printf("%lld\n",ans);
	return 0;
}