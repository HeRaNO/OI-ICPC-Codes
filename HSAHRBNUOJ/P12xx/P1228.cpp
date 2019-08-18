#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;
 
int kas,n,f[MAXN],bel[MAXN],siz[MAXN];
long long mn[MAXN],ans,mnn;
pair <int,int> a[MAXN];
 
inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}
 
int main()
{
	while (true)
	{
		memset(mn,0x7f,sizeof mn);mnn=~(1LL<<63);ans=0;
		memset(bel,0,sizeof bel);memset(siz,0,sizeof siz);
		scanf("%d",&n);if (!n) break;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i].first);a[i].second=i;
			mnn=min(mnn,1LL*a[i].first);f[i]=i;
		}
		sort(a+1,a+n+1);
		for (int i=1;i<=n;i++)
		{
			int fx=getf(i),fy=getf(a[i].second);
			if (fx!=fy) f[fy]=fx;
		}
		for (int i=1;i<=n;i++) bel[i]=getf(i);
		for (int i=1;i<=n;i++)
		{
			mn[bel[i]]=min(mn[bel[i]],1LL*a[i].first);
			++siz[bel[i]];
		}
		for (int i=1;i<=n;i++)
		{
			ans+=a[i].first;
			if (siz[i]) ans+=min(mnn*(siz[i]+1)+2*mn[i],mn[i]*(siz[i]-1))-mn[i];
		}
		printf("Case %d: %lld\n\n",++kas,ans);
	}
	return 0;
}