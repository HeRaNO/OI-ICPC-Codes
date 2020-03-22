#include <bits/stdc++.h>
#define MAXN 100005
#define fi first
#define se second
using namespace std;

int n;
pair <int,int> a[MAXN];

int main()
{
	while (scanf("%d",&n)==1&&n)
	{
		long long ans=0;
		for (int i=1;i<=n;i++) scanf("%d %d",&a[i].fi,&a[i].se);
		sort(a+1,a+n+1,[&](pair <int,int> a,pair <int,int> b){return 1LL*a.fi*b.se<1LL*a.se*b.fi;});
		for (int i=1;i<=n;i++) (ans+=a[i].fi+ans*a[i].se%31536000)%=31536000;
		printf("%lld\n",ans);
	}
	return 0;
}