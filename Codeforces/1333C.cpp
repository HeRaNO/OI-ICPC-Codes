#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n;
long long s,ans,mx;
map <long long,long long> mp;

int main()
{
	scanf("%d",&n);ans=1LL*n*(n+1);ans>>=1;
	mp.insert({0,1});
	for (int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		s+=x;mx=max(mx,mp[s]);
		ans-=mx;mp[s]=i+1;
	}
	printf("%lld\n",ans);
	return 0;
}