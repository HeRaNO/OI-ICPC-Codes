#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,m,q,b,o,x,y,R,M,Q,lg[MAXN<<1],pt[MAXN],dep[MAXN<<1];
int fa[18][MAXN<<1],euler[MAXN<<1],par[MAXN];
int sta[MAXN],top,B,bl[MAXN];
int v[MAXN],w[MAXN],a[MAXN],c[MAXN],cnt[MAXN],rdep[MAXN];
long long ans[MAXN],now;
vector <int> g[MAXN];
bool vis[MAXN];

struct Park
{
	int l,r,t,x;
	Park(){}
	Park(int _,int __,int ___,int ____):
		l(_),r(__),t(___),x(____){}
	bool operator < (const Park &a)const{
		if (bl[l]==bl[a.l]) return bl[r]==bl[a.r]?t<a.t:bl[r]<bl[a.r];
		return bl[l]<bl[a.l];
	}
}C[MAXN],Qry[MAXN];

inline void add(int u,int v)
{
	g[u].push_back(v);g[v].push_back(u);
	return ;
}

inline void dfs(int x,int f,int deep)
{
	sta[++top]=x;
	if (top==b)
	{
		++B;
		while (top) bl[sta[top--]]=B;
	}
	pt[x]=++R;euler[R]=x;dep[R]=deep;par[x]=f;rdep[x]=deep;
	for (auto v:g[x])
		if (v!=f)
		{
			dfs(v,x,deep+1);
			euler[++R]=x;dep[R]=deep;
		}
	return ;
}

inline void RMQLCA()
{
	dfs(1,0,0);++B;
	while (top) bl[sta[top--]]=B;
	for (int i=1;i<=R;i++) fa[0][i]=i;
	for (int i=2;i<=R;i++) lg[i]=lg[i>>1]+1;
	for (int j=1;j<=lg[R];j++)
		for (int i=1;i+(1<<j)-1<=R;i++)
		{
			int a=fa[j-1][i],b=fa[j-1][i+(1<<(j-1))];
			fa[j][i]=dep[a]<=dep[b]?a:b;
		}
	return ;
}

inline int getLCA(int x,int y)
{
	x=pt[x];y=pt[y];
	if (x>y) swap(x,y);
	int t=lg[y-x+1];int a=fa[t][x],b=fa[t][y-(1<<t)+1];
	return dep[a]<=dep[b]?euler[a]:euler[b];
}

inline void change(int x)
{
	vis[x]=!vis[x];
	if (vis[x]) now+=1LL*v[c[x]]*w[++cnt[c[x]]];
	else now-=1LL*v[c[x]]*w[cnt[c[x]]--];
	return ;
}

inline void modify(int x,int y)
{
	if (vis[x]) change(x),c[x]=y,change(x);
	else c[x]=y;
	return ;
}

inline void Update(int x,int y)
{
	while (x!=y)
	{
		if (rdep[x]<rdep[y]) swap(x,y);
		change(x);x=par[x];
	}
	return ;
}

inline void TreeModui()
{
	sort(Qry+1,Qry+Q+1);
	Qry[0]=Park(1,1,0,0);
	for (int i=1,t=0,k;i<=Q;i++)
	{
		while (t<Qry[i].t) ++t,modify(C[t].l,C[t].r);
		while (t>Qry[i].t) modify(C[t].l,C[t].t),--t;
		Update(Qry[i].l,Qry[i-1].l);
		Update(Qry[i].r,Qry[i-1].r);
		change(k=getLCA(Qry[i].l,Qry[i].r));
		ans[Qry[i].x]=now;
		change(k);
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
	read(n);read(m);read(q);b=1200;
	for (int i=1;i<=m;i++) read(v[i]);
	for (int i=1;i<=n;i++) read(w[i]);
	for (int i=1;i<n;i++) read(x),read(y),add(x,y);
	for (int i=1;i<=n;i++) read(c[i]),a[i]=c[i];
	RMQLCA();
	for (int i=1;i<=q;i++)
	{
		read(o);read(x);read(y);
		if (!o) C[++M]=Park(x,y,a[x],-1),a[x]=y;
		else ++Q,Qry[Q]=Park(x,y,M,Q);
	}
	TreeModui();
	for (int i=1;i<=Q;i++) printf("%lld\n",ans[i]);
	return 0;
}