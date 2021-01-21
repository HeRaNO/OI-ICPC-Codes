#include <cstdio>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n,a[MAXN],sta[MAXN],ls[MAXN],rs[MAXN];
long long s[MAXN],ans=-1;
pair<int,int> lr[MAXN],ansl;

inline pair<int,int> getRange(pair<int,int> a,pair<int,int> b)
{
	int x=min(a.first,b.first);
	int y=max(a.second,b.second);
	return make_pair(x,y);
}

inline void dfs(int x)
{
	if (ls[x])
	{
		dfs(ls[x]);
		lr[x]=getRange(lr[x],lr[ls[x]]);
	}
	if (rs[x])
	{
		dfs(rs[x]);
		lr[x]=getRange(lr[x],lr[rs[x]]);
	}
	return ;
}

inline void BuildTree()
{
	int top=0,rt=1;
	for (int i=1;i<=n;i++)
	{
		int k=top;lr[i]=make_pair(i,i);
		if (a[i]<a[rt]) rt=i;
		for (;k&&a[sta[k]]>a[i];--k);
		if (k) rs[sta[k]]=i;
		if (k<top) ls[i]=sta[k+1];
		sta[++k]=i;top=k;
	}
	dfs(rt);
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	BuildTree();
	for (int i=1;i<=n;i++)
	{
		long long x=1LL*a[i]*(s[lr[i].second]-s[lr[i].first-1]);
		if (ans<x)
		{
			ans=x;ansl=lr[i];
		}
	}
	printf("%lld\n",ans);
	printf("%d %d\n",ansl.first,ansl.second);
	return 0;
}