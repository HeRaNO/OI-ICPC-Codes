#include <bits/stdc++.h>
using namespace std;

int T;
long long a,m;

long long phi(long long x)
{
	long long r=x;
	for (long long i=2;i*i<=x;i++)
		if (!(x%i))
		{
			r/=i;r*=(i-1);
			while (!(x%i)) x/=i;
		}
	if (x!=1) r/=x,r*=(x-1);
	return r;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld %lld",&a,&m);
		printf("%lld\n",phi(m/__gcd(a,m)));
	}
	return 0;
}