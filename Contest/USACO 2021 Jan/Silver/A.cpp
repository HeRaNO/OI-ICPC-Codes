#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,m,u,v,f[MAXN],p[MAXN];
set <int> s[MAXN];

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline void Union(int u,int v)
{
	int fx=getf(u),fy=getf(v);
	if (fx==fy) return ;
	if (s[fx].size()<s[fy].size()) swap(fx,fy);
	f[fy]=fx;
	for (auto p:s[fy]) s[fx].insert(p);
	return ;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) f[i]=p[i]=i,s[i].insert(i);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		s[p[u]].insert(v);s[p[v]].insert(u);
		swap(p[u],p[v]);
	}
	for (int i=1;i<=n;i++) Union(i,p[i]);
	for (int i=1;i<=n;i++) printf("%d\n",s[getf(i)].size());
	return 0;
}