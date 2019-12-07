#include <bits/stdc++.h>
using namespace std;

int n,x,y,p;

int main()
{
	scanf("%d %d %d",&n,&x,&y);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p);
		y+=p;
	}
	printf("%lld\n",1LL*y*y-x*x);
	return 0;
}