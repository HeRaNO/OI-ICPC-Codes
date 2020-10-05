#include <bits/stdc++.h>
#define MAXN 25
#define fi first
#define se second
using namespace std;

int T,n,m,f[MAXN];
vector <pair<int,pair<int,int> > > e;

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline void Solve()
{
	int ans=0,cnt=0;
	scanf("%d %d",&n,&m);e.clear();
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		e.push_back({w,{u,v}});
	}
	sort(e.begin(),e.end());
	for (auto p:e)
	{
		int w=p.fi,u=p.se.fi,v=p.se.se;
		int fx=getf(u),fy=getf(v);
		if (fx!=fy)
		{
			ans+=w;f[fy]=fx;
			++cnt;
		}
		if (cnt==n-1) break;
	}
	if (ans==1) printf("%d meter\n",ans);
	else printf("%d meters\n",ans);
	return ;
}

int main()
{
	scanf("%d",&T);
	for (int i=1;i<=T;i++) printf("Case #%d: ",i),Solve();
	return 0;
}
