#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int a,b,p,ans;
		scanf("%d %d",&a,&b);
		p=abs(a-b);ans=p/5;p%=5;ans+=(p>>1);p&=1;ans+=p;
		printf("%d\n",ans);
	}
	return 0;
}