#include <bits/stdc++.h>
using namespace std;

int T,x,y,a,b;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d %d",&x,&y,&a,&b);
		if (x>y) swap(x,y);
		printf("%lld\n",min(1LL*(x+y)*a,1LL*x*b+1LL*(y-x)*a));
	}
	return 0;
}