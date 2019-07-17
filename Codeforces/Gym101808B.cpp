#include <bits/stdc++.h>
#define MAXN 2005
using namespace std;

const long long h1=131;
const long long M1=1e9+9;
const long long h2=233;
const long long M2=1e9+7;

int T,n,u,v,ans,cnt,a[MAXN];
long long _1[MAXN],_2[MAXN];
map <pair<int,int>,int> mp,h[MAXN];

int main()
{
	_1[0]=_2[0]=1LL;
	for (int i=1;i<=2000;i++)
	{
		_1[i]=_1[i-1]*h1%M1;
		_2[i]=_2[i-1]*h2%M2;
	}
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);cnt=0;ans=0;
		mp.clear();
		for (int i=1;i<=n;i++)
		{
			h[i].clear();
			scanf("%d %d",&u,&v);
			if (u>v) swap(u,v);
			if (!mp.count(make_pair(u,v))) mp.insert(make_pair(make_pair(u,v),++cnt));
			a[i]=mp[make_pair(u,v)];
		}
		for (int i=1;i<=n;i++)
		{
			long long p=0,q=0;
			for (int j=i;j<=n;j++)
			{
				(p+=_1[a[j]])%=M1;
				(q+=_2[a[j]])%=M2;
				ans+=h[j-i+1][make_pair(p,q)];
				++h[j-i+1][make_pair(p,q)];
			}
		}
		printf("%d\n",ans);	
	}
	return 0;
}