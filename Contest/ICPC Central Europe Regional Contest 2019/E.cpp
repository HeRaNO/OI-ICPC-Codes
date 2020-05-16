#include <bits/stdc++.h>
using namespace std;

long long f(long long x)
{
	if (x<=0) return 0;
	long long S=0,mx=0;
	for (long long i=1;i*i<=x;i++) S+=x/i,mx=max(mx,i);
	return 2*S-mx*mx;
}

int main()
{
	long long l,r;
	scanf("%lld %lld",&l,&r);
	printf("%lld\n",f(r)-f(l-1));
	return 0;
}
