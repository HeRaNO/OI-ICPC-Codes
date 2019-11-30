#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		long long n,k;
		scanf("%lld%lld",&n,&k);
		long long p=k/n;
		long long ans=(k%n)*(p+1)*(p+1)+(n-(k%n))*p*p;
		printf("%lld\n",ans);
	}
	return 0;
}