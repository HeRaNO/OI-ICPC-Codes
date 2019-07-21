#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int T,n,m,x,l,k,ans,h[MAXN],cnt[MAXN];
vector <int> a[MAXN];
set <int> s;
set <int> :: iterator it;
set <int> :: reverse_iterator rit;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(cnt,0,sizeof cnt);
		scanf("%d %d",&n,&m);ans=0;s.clear();
		for (int i=1;i<=n+1;i++) a[i].clear();
		for (int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&x,&l,&k);
			h[i]=l;
			int pl=max(x-k,1);
			int pr=min(x+k,n);
			a[pl].push_back(i);
			a[pr+1].push_back(-i);
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<a[i].size();j++)
			{
				if (a[i][j]>0)
				{
					s.insert(a[i][j]);
					++cnt[h[a[i][j]]];
				}
				else
				{
					it=s.find(-a[i][j]);
					s.erase(it);--cnt[h[-a[i][j]]];
				}
			}
			if (s.empty()) ++ans;
			else
			{
				if (cnt[h[*s.rbegin()]]>1) ++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}