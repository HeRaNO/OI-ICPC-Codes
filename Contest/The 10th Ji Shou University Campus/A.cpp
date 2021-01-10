#include <bits/stdc++.h>
using namespace std;

inline void Solve()
{
	int n,s=0;
	long long ans=0;
	scanf("%d",&n);
	if (!n) return puts("0"),void();
	for (int i=0;;i++)
	{
		int p=1<<i;s+=p;
		if (s>n)
		{
			int a=1<<i;
			long long f=a*2-1;
			ans+=1LL*(f+f+n-s+p-1)*(n-s+p)/2;
			printf("%lld\n",ans);
			return ;
		}
		long long f=2*p-1;
		ans+=1LL*(f+f+p-1)*p/2;
		if (s==n) return printf("%lld\n",ans),void();
	}
	assert(false);
	return ;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}