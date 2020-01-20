#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;

struct link
{
	int to,val,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int T,n,k,u,v,w,o,_2pow[15];
int fa[MAXN][15],dis[MAXN],dep[MAXN];

inline void add(int u,int v,int w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,head[v]};head[v]=cnt++;
}

inline void dfs(int x,int f,int deep)
{
	dep[x]=deep;fa[x][0]=f;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f)
		{
			dis[e[i].to]=dis[x]+e[i].val;
			dfs(e[i].to,x,deep+1);
		}
	return ;
}

inline void LCA()
{
	for (int j=1;j<=k;j++)
		for (int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	return ;
}

inline int getLCA(int u,int v)
{
	if (dep[u]>dep[v]) swap(u,v);
	for (int i=k;~i;i--)
		if (_2pow[i]<=dep[v]-dep[u])
			v=fa[v][i];
	if (u==v) return u;
	for (int i=k;~i;i--)
		if (fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[v][0];
}

inline int getDis(int u,int v)
{
	return dis[u]+dis[v]-2*dis[getLCA(u,v)];
}

inline int jump(int u,int v)
{
	for (int i=k;~i;i--) if (v&(1<<i)) u=fa[u][i];
	return u;
}

inline int getKth(int u,int v,int w)
{
	int lca=getLCA(u,v);--w;
	int d=dep[u]-dep[lca],l=dep[u]+dep[v]-(dep[lca]<<1);
	if (d==w) return lca;
	if (d>w) return jump(u,w);
	return jump(v,l-w);
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9')
	{
		if (ch=='D')
		{
			ch=getchar();
			if (ch=='I'){x=0;return ;}
			if (ch=='O'){x=-1;return ;}
		}
		if (ch=='K'){x=1;return ;}
		if (ch=='-') f=true;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(T);
	while (T--)
	{
		read(n);memset(head,-1,sizeof head);cnt=0;
		for (_2pow[k=0]=1;_2pow[k]<=n;k++) _2pow[k+1]=_2pow[k]<<1;
		for (int i=1;i<n;i++)
		{
			read(u);read(v);read(w);
			add(u,v,w);
		}
		dfs(1,0,1);LCA();
		while (true)
		{
			read(o);if (!~o) break;
			read(u);read(v);
			if (!o) printf("%d\n",getDis(u,v));
			else read(w),printf("%d\n",getKth(u,v,w));
		}
		putchar('\n');
	}
	return 0;
}