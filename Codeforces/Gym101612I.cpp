#include <bits/stdc++.h>
#define MAXN 3000005
typedef long long ll;
using namespace std;
const int INF=~(1<<31);

int main()
{
	freopen("intel.in","r",stdin);
	freopen("intel.out","w",stdout);
	int n;
	ll ans=0;
	scanf("%d",&n);
	ll x,y,ix,iy;
	scanf("%lld%lld",&x,&y);
	ix=x,iy=y;
	ll minx=INF,maxx=-INF,miny=INF,maxy=-INF;
	minx=min(minx,x);
	maxx=max(maxx,x);
	miny=min(miny,y);
	maxy=max(maxy,y);
	for(int i=1;i<n;i++)
	{
		ll x2,y2;
		scanf("%lld%lld",&x2,&y2);
		minx=min(minx,x2);
		maxx=max(maxx,x2);
		miny=min(miny,y2);
		maxy=max(maxy,y2);
		ans+=abs(x-x2)+abs(y-y2);
		x=x2,y=y2;
	}
	ans+=abs(x-ix)+abs(y-iy);
	printf("%lld",ans-2*abs(maxx-minx)-2*abs(maxy-miny));
	return 0;
}