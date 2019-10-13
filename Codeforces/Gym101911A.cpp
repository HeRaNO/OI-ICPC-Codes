#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

set <pair<int,int> > s;
int n,m,k,a[MAXN],ans[MAXN],day;
set <pair<int,int> > :: iterator it;

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s.insert(make_pair(a[i],i));
	}
	while (!s.empty())
	{
		int u=s.begin()->second;s.erase(s.begin());ans[u]=++day;
		while (true)
		{
			it=s.lower_bound(make_pair(a[u]+k+1,0));
			if (it==s.end()) break;
			u=it->second;ans[u]=day;
			s.erase(it);
		}
	}
	printf("%d\n",day);
	for (int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}