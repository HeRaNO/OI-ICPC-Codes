#include <cstdio>
using namespace std;
int main()
{
	long long n;scanf("%lld",&n);
	for (long long i=1;i<=n;i++)
		if (((i*(i+1))/2)%n==0)
		{
			printf("%lld\n",i);return 0;
		}
	return 0;
}
