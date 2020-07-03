#include <bits/stdc++.h>
#define MAXN 1005
#define MAXM 11005
using namespace std;

const int INF=0x3f3f3f3f;

struct edge
{
	int u,v,w,p;
	edge(){}
	edge(int _,int __,int ___,int ____):u(_),v(__),w(___),p(____){}
};

edge e[MAXM],g[MAXM];
int n,m,s=1,r=n+1,pre[MAXN],in[MAXN],id[MAXN],vis[MAXN];

inline void chkmin(int &a,int b){if (a>b) a=b;return ;}

inline long long ZhuliuAlgo(int n,int m,int rt)
{
	long long ans=0;
	while (true)
	{
		memset(in,0x3f,sizeof in);
		for (int i=1;i<=m;i++)
			if (in[e[i].v]>e[i].w)
			{
				if (e[i].u==rt) r=e[i].p; // WTF???
				in[e[i].v]=e[i].w;
				pre[e[i].v]=e[i].u;
			}
		for (int i=1;i<=n;i++) if (i!=rt&&in[i]==INF) return -1;
		memset(id,-1,sizeof id);memset(vis,-1,sizeof vis);
		in[rt]=0;int T=0;
		for (int i=1;i<=n;i++)
		{
			ans+=in[i];int v=i;
			while (vis[v]!=i&&!~id[v]&&v!=rt) vis[v]=i,v=pre[v];
			if (v!=rt&&!~id[v])
			{
				id[v]=++T;
				for (int u=pre[v];u!=v;u=pre[u]) id[u]=T;
			}
		}
		if (!T) break;
		for (int i=1;i<=n;i++) if (!~id[i]) id[i]=++T;
		int M=0;
		for (int i=1;i<=m;i++)
		{
			e[i].w-=in[e[i].v];
			e[i].u=id[e[i].u];e[i].v=id[e[i].v];
			if (e[i].u!=e[i].v) g[++M]=e[i];
		}
		for (int i=1;i<=M;i++) e[i]=g[i];
		m=M;n=T;rt=id[rt];
	}
	return ans;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1,u,v,w;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[i]=edge(u,v,w,v);s+=w;
	}
	for (int i=1;i<=n;i++) e[i+m]=edge(n+1,i,s,i);
	long long ans=ZhuliuAlgo(n+1,m+n,n+1);
	if (!~ans||ans>=(s<<1)) puts("-1");
	else printf("%lld %d\n",ans-s,r);
	return 0;
}