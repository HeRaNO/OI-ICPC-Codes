#include <cstdio>
using namespace std;

inline long long fpow(long long a,long long b,long long p)
{
	long long r=1;a%=p;
	for (;b;b>>=1,a=(a*a)%p) if (b&1) r=(r*a)%p;
	return r%p;
}

int main()
{
	long long r,t,m;
	while (~scanf("%lld %lld %lld",&r,&t,&m)) printf("%lld\n",fpow(m,t,r));
	return 0;
}
