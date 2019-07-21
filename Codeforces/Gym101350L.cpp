#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct SegmentTree
{
	int p,r,m;long long x,lazy,mx;
};

SegmentTree tree[1<<18];
int T,n,o,p,x,q;
long long a[MAXN],s;

void BuildTree(int u)
{
	tree[u].mx=tree[u].lazy=tree[u].x=0;
	if (tree[u].p+1==tree[u].r) return ;
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	return ;
}

inline void PushDown(int u)
{
	if (!tree[u].lazy) return ;
	tree[u<<1].lazy=tree[u].lazy;
	tree[u<<1].mx=tree[u].lazy;
	tree[u<<1].x=(tree[u<<1].r-tree[u<<1].p)*tree[u].lazy;
	tree[u<<1|1].lazy=tree[u].lazy;
	tree[u<<1|1].mx=tree[u].lazy;
	tree[u<<1|1].x=(tree[u<<1|1].r-tree[u<<1|1].p)*tree[u].lazy;
	tree[u].lazy=0;
	return ;
}

void setval(int u,int l,int r,long long v)
{
	if (l>=r) return ;
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].mx=v;
		tree[u].x=(r-l)*v;
		tree[u].lazy=v;
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) setval(u<<1,l,r,v);
	else if (tree[u].m<=l) setval(u<<1|1,l,r,v);
	else
	{
		setval(u<<1,l,tree[u].m,v);
		setval(u<<1|1,tree[u].m,r,v);
	}
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	tree[u].mx=max(tree[u<<1].mx,tree[u<<1|1].mx);
	return ;
}

inline long long query_pos(int x)
{
	int u=1;
	while (tree[u].p+1!=tree[u].r)
	{
		PushDown(u);
		if (x<tree[u].m) u<<=1;
		else u=u<<1|1;
	}
	return tree[u].mx;
}

inline long long qmax(int u,int l,int r)
{
	if (l>=r) return -1;
	if (tree[u].p==l&&tree[u].r==r) return tree[u].mx;
	PushDown(u);
	if (r<=tree[u].m) return qmax(u<<1,l,r);
	else if (tree[u].m<=l) return qmax(u<<1|1,l,r);
	else return max(qmax(u<<1,l,tree[u].m),qmax(u<<1|1,tree[u].m,r));
}

inline int getl(int u,int l,int r,int v)
{
	if (l>=r) return 0;
	if (tree[u].p+1==tree[u].r) return tree[u].mx<v?0:tree[u].p;
	PushDown(u);
	if (tree[u].mx<v) return 0;
	if (r<=tree[u].m) return getl(u<<1,l,r,v);
	else if (tree[u].m<=l) return getl(u<<1|1,l,r,v);
	else
	{
		int t=getl(u<<1|1,tree[u].m,r,v);
		if (t) return t;
		return getl(u<<1,l,tree[u].m,v);
	}
}

inline int getr(int u,int l,int r,int v)
{
	if (l>=r) return n+1;
	if (tree[u].p+1==tree[u].r) return tree[u].mx<v?n+1:tree[u].p;
	PushDown(u);
	if (tree[u].mx<v) return n+1;
	if (r<=tree[u].m) return getr(u<<1,l,r,v);
	else if (tree[u].m<=l) return getr(u<<1|1,l,r,v);
	else
	{
		int t=getr(u<<1,l,tree[u].m,v);
		if (t!=n+1) return t;
		return getr(u<<1|1,tree[u].m,r,v);
	}
}

inline void add(int x,long long v)
{
	a[x]+=v;s+=v;
	if (query_pos(x)>=a[x]) return ;
	long long st,lmx;
	setval(1,x,x+1,a[x]);
	lmx=qmax(1,1,x);
	if (lmx<=a[x]) st=lmx;
	else st=a[x];
	setval(1,getl(1,1,x,st)+1,x,st);
	lmx=qmax(1,x+1,n+1);
	if (lmx<=a[x]) st=lmx;
	else st=a[x];
	setval(1,x+1,getr(1,x+1,n+1,st),st);
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='P'){x=0;return ;}
		if (ch=='U'){x=1;return ;}
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		memset(a,0,sizeof a);s=0;
		read(n);read(q);
		tree[1].p=1;tree[1].r=n+1;BuildTree(1);
		for (int i=1;i<=n;i++) read(x),add(i,x);
		while (q--)
		{
			read(o);
			if (!o) printf("%lld\n",tree[1].x-s);
			else
			{
				read(x);read(p);
				add(x,p);
			}
		}
	}
	return 0;
}