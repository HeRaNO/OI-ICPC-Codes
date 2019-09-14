#include <bits/stdc++.h>
#define MAXN 3005
#define fi first
#define se second
using namespace std;

int n,u,v,w,s,f[MAXN],l[MAXN],siz[MAXN],ans;
pair <int,pair<int,int> > a[MAXN];

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) f[i]=i,siz[i]=1;
	for (int i=1;i<n;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		a[i]=make_pair(w,make_pair(u,v));
	}
	sort(a+1,a+n);
	for (int i=1;i<=n;i++) scanf("%d",&l[i]),s+=l[i];
	for (int i=1;i<n&&!ans;i++)
	{
		int fx=getf(a[i].se.fi),fy=getf(a[i].se.se);
		f[fy]=fx;siz[fx]+=siz[fy];l[fx]+=l[fy];
		if (siz[fx]>s-l[fx]) ans=a[i].fi;
	}
	if (!ans) ans=a[n-1].fi;
	printf("%d\n",ans);
	return 0;
}