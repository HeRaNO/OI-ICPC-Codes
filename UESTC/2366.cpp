#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,x,ans[MAXN];
int lc[MAXN],rc[MAXN],dep[MAXN],siz[MAXN],rt[MAXN];
long long L,w,a[MAXN],lazy[MAXN];
vector <pair<int,long long> > g[MAXN];

inline void add(int x,long long v)
{
	if (!x) return ;
	a[x]+=v;lazy[x]+=v;
	return ;
}

inline void PushDown(int x)
{
	if (!lazy[x]) return ;
	add(lc[x],lazy[x]);add(rc[x],lazy[x]);lazy[x]=0;
	return ;
}

int Merge(int x,int y)
{
	if (!x||!y) return x+y;
	if (a[x]<a[y]) swap(x,y);
	PushDown(x);
	rc[x]=Merge(rc[x],y);
	if (dep[rc[x]]>dep[lc[x]]) swap(lc[x],rc[x]);
	dep[x]=dep[rc[x]]+1;
	siz[x]=siz[lc[x]]+siz[rc[x]]+1;
	return x;
}

void pop(int x)
{
	PushDown(rt[x]);
	rt[x]=Merge(lc[rt[x]],rc[rt[x]]);
	return ;
}

inline void dfs(int x)
{
	rt[x]=x;dep[x]=siz[x]=1;
	for (auto p:g[x])
	{
		int v=p.first;long long w=p.second;
		dfs(v);add(rt[v],w);
		while (a[rt[v]]>L) pop(v);
		rt[x]=Merge(rt[x],rt[v]);
	}
	ans[x]=siz[rt[x]];
	return ;
}

int main()
{
	scanf("%d %lld",&n,&L);
	for (int i=2;i<=n;i++)
	{
		scanf("%d %lld",&x,&w);
		g[x].push_back({i,w});
	}
	dfs(1);
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}