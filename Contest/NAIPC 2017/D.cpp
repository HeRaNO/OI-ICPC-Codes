#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,a[MAXN],fa[MAXN],p[MAXN];
multiset <int> s[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i],&p[i]);
		fa[i]=i;
	}
	for (int i=n;i;i--)
	{
		auto it=s[fa[i]].upper_bound(a[i]-1);
		if (it!=s[fa[i]].end()) s[fa[i]].erase(it);
		s[fa[i]].insert(a[i]);
		if (s[fa[i]].size()<s[fa[p[i]]].size())
			s[fa[p[i]]].insert(s[fa[i]].begin(),s[fa[i]].end());
		else
		{
			s[fa[i]].insert(s[fa[p[i]]].begin(),s[fa[p[i]]].end());
			fa[p[i]]=fa[i];
		}
	}
	printf("%u\n",s[fa[0]].size());
	return 0;
}