#include <bits/stdc++.h>
#define MAXN 305
using namespace std;

int n,l[MAXN],c[MAXN];
map <int,int> mp;
map <int,int> :: iterator it,itt;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&l[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	mp[0]=0;
	for (int i=1;i<=n;i++)
		for (it=mp.begin();it!=mp.end();it++)
		{
			int g=__gcd(l[i],it->first);
			if (mp.count(g)) mp[g]=min(mp[g],it->second+c[i]);
			else mp[g]=it->second+c[i];
		}
	if (!mp.count(1)) puts("-1");
	else printf("%d\n",mp[1]);
	return 0;
}