#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans;
vector <pair<int,ll> > e[100050];

int main()
{
	int Test;cin>>Test;
	while(Test--)
	{
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;++i)e[i].clear();
		for(int i=1;i<n;++i)
		{
			int x,y;ll w;
			scanf("%d%d%lld",&x,&y,&w);
			e[x].push_back({y,w});
			e[y].push_back({x,w});
		}
		for(int u=1;u<=n;++u)
		{
			if(e[u].size()>=2)
			{
				ll tmp=0,mn=LLONG_MAX;
				for(auto v:e[u])
				{
					tmp+=v.second;
					mn=min(mn,v.second);
				}
				ans+=tmp+mn*(e[u].size()-2);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
