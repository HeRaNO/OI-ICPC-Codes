#include <bits/stdc++.h>
using namespace std;

const long long M=1e9+7;

int k,cnt=-1;
long long x,n=1;

inline long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,(a*=a)%=M) if (b&1) (r*=a)%=M;
	return r;
}

int main()
{
	scanf("%d",&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%lld",&x);
		if (!(x&1)) cnt=1;
		x%=(M-1);(n*=x)%=(M-1);
	}
	n=(n-1+M-1)%(M-1);
	long long p=fpow(2,n),q;q=p;
	p=(p+cnt+M)%M;(p*=333333336LL)%=M;
	printf("%lld/%lld\n",p,q);
	return 0;
}