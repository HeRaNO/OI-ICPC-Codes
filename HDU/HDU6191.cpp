#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,m,x,y,R,rt[MAXN],v[MAXN],rev[MAXN];
int son[MAXN*33][2],sz[MAXN*33],tot,in[MAXN],out[MAXN];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

void dfs(int x,int f)
{
	in[x]=++R;rev[R]=x;
	for (int i=head[x];~i;i=e[i].nxt) if (e[i].to!=f) dfs(e[i].to,x);
	out[x]=R;
	return ;
}

inline void add(int &x,int y,int v)
{
	x=++tot;int now=x;
	for(int i=30;~i;i--)
	{
		int nxt=v>>i&1;
		son[now][nxt^1]=son[y][nxt^1];
		now=son[now][nxt]=++tot;y=son[y][nxt];
		sz[now]=sz[y]+1;
	}
	return ;
}

inline int query(int x,int y,int v)
{
	int res=0;
	for(int i=30;~i;i--)
	{
		int nxt=v>>i&1;
		if(sz[son[y][nxt^1]]>sz[son[x][nxt^1]])
			res|=(1<<i),y=son[y][nxt^1],x=son[x][nxt^1];
		else y=son[y][nxt],x=son[x][nxt];
	}
	return res;
}

int main()
{
	while (scanf("%d %d",&n,&m)!=EOF)
	{
		memset(son,0,sizeof son);memset(rt,0,sizeof rt);memset(sz,0,sizeof sz);
		memset(head,-1,sizeof head);cnt=0;R=0;tot=1;
		for (int i=1;i<=n;i++) scanf("%d",&v[i]);
		for (int i=2;i<=n;i++) scanf("%d",&x),add(i,x);
		dfs(1,-1);
		for (int i=1;i<=n;i++) add(rt[i],rt[i-1],v[rev[i]]);
		while (m--)
		{
			scanf("%d %d",&x,&y);
			printf("%d\n",query(rt[in[x]-1],rt[out[x]],y));
		}
	}
	return 0;
}