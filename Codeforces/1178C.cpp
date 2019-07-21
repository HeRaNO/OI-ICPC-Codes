#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

inline long long fpow(long long a,long long b,long long p)
{
	long long r=1;
	for (;b;a=(a*a)%p,b>>=1) if (b&1) r=(r*a)%p;
	return r;
}

int main()
{
	int w,h;
	scanf("%d %d",&w,&h);
	printf("%lld\n",fpow(2,w+h,998244353LL));
	return 0;
}