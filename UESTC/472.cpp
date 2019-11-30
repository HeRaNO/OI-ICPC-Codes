#include <bits/stdc++.h>
using namespace std;

const long long M=1e9+7;

int a,b,c;

inline long long fpow(long long a,long long b,long long p)
{
	long long r=1;
	for (;b;b>>=1,(a*=a)%=p) if (b&1) (r*=a)%=p;
	return r;
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d %d %d",&a,&b,&c))
		printf("%lld\n",fpow(a,fpow(b,c,M-1),M));
	return 0;
}