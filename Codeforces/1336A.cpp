#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,k,u,v,dep[MAXN],siz[MAXN],a[MAXN];
vector <int> g[MAXN];
long long ans;

inline void add(int u,int v)
{
	g[u].push_back(v);g[v].push_back(u);
	return ;
}

inline void dfs(int x,int fa,int deep)
{
	dep[x]=deep;siz[x]=1;
	for (auto v:g[x]) if (v!=fa) dfs(v,x,deep+1),siz[x]+=siz[v];
	return ;
}

bool cmp(const int &x,const int &y)
{
	return dep[x]-siz[x]>dep[y]-siz[y];
}

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=1;i<n;i++) scanf("%d %d",&u,&v),add(u,v);
	dfs(1,-1,1);
	for (int i=1;i<=n;i++) a[i]=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=k;i++) ans+=dep[a[i]]-siz[a[i]];
	printf("%lld\n",ans);
	return 0;
}