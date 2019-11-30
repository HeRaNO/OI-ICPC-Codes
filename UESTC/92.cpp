#include <bits/stdc++.h>
#define MAXN 100005
#define MAXK 18
using namespace std;

struct link
{
	int to,val,nxt;
};

struct node
{
	int d,u;
	bool operator < (const node &a)const{
		return d>a.d;
	}
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,T,R,k,u,v,w,x,y,ans,dep[MAXN],_2pow[MAXK];
int dis[2][MAXN],LCAFather[MAXN][MAXK],LCADis[MAXN][MAXK];
bool vis[MAXN];
priority_queue <node> q;

inline void add(int u,int v,int w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,head[v]};head[v]=cnt++;
}

inline void dfs(int x,int fa,int val,int deep)
{
	LCAFather[x][0]=fa;LCADis[x][0]=val;dep[x]=deep;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa)
			dfs(e[i].to,x,e[i].val,deep+1);
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

inline int GetDis(int u,int v)
{
	int res=0;
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
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(T);
	for (int cas=1;cas<=T;cas++)
	{
		printf("Case #%d:\n",cas);
		memset(head,-1,sizeof head);memset(dis,0x3f,sizeof dis);
		read(n);read(R);k=cnt=0;
		for (_2pow[0]=1;_2pow[k]<=n;k++) _2pow[k+1]=_2pow[k]<<1;
		for (int i=1;i<n;i++)
		{
			read(u);read(v);read(w);
			add(u,v,w);
		}
		dfs(1,0,0,1);LCA();
		read(u);read(v);read(w);add(u,v,w);
		Dijkstra(0,u);Dijkstra(1,v);
		while (R--)
		{
			read(x);read(y);
			u=GetDis(x,y);
			v=min(dis[0][x]+dis[0][y],dis[1][x]+dis[1][y]);
			if (u>v) ans=u-v;
			else ans=0;
			printf("%d\n",ans);
		}
	}
	return 0;
}