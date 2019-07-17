#include <bits/stdc++.h>
#define MAXN 100005
#define MAXK 18
#define MAXM 100035
using namespace std;

struct link
{
	int to;long long val;int nxt;
};

struct node
{
	long long d; int u;
	bool operator < (const node &a)const
	{
		return d > a.d;
	}
};

link e[MAXM<<1];
int head[MAXN],cnt;
int n,m,T,k,u,v,w,x,y,f[MAXN],dep[MAXN],r[MAXN],_2pow[MAXK];
int LCAFather[MAXN][MAXK];
long long dis[65][MAXN],LCADis[MAXN][MAXK],ans;
bool vis[MAXN];
priority_queue <node> q;

inline void add(int u,int v,long long w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,head[v]};head[v]=cnt++;
}

inline void dfs(int x,int fa,long long val,int deep)
{
	LCAFather[x][0]=fa;LCADis[x][0]=val;dep[x]=deep;vis[x]=true;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa)
		{
			if (vis[e[i].to]) r[++r[0]]=x;
			else dfs(e[i].to,x,e[i].val,deep+1);
		}
	return ;
}

inline void LCA()
{
	for (int j=1;j<=k;j++)
		for (int i=1;i<=n;i++)
		{
			LCAFather[i][j]=LCAFather[LCAFather[i][j-1]][j-1];
			LCADis[i][j]=LCADis[i][j-1]+LCADis[LCAFather[i][j-1]][j-1];
		}
	return ;
}

inline long long GetDis(int u,int v)
{
	long long res=0;
	if (dep[u]>dep[v]) swap(u,v);
	for (int i=k;~i;i--)
		if (_2pow[i]<=dep[v]-dep[u])
		{
			res+=LCADis[v][i];
			v=LCAFather[v][i];
		}
	for (int i=k;~i;i--)
		if (LCAFather[u][i]!=LCAFather[v][i])
		{
			res+=LCADis[u][i]+LCADis[v][i];
			u=LCAFather[u][i];
			v=LCAFather[v][i];
		}
	if (u!=v) res+=LCADis[u][0]+LCADis[v][0];
	return res;
}

inline void Dijkstra(int pt,int S)
{
	memset(vis,0,sizeof vis);
	q.push((node){0LL,S});dis[pt][S]=0LL;
	while (!q.empty())
	{
		node x=q.top();q.pop();
		if (vis[x.u]) continue;vis[x.u]=true;
		for (int i=head[x.u];~i;i=e[i].nxt)
			if (dis[pt][e[i].to]>dis[pt][x.u]+e[i].val)
			{
				dis[pt][e[i].to]=dis[pt][x.u]+e[i].val;
				q.push((node){dis[pt][e[i].to],e[i].to});
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
	int TT;scanf("%d",&TT);
	while (TT--)
	{
		memset(vis,0,sizeof vis);
		cnt=0;memset(head,-1,sizeof head);memset(dis,0x3f,sizeof dis);
		memset(dep,0,sizeof dep);memset(f,0,sizeof f);
		memset(LCADis,0,sizeof LCADis);memset(LCAFather,0,sizeof LCAFather);
		read(n);read(T);m=n;r[0]=0;
		for (_2pow[k=0]=1;_2pow[k]<=n;k++) _2pow[k+1]=_2pow[k]<<1;
		for (int i=1;i<=m;i++)
		{
			read(u);read(v);read(w);
			add(u,v,w);
		}
		dfs(1,0,0,1);LCA();
		sort(r+1,r+r[0]+1);r[0]=unique(r+1,r+r[0]+1)-r-1;
		for (int i=1;i<=r[0];i++) Dijkstra(i,r[i]);
		while (T--)
		{
			read(x);read(y);
			long long cnt=GetDis(y,x);
			for (int i=1;i<=r[0];i++) cnt=min(cnt,dis[i][y]+dis[i][x]);
			printf("%lld\n",cnt);
		}
	}
	return 0;
}