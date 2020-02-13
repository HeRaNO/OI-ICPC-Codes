#include <bits/stdc++.h>
using namespace std;

int T,n,g,b,p,q;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&n,&g,&b);
		p=g+b;q=(n-1)>>1;
		printf("%lld\n",max(1LL*n,1LL*(q/g)*p+(n+1)/2-1LL*(q/g)*g));
	}
	return 0;
}