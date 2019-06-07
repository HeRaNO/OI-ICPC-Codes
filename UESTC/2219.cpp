#include <bits/stdc++.h>
#define MAXN 3005
#define MAXM 3005
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXM<<1],f[MAXN*MAXN];
int h[MAXN],g[MAXN],cnt,cnt1;
int n,m,T,u,v,x,s,p,ans,val[MAXN],dp[MAXN];
int dfn[MAXN],low[MAXN],sta[MAXN],bel[MAXN],top,scc_cnt;
bool vis[MAXN];
queue <int> q;

inline void add(link e[],int head[],int &cnt,int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	return ;
}

void Tarjan(int x,int fa)
{
	dfn[x]=low[x]=++T;sta[++top]=x;
	for (int i=h[x];~i;i=e[i].nxt)
	{
		if (vis[e[i].to]||e[i].to==fa) continue;
		if (dfn[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
		else
		{
			Tarjan(e[i].to,x);
			low[x]=min(low[x],low[e[i].to]);
		}
	}
	if (dfn[x]==low[x])
	{
		int t;scc_cnt++;
		do{
			t=sta[top--];
			vis[t]=true;
			bel[t]=scc_cnt;
		}
		while (t!=x);
	}
	return ;
}

inline void DP(int x)
{
	q.push(x);dp[x]=val[x];
	while (!q.empty())
	{
		int u=q.front();q.pop();
		for (int i=g[u];~i;i=f[i].nxt)
			if (dp[f[i].to]<dp[u]+val[f[i].to])
			{
				dp[f[i].to]=dp[u]+val[f[i].to];
				q.push(f[i].to);
			}
	}
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	memset(h,-1,sizeof h);memset(g,-1,sizeof g);memset(dp,-1,sizeof dp);
	read(n);read(m);
	for (int i=1;i<=m;i++) read(u),read(v),add(e,h,cnt,u,v);
	for (int i=1;i<=n;i++) if (!dfn[i]) Tarjan(i,0);
	for (int i=1;i<=n;i++)
		for (int j=h[i];~j;j=e[j].nxt)
			if (bel[i]!=bel[e[j].to])
				add(f,g,cnt1,bel[i],bel[e[j].to]);
	for (int i=1;i<=n;i++)
	{
		read(x);val[bel[i]]+=x;
	}
	read(s);DP(bel[s]);
	read(p);
	for (int i=1;i<=p;i++)
	{
		read(x);ans=max(ans,dp[bel[x]]);
	}
	printf("%d\n",ans);
	return 0;
}