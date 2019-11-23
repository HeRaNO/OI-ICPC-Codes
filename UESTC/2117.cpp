#include <bits/stdc++.h>
using namespace std;

const long long M=1000000007LL;

int n,T;long long a,b;

long long fp(long long a,int n)
{
	long long r=1;
	for (;n;n>>=1,a=(a*a)%M) if (n&1) r=(r*a)%M;
	return r;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %lld %lld",&n,&a,&b);
		long long x=fp(a,n+1);
		long long y=fp(b,n+1);
		long long z=(x-y+M)%M;
		long long q=fp(a-b,M-2);
		printf("%lld\n",z*q%M);
	}
	return 0;
}