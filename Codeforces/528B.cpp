#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
struct points
{
	ll x,y;
}p[200050];

inline bool cmp(const points &X,const points &Y)
{
	if(X.x==Y.x)return X.y<Y.y;
	else return X.x<Y.x;
}
int ans;
 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		ll pos,val;
		scanf("%lld%lld",&pos,&val);
		p[i].x=pos+val;
		p[i].y=pos-val;
	}
	sort(p+1,p+n+1,cmp);
	int tmp=INT_MIN;
	for(int i=1;i<=n;++i)
	{
		if(p[i].y>=tmp)
		{
			tmp=p[i].x;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}