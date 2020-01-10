#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

long long n,a=1;

int main()
{
	scanf("%lld",&n);long long p=n;
	for (long long i=2;i*i<=n;i++)
		if (!(n%i))
		{
			if (__gcd(i,n/i)==1) a=i;
		}
	printf("%lld %lld\n",n/a,a);
	return 0;
}