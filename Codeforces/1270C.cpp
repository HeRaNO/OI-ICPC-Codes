#include <bits/stdc++.h>
using namespace std;

int n,x,T;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		long long p=0,q=0;
		for (int i=1;i<=n;i++) scanf("%d",&x),p+=x,q^=x;
		puts("3");
		long long ans=1e18;
		if (p&1)
		{
			long long k=ans;--k;
			p+=k;q^=k;q<<=1;
			printf("%lld %lld %lld\n",k,(q-p)>>1,(q-p)>>1);
		}
		else
		{
			p+=ans;q^=ans;q<<=1;
			printf("%lld %lld %lld\n",ans,(q-p)>>1,(q-p)>>1);
		}
	}
	return 0;
}