#include <cstdio>

using i128 = __int128;

i128 sum_i(long long n)
{
	return (i128)n*(n+1)/2;
}

i128 sum_i2(long long n)
{
	return (i128)n*(n+1)*(2*n+1)/6;
}

const long long M=1000000000000000000LL;

void writeln(i128 x)
{
	if (x<M) printf("%lld\n",(long long)x);
	else printf("%lld%018lld\n",(long long)(x/M),(long long)(x%M));
	return ;
}

void Solve()
{
	long long n;scanf("%lld",&n);
	i128 ans=0;
	for (long long l=1,r;l<=n;l=r+1)
	{
		r=n/(n/l);
		ans+=(sum_i(r)-sum_i(l-1))*(n+1)*(n/l);
		ans-=(sum_i2(r)-sum_i2(l-1))*sum_i(n/l);
	}
	writeln((i128)n*n*(n+1)/2-ans);
	return ;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--) Solve();
	return 0;
}