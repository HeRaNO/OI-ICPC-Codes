#include <cstdio>
#include <cstring>
#define MAXN 10001
#define MAXM 20001
using namespace std;

struct link{int to,nxt;};

link e[MAXM<<1];
int head[MAXN],cnt;
int n,m,T,x,y,all,ans,v[MAXN],f[MAXN],sta[MAXN],w[MAXN],top;
int dfn[MAXN],low[MAXN],bel[MAXN],b[MAXM][2],bcccnt,bcnt;
bool vis[MAXN],vise[MAXM];

inline void init()
{
	cnt=bcccnt=bcnt=all=T=0;ans=~(1<<31);
	memset(head,-1,sizeof head);
	memset(f,0,sizeof f);memset(w,0,sizeof w);
	memset(dfn,0,sizeof dfn);memset(low,0,sizeof low);
	memset(vis,0,sizeof vis);memset(vise,0,sizeof vise);
	return ;
}

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline int min(int a,int b){return a<b?a:b;}
inline int abs(int x){return x<0?-x:x;}

void Tarjan(int x,int fa)
{
	dfn[x]=low[x]=++T;sta[++top]=x;vis[x]=true;
	for (int i=head[x];~i;i=e[i].nxt)
	{
		if (vise[i]) continue;
		vise[i]=vise[i^1]=true;
		if (!dfn[e[i].to])
		{
			Tarjan(e[i].to,x);
			low[x]=min(low[x],low[e[i].to]);
			if (low[e[i].to]>dfn[x])
			{
				b[++bcnt][0]=x;b[bcnt][1]=e[i].to;
				int t;++bcccnt;
				do{
					t=sta[top--];vis[t]=false;bel[t]=bcccnt;
				}while (t!=e[i].to);
			}
		}
		else if (vis[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	}
	return ;
}

void dfs(int x)
{
	vis[x]=true;f[x]=w[x];
	for (int i=head[x];~i;i=e[i].nxt)
		if (!vis[e[i].to])
		{
			dfs(e[i].to);
			f[x]+=f[e[i].to];
		}
	ans=min(ans,abs(all-(f[x]<<1)));
	return ;
}

inline void read(int &x)
{
	x=0;char ch;
	if ((ch=getchar())==EOF){x=-1;return ;}
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	while (1)
	{
		init();
		read(n);if (!~n) break;read(m);
		for (int i=1;i<=n;i++) read(v[i]),all+=v[i];
		for (int i=1;i<=m;i++) read(x),read(y),add(x+1,y+1);
		Tarjan(1,0);
		++bcccnt;
		while (top) bel[sta[top--]]=bcccnt;
		if (bcccnt==1){puts("impossible");continue;}
		for (int i=1;i<=n;i++) w[bel[i]]+=v[i];
		memset(head,-1,sizeof head);cnt=0;memset(vis,0,sizeof vis);
		for (int i=1;i<=bcnt;i++) add(bel[b[i][0]],bel[b[i][1]]);
		dfs(1);printf("%d\n",ans);
	}
	return 0;
}