#include <bits/stdc++.h>
using namespace std;

int a,b,q,pt1,pt2,pt3;
long long x,ans,s[100010],t[100010];

int main()
{
	scanf("%d %d %d",&a,&b,&q);
	s[0]=-5e10;for (int i=1;i<=a;i++) scanf("%lld",&s[i]);s[a+1]=5e10;
	t[0]=-5e10;for (int i=1;i<=b;i++) scanf("%lld",&t[i]);t[b+1]=5e10;
	while (q--)
	{
		scanf("%lld",&x);ans=~(1LL<<63);
		pt1=lower_bound(s+1,s+a+1,x)-s;
		pt2=lower_bound(t+1,t+b+1,s[pt1])-t;
		pt3=lower_bound(t+1,t+b+1,s[pt1-1])-t;
		ans=min(ans,s[pt1]-x+min(t[pt2]-s[pt1],s[pt1]-t[pt2-1]));
		ans=min(ans,x-s[pt1-1]+min(t[pt3]-s[pt1-1],s[pt1-1]-t[pt3-1]));
		pt1=lower_bound(t+1,t+b+1,x)-t;
		pt2=lower_bound(s+1,s+a+1,t[pt1])-s;
		pt3=lower_bound(s+1,s+a+1,t[pt1-1])-s;
		ans=min(ans,t[pt1]-x+min(s[pt2]-t[pt1],t[pt1]-s[pt2-1]));
		ans=min(ans,x-t[pt1-1]+min(s[pt3]-t[pt1-1],t[pt1-1]-s[pt3-1]));
		printf("%lld\n",ans);
	}
	return 0;
}