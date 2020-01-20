#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;

struct link
{
	int to,val,pt,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,T,R,o,y,p,u,v,w[MAXN],vp[MAXN];
int pos[MAXN],top[MAXN],fa[MAXN],x[1<<15];
int in[MAXN],dep[MAXN],siz[MAXN],mx[MAXN];

inline void add(int u,int v,int w,int i)
{
	e[cnt]=(link){v,w,i,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,i,head[v]};head[v]=cnt++;
}

inline void dfs1(int x)
{
	siz[x]=1;mx[x]=-1;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa[x])
		{
			dep[e[i].to]=dep[x]+1;fa[e[i].to]=x;
			w[e[i].to]=e[i].val;vp[e[i].pt]=e[i].to;
			dfs1(e[i].to);
			siz[x]+=siz[e[i].to];
			if (!~mx[x]||siz[e[i].to]>siz[mx[x]]) mx[x]=e[i].to;
		}
	return ;
}

inline void dfs2(int x,int t)
{
	top[x]=t;pos[R]=x;in[x]=R++;
	if (~mx[x]) dfs2(mx[x],t);
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=mx[x]&&e[i].to!=fa[x]) dfs2(e[i].to,e[i].to);
	return ;
}

inline void BuildTree(int u,int l,int r)
{
	if (l+1==r){x[u]=w[pos[l]];return ;}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u]=max(x[u<<1],x[u<<1|1]);
	return ;
}

inline void modify(int u,int px,int v,int pl,int pr)
{
	if (pl+1==pr){x[u]=v;return ;}
	int m=pl+pr>>1;
	if (px<m) modify(u<<1,px,v,pl,m);
	else modify(u<<1|1,px,v,m,pr);
	x[u]=max(x[u<<1],x[u<<1|1]);
	return ;
}

inline int query(int u,int l,int r,int pl,int pr)
{
	if (pl==l&&pr==r) return x[u];
	int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return max(query(u<<1,l,m,pl,m),query(u<<1|1,m,r,m,pr));
}

inline int Q(int l,int r)
{
	int res=0;
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		res=max(res,query(1,in[top[l]],in[l]+1,1,n+1));
		l=fa[top[l]];
	}
	if (in[l]>in[r]) swap(l,r);
	if (in[l]!=in[r])
		res=max(res,query(1,in[l]+1,in[r]+1,1,n+1));
	return res;
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9')
	{
		if (ch=='C'){x=0;return ;}
		if (ch=='Q'){x=1;return ;}
		if (ch=='D'){x=-1;return ;}
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
		read(n);memset(head,-1,sizeof head);cnt=0;R=1;
		memset(siz,0,sizeof siz);memset(fa,0,sizeof fa);
		for (int i=1;i<n;i++)
		{
			read(u);read(v);read(p);
			add(u,v,p,i);
		}
		dfs1(1);dfs2(1,1);BuildTree(1,1,n+1);
		while (true)
		{
			read(o);if (!~o) break;
			read(y);read(p);
			if (!o) modify(1,in[vp[y]],p,1,n+1);
			else printf("%d\n",Q(y,p));
		}
	}
	return 0;
}