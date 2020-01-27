#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,u,v,a,b,c,dep[MAXN],pre[MAXN],ans;
bool vis[MAXN],d[MAXN];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline void dfs1(int x,int f,int deep)
{
	dep[x]=deep;if (dep[x]>dep[a]) a=x;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f) dfs1(e[i].to,x,deep+1);
	return ;
}

inline void dfs2(int x,int f,int deep)
{
	dep[x]=deep;if (dep[x]>dep[b]) b=x;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f)
		{
			dfs2(e[i].to,x,deep+1);
			pre[e[i].to]=x;
		}
	return ;
}

inline void dfs3(int x,int f,int deep)
{
	vis[x]=true;
	if (deep>ans)
	{
		ans=deep;c=x;
	}
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f&&!vis[e[i].to]&&!d[e[i].to])
			dfs3(e[i].to,x,deep+1);
	return ;
}

int main()
{
	scanf("%d",&n);memset(head,-1,sizeof head);
	for (int i=1;i<n;i++) scanf("%d %d",&u,&v),add(u,v);
	dfs1(1,-1,0);memset(dep,0,sizeof dep);dfs2(a,-1,0);
	for (int x=b;x!=a;x=pre[x]) d[x]=true;d[a]=true;
	for (int i=1;i<=n;i++) if (d[i]) dfs3(i,-1,0);
	printf("%d\n",ans+dep[b]);
	if (!c)
	{
		for (int i=1;i<=n;i++) if (i!=a&&i!=b){c=i;break;}
	}
	printf("%d %d %d\n",a,b,c);
	return 0;
}