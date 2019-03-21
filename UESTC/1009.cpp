#include <cstdio>
using namespace std;

int n,T;

long long fp(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,a=(a*a)%10) if (b&1) r=(r*a)%10;
	return r;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);printf("%lld\n",fp(n,n));
	}
	return 0;
}
