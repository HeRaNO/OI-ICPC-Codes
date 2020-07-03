#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100005
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,m,T,u,v,ans,low[MAXN],dfn[MAXN];
bool cut[MAXN];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline void Tarjan(int x)
{
	dfn[x]=low[x]=++T;
	for (int i=head[x];~i;i=e[i].nxt)
	{
		if (!dfn[e[i].to])
		{
			Tarjan(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
			if (low[e[i].to]>=dfn[x]) cut[x]|=(dfn[x]>1||dfn[e[i].to]>2);
		}
		else low[x]=min(low[x],dfn[e[i].to]);
	}
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		add(u,v);
	}
	for (int i=1;i<=n;i++) if (!dfn[i]) T=0,Tarjan(i);
	for (int i=1;i<=n;i++) ans+=cut[i];
	printf("%d\n",ans);
	return 0;
}
