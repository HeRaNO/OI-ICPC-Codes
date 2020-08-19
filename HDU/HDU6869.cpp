#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		long long a,b,k;
		scanf("%lld %lld %lld",&a,&b,&k);++k;
		if (a>b) swap(a,b);
		long long c=b-a;
		if (c%k)
		{
			puts("1");
			continue;
		}
		c/=k;
		double r=(2-k+sqrt(k*k+4))/2;
		double s=(2+k+sqrt(k*k+4))/2;
		long long t1=(long long)(r*c),t2=(long long)(s*c);
		if (t1==a&&t2==b) puts("0");
		else puts("1");
	}
	return 0;
}