#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

vector <pair<int,int> > g[MAXN];
vector <int> e[MAXN];
int n,m,q,T,R=1,u,v,bcc,TOP,f[MAXN],ff[MAXN];
int dfn[MAXN],low[MAXN],vbel[MAXN],sta[MAXN];
bool vis[MAXN];
int in[MAXN],top[MAXN],fa[MAXN];
int dep[MAXN],siz[MAXN],MX[MAXN];
int mn[1<<19],mx[1<<19],lazy[1<<19];

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}
inline int getff(int x){return x==ff[x]?x:ff[x]=getff(ff[x]);}

inline void add(int u,int v,int i)
{
	int fx=getf(u),fy=getf(v);
	if (fx!=fy) f[fy]=fx;
	g[u].push_back({v,i});g[v].push_back({u,i});
	return ;
}

inline void adde(int u,int v)
{
	int fx=getff(u),fy=getff(v);
	if (fx!=fy)
	{
		ff[fy]=fx;
		e[u].push_back(v);e[v].push_back(u);
	}
	return ;
}

inline void Tarjan(int x)
{
	dfn[x]=low[x]=++T;sta[++TOP]=x;
	for (auto i:g[x])
	{
		int v=i.first,pt=i.second;
		if (vis[pt]) continue;
		vis[pt]=true;
		if (dfn[v]) low[x]=min(low[x],dfn[v]);
		else
		{
			Tarjan(v);
			low[x]=min(low[x],low[v]);
		}
	}
	if (dfn[x]==low[x])
	{
		vbel[x]=++bcc;
		while (sta[TOP]!=x) vbel[sta[TOP--]]=bcc;
		TOP--;
	}
	return ;
}

inline void dfs1(int x)
{
	siz[x]=1;MX[x]=-1;
	for (auto v:e[x])
		if (v!=fa[x])
		{
			dep[v]=dep[x]+1;fa[v]=x;
			dfs1(v);
			siz[x]+=siz[v];
			if (!~MX[x]||siz[v]>siz[MX[x]]) MX[x]=v;
		}
	return ;
}

inline void dfs2(int x,int t)
{
	top[x]=t;in[x]=R++;
	if (~MX[x]) dfs2(MX[x],t);
	for (auto v:e[x]) if (v!=MX[x]&&v!=fa[x]) dfs2(v,v);
	return ;
}

inline void color(int u,int v)
{
	mx[u]=mn[u]=lazy[u]=v;
	return ;
}

inline void PushDown(int u)
{
	if (!lazy[u]) return ;
	color(u<<1,lazy[u]);color(u<<1|1,lazy[u]);lazy[u]=0;
	return ;
}

inline void modify(int u,int l,int r,int v,int pl,int pr)
{
	if (l==pl&&r==pr){color(u,v);return ;}
	int m=pl+pr>>1;PushDown(u);
	if (r<=m) modify(u<<1,l,r,v,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,v,m,pr);
	else
	{
		modify(u<<1,l,m,v,pl,m);
		modify(u<<1|1,m,r,v,m,pr);
	}
	mx[u]=max(mx[u<<1],mx[u<<1|1]);
	mn[u]=min(mn[u<<1],mn[u<<1|1]);
	return ;
}

inline int qmin(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return mn[u];
	int m=pl+pr>>1;PushDown(u);
	if (r<=m) return qmin(u<<1,l,r,pl,m);
	else if (m<=l) return qmin(u<<1|1,l,r,m,pr);
	else return min(qmin(u<<1,l,m,pl,m),qmin(u<<1|1,m,r,m,pr));
}

inline int qmax(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return mx[u];
	int m=pl+pr>>1;PushDown(u);
	if (r<=m) return qmax(u<<1,l,r,pl,m);
	else if (m<=l) return qmax(u<<1|1,l,r,m,pr);
	else return max(qmax(u<<1,l,m,pl,m),qmax(u<<1|1,m,r,m,pr));
}

inline void C(int l,int r,int v)
{
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		modify(1,in[top[l]],in[l]+1,v,1,bcc+2);
		l=fa[top[l]];
	}
	if (in[l]>in[r]) swap(l,r);
	if (in[l]<in[r]) modify(1,in[l]+1,in[r]+1,v,1,bcc+2);
	return ;
}

inline int Qmn(int l,int r)
{
	int res=0;
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		res=min(qmin(1,in[top[l]],in[l]+1,1,bcc+2),res);
		l=fa[top[l]];
	}
	if (in[l]>in[r]) swap(l,r);
	if (in[l]<in[r]) res=min(res,qmin(1,in[l]+1,in[r]+1,1,bcc+2));
	return res;
}

inline int Qmx(int l,int r)
{
	int res=0;
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		res=max(qmax(1,in[top[l]],in[l]+1,1,bcc+2),res);
		l=fa[top[l]];
	}
	if (in[l]>in[r]) swap(l,r);
	if (in[l]<in[r]) res=max(res,qmax(1,in[l]+1,in[r]+1,1,bcc+2));
	return res;
}

inline int getLCA(int l,int r)
{
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		l=fa[top[l]];
	}
	return dep[l]<dep[r]?l:r;
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
	memset(fa,-1,sizeof fa);
	read(n);read(m);read(q);
	for (int i=1;i<=n;i++) f[i]=ff[i]=i;
	for (int i=1;i<=m;i++) read(u),read(v),add(u,v,i);
	for (int i=1;i<=n;i++) if (!dfn[i]) T=0,Tarjan(i);
	for (int i=1;i<=n;i++)
		for (auto v:g[i])
			if (vbel[i]!=vbel[v.first])
				adde(vbel[i],vbel[v.first]);
	adde(0,getff(1));
	for (int i=2;i<=bcc;i++) if (getff(i)!=getff(1)) adde(i,0);
	dfs1(0);dfs2(0,0);
	while (q--)
	{
		read(u);read(v);
		if (getf(u)!=getf(v)) return puts("No"),0;
		u=vbel[u];v=vbel[v];
		int lca=getLCA(u,v);
		if (Qmn(u,lca)==-1||Qmx(lca,v)==1) return puts("No"),0;
		C(u,lca,1);C(lca,v,-1);
	}
	puts("Yes");
	return 0;
}