#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

const long long M=1e9+7;

pair <long long, long long> a[MAXN];
multimap <long long, long long, greater<long long> > s;
multimap <long long, long long, greater<long long> > :: iterator it;
int n;
long long ans,x,y;

int main()
{
	scanf("%d %lld %lld",&n,&x,&y);
	for (int i=1;i<=n;i++) scanf("%lld %lld",&a[i].first,&a[i].second);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		it=s.upper_bound(a[i].first);
		if (it==s.end())
		{
			s.insert(make_pair(a[i].second,a[i].first));
			long long c=(a[i].second-a[i].first)*y%M;
			c=(c+x)%M;
			ans=(ans+c)%M;
		}
		else
		{
			if ((a[i].first-it->first)*y<x)
			{
				long long c1=(it->first-it->second)*y%M;
				long long c2=(a[i].second-it->second)*y%M;
				ans=(ans-c1+M+c2)%M;
				long long p=it->second;
				s.erase(it);
				s.insert(make_pair(a[i].second,p));
			}
			else
			{
				s.insert(make_pair(a[i].second,a[i].first));
				long long c=(a[i].second-a[i].first)*y%M;
				c=(c+x)%M;
				ans=(ans+c)%M;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
