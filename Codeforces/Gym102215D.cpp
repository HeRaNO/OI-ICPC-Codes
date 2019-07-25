#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct SegmentTree
{
	int p,r,m,x,lazy;
};

struct link
{
	int to,nxt;
};

SegmentTree tree[1<<19];
link e[MAXN<<1];
int head[MAXN],cnt;
int n,T,R,u,v,fr,fb,r,b;
int dep[MAXN],in[MAXN],fa[MAXN],siz[MAXN],mx[MAXN],top[MAXN];
int rr[MAXN],bb[MAXN];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline void dfs1(int x)
{
	siz[x]=1;mx[x]=-1;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa[x])
		{
			fa[e[i].to]=x;dep[e[i].to]=dep[x]+1;
			dfs1(e[i].to);
			siz[x]+=siz[e[i].to];
			if (!~mx[x]||siz[mx[x]]<siz[e[i].to]) mx[x]=e[i].to;
		}
	return ;
}

inline void dfs2(int x,int t)
{
	top[x]=t;in[x]=++R;
	if (~mx[x]) dfs2(mx[x],t);
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=mx[x]&&e[i].to!=fa[x]) dfs2(e[i].to,e[i].to);
	return ;
}

void BuildTree(int u)
{
	tree[u].lazy=-1;
	if (tree[u].p+1==tree[u].r) return ;
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	return ;
}

inline void PushDown(int u)
{
	if (!~tree[u].lazy) return ;
	tree[u<<1].lazy=tree[u].lazy;
	tree[u<<1].x=(tree[u<<1].r-tree[u<<1].p)*tree[u].lazy;
	tree[u<<1|1].lazy=tree[u].lazy;
	tree[u<<1|1].x=(tree[u<<1|1].r-tree[u<<1|1].p)*tree[u].lazy;
	tree[u].lazy=-1;
	return ;
}

void modify(int u,int x,int v)
{
	if (tree[u].p+1==tree[u].r){tree[u].x=v;return ;}
	PushDown(u);
	if (x<tree[u].m) modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

void modify(int u,int l,int r,int v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].lazy=v;
		tree[u].x=(r-l)*v;
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) modify(u<<1,l,r,v);
	else if (tree[u].m<=l) modify(u<<1|1,l,r,v);
	else
	{
		modify(u<<1,l,tree[u].m,v);
		modify(u<<1|1,tree[u].m,r,v);
	}
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

int query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	PushDown(u);
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return query(u<<1,l,tree[u].m)+query(u<<1|1,tree[u].m,r);
}

int lca;

inline void addlink(int l,int r,int v)
{
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		modify(1,in[top[l]],in[l]+1,v);
		l=fa[top[l]];
	}
	lca=dep[l]>dep[r]?r:l;
	if (in[l]>in[r]) swap(l,r);
	modify(1,in[l],in[r]+1,v);
	return ;
}

inline int qlink(int l,int r)
{
	int res=0;
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		res+=query(1,in[top[l]],in[l]+1);
		l=fa[top[l]];
	}
	lca=dep[l]>dep[r]?r:l;
	if (in[l]>in[r]) swap(l,r);
	res+=query(1,in[l],in[r]+1);
	return res;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		add(u,v);
	}
	dfs1(1);dfs2(1,1);tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&r,&b);bool f=true;
		for (int i=1;i<=r;i++) scanf("%d",&rr[i]);
		for (int i=1;i<=b;i++) scanf("%d",&bb[i]);
		modify(1,in[rr[1]],1);fr=rr[1];
		for (int i=2;i<=r;i++)
		{
			addlink(fr,rr[i],1);
			fr=lca;
		}
		fb=bb[1];
		for (int i=2;i<=b&&f;i++)
		{
			if (qlink(fb,bb[i])) f=false;
			fb=lca;
		}
		tree[1].lazy=0;tree[1].x=0;
		if (!f){puts("NO");continue;}
		modify(1,in[bb[1]],1);fb=bb[1];
		for (int i=2;i<=b;i++)
		{
			addlink(fb,bb[i],1);
			fb=lca;
		}
		fr=rr[1];
		for (int i=2;i<=r&&f;i++)
		{
			if (qlink(fr,rr[i])) f=false;
			fr=lca;
		}
		tree[1].lazy=0;tree[1].x=0;
		puts(f?"YES":"NO");
	}
	return 0;
}