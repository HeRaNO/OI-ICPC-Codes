#include <bits/stdc++.h>
using namespace std;

long long a,b,x,y;

int main()
{
	scanf("%lld %lld %lld %lld",&a,&b,&x,&y);
	long long t=__gcd(x,y);
	x/=t;y/=t;
	printf("%lld\n",min(a/x,b/y));
	return 0;
}