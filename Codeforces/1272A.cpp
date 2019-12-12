#include <bits/stdc++.h>
using namespace std;

int T;
long long a,b,c;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld %lld %lld",&a,&b,&c);long long ans=~(1LL<<63);
		for (int i=-1;i<=1;i++)
			for (int j=-1;j<=1;j++)
				for (int k=-1;k<=1;k++)
				{
					long long p=a+i,q=b+j,r=c+k;
					ans=min(ans,abs(p-q)+abs(p-r)+abs(q-r));
				}
		printf("%lld\n",ans);
	}
	return 0;
}