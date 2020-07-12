#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,w[MAXN<<1],f[MAXN],c[MAXN],sta[MAXN<<1],top;
int dep[MAXN<<1],lc[MAXN];
long long ans,dp[MAXN<<1];
vector <int> g[MAXN<<1];

inline int lowbit(int x){return x&-x;}
inline void add(int x,int v){for (;x<=n;x+=lowbit(x)) c[x]+=v;return ;}
inline int query(int x){int r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}

inline void init(int n)
{
	for (int i=2;i<=n;i++)
		if (!f[i])
			for (int j=i;j<=n;j+=i)
				if (!f[j]) f[j]=i;
	return ;
}

inline int BuildTree()
{
	int N=n;sta[top=1]=1;
	for (int i=1;i<=n;i++) c[i]=0;
	for (int i=2;i<=n;i++)
	{
		dep[i]=dep[i-1]+1;int j=i;
		for (;j!=f[j];j/=f[j]) ++dep[i];
		lc[i]=query(n)-query(j-1);
		for (j=i;j!=1;j/=f[j]) add(f[j],1);
	}
	for (int i=2;i<=n;i++)
	{
		while (top>1&&dep[sta[top-1]]>=lc[i])
		{
			g[sta[top-1]].push_back(sta[top]);
			--top;
		}
		if (dep[sta[top]]!=lc[i])
		{
			dep[++N]=lc[i];
			g[N].push_back(sta[top]);
			sta[top]=N;
		}
		sta[++top]=i;
	}
	for (;top>1;--top) g[sta[top-1]].push_back(sta[top]);
	return N;
}

void dfs1(int x)
{
	for (auto v:g[x]) dfs1(v),w[x]+=w[v];
	return ;
}

void dfs2(int x)
{
	for (auto v:g[x])
	{
		dp[v]=dp[x]+1LL*(w[1]-2*w[v])*(dep[v]-dep[x]);
		dfs2(v);
	}
	return ;
}

int main()
{
	init(100000);
	while (scanf("%d",&n)==1)
	{
		ans=~(1LL<<63);
		for (int i=1;i<=n;i++) scanf("%d",&w[i]);
		n=BuildTree();
		for (int i=1;i<=n;i++) dp[1]+=1LL*w[i]*dep[i];
		dfs1(1);dfs2(1);
		for (int i=1;i<=n;i++) ans=min(ans,dp[i]);
		printf("%lld\n",ans);
		for (int i=1;i<=n;i++) g[i].clear(),dp[i]=0,w[i]=0;
	}
	return 0;
}