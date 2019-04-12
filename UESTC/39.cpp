#include <cstdio>

bool coprime(long long a,long long b)
{
	long long p=a>b?a:b,q=a<b?a:b;
	if (!(p%q)) return false;
	for (long long i=2;i*i<=p;i++)
		if (!(p%i)&&!(q%i)) return false;
	return true;
}

int main()
{
	long long a,b;
	while (~scanf("%lld %lld",&a,&b)&&a&&b)
	{
		if (coprime(a,b)) printf("%lld\n",a*b-a-b);
		else puts("Inf");
	}
	return 0;
}
