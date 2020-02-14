#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt,bel[MAXN];
int n,m,Q,T,R,u,v,bcc,low[MAXN],dfn[MAXN],sta[MAXN],top;
int dep[MAXN<<1],dis[20][MAXN<<2],lg[MAXN<<2],pt[MAXN<<1];
vector <int> s[MAXN],g[MAXN<<1];
bool cut[MAXN];

inline int f(int x){return x<0?0:x;}

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline void addg(int u,int v)
{
	g[u].push_back(v);g[v].push_back(u);
	return ;
}

inline void Tarjan(int x,int fa)
{
	dfn[x]=low[x]=++T;sta[++top]=x;
	for (int i=head[x];~i;i=e[i].nxt)
	{
		if (!dfn[e[i].to])
		{
			Tarjan(e[i].to,x);
			low[x]=min(low[x],low[e[i].to]);
			if (low[e[i].to]>=dfn[x])
			{
				cut[x]|=(dfn[x]>1||dfn[e[i].to]>2);
				++bcc;int y;
				do{
					y=sta[top--];s[bcc].push_back(y);
				}while (y!=e[i].to);
				s[bcc].push_back(x);
			}
		}
		else
			low[x]=min(low[x],dfn[e[i].to]);
	}
	return ;
}

inline void BuildTree()
{
	int cnt=0;
	for (int i=1;i<=n;i++) if (cut[i]) bel[i]=++cnt;
	for (int i=1;i<=bcc;i++)
	{
		++cnt;
		for (auto x:s[i])
		{
			if (cut[x]) addg(bel[x],cnt);
			else bel[x]=cnt;
		}
	}
	return ;
}

inline void dfs(int x,int f)
{
	dis[0][++R]=dep[x];pt[x]=R;
	for (auto v:g[x])
		if (v!=f)
		{
			dep[v]=dep[x]+1;dfs(v,x);
			dis[0][++R]=dep[x];
		}
	return ;
}

inline int getdis(int x,int y)
{
	int d=dep[x]+dep[y];x=pt[x];y=pt[y];
	if (x>y) swap(x,y);int t=lg[y-x+1];
	return d-2*min(dis[t][x],dis[t][y-(1<<t)+1]);
}

inline void RMQLCA()
{
	dfs(1,-1);
	for (int i=2;i<=R;i++) lg[i]=lg[i>>1]+1;
	for (int j=1;j<=lg[R];j++)
		for (int i=1;i+(1<<j)-1<=R;i++)
			dis[j][i]=min(dis[j-1][i],dis[j-1][i+(1<<(j-1))]);
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d %d",&u,&v),add(u,v);
	Tarjan(1,-1);BuildTree();RMQLCA();
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%d %d",&u,&v);
		if (bel[u]==bel[v]) puts("0");
		else
		{
			int ans=getdis(bel[u],bel[v]);
			if (cut[u]) --ans;
			if (cut[v]) --ans;
			printf("%d\n",ans>>1);
		}
	}
	return 0;
}