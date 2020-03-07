#include <bits/stdc++.h>
#define MAXN 55
using namespace std;

struct Point
{
	int x,y;
	long long operator * (const Point &p)const{
		return 1LL*x*p.y-1LL*y*p.x;
	}
};

Point p[MAXN];
int n,T;
long long ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d %d",&p[i].x,&p[i].y);
		long long now=0;
		for (int i=0;i<n;i++) now+=p[i%n]*p[(i+1)%n];
		ans+=abs(now);
	}
	printf("%lld\n",ans>>1);
	return 0;
}