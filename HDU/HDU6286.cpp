#include <bits/stdc++.h>
using namespace std;

int a,b,c,d;

int main()
{
	while (~scanf("%d %d %d %d",&a,&b,&c,&d))
	{
		long long x1=b-a+1,x2=b/2-(a-1)/2,x3=b/1009-(a-1)/1009,x4=b/2018-(a-1)/2018;
		long long y1=d-c+1,y2=d/2-(c-1)/2,y3=d/1009-(c-1)/1009,y4=d/2018-(c-1)/2018;
		long long ans=0;
		ans+=(x2-x4)*(y3-y4);
		ans+=(x3-x4)*(y2-y4);
		ans+=(x1)*y4;
		ans+=(y1)*x4;
		ans-=x4*y4;
		printf("%lld\n",ans);
	}
	return 0;
}
