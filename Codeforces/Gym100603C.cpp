#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,x,f[MAXN],p[MAXN],bel[MAXN],siz[MAXN];
long long a[MAXN],all[MAXN],mn[MAXN],ans,mnn;

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int main()
{
	memset(mn,0x7f,sizeof mn);mnn=~(1LL<<63);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),mnn=min(mnn,a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]),f[i]=i;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		int fx=getf(x),fy=getf(p[i]);
		if (fx!=fy) f[fy]=fx;
	}
	for (int i=1;i<=n;i++) bel[i]=getf(i);
	for (int i=1;i<=n;i++)
	{
		mn[bel[i]]=min(mn[bel[i]],a[i]);
		all[bel[i]]+=a[i];
		++siz[bel[i]];
	}
	for (int i=1;i<=n;i++)
	{
		ans+=a[i];
		if (siz[i]) ans+=min(mnn*(siz[i]+1)+2*mn[i],mn[i]*(siz[i]-1))-mn[i];
	}
	printf("%lld\n",ans);
	return 0;
}