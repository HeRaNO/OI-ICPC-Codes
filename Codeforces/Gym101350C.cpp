#include <bits/stdc++.h>
using namespace std;

int T,n,x,g;
long long s;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int n;scanf("%d",&n);s=0;
		scanf("%d",&x);s+=x;g=x;
		for (int i=2;i<=n;i++)
		{
			scanf("%d",&x);
			g=__gcd(g,x);s+=x;
		}
		printf("%lld %d\n",s,g);
	}
	return 0;
}