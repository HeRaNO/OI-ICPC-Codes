#include <cstdio>
#define MAXN 100005
using namespace std;

struct SegmentTree
{
	int p,r,m;
	int x[20],lazy[20],rev[20];
};

SegmentTree tree[1<<18];
int n,m,o,l,r,x,a[MAXN];

inline void BuildTree(int u)
{
	for (int i=0;i<20;i++) tree[u].lazy[i]=-1;
	if (tree[u].p+1==tree[u].r)
	{
		int v=a[tree[u].p];
		for (int i=0;i<20;i++) tree[u].x[i]=((v&(1<<i))!=0);
		return ;
	}
	tree[u].m=tree[u].r+tree[u].p>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	for (int i=0;i<20;i++) tree[u].x[i]=tree[u<<1].x[i]+tree[u<<1|1].x[i];
	return ;
}

inline void MakeSame(int u,int i,int v)
{
	tree[u].rev[i]=0;
	if (v) tree[u].x[i]=tree[u].r-tree[u].p;
	else tree[u].x[i]=0;
	tree[u].lazy[i]=v;
	return ;
}

inline void Rev(int u,int i)
{
	tree[u].x[i]=tree[u].r-tree[u].p-tree[u].x[i];
	tree[u].rev[i]^=1;
	return ;
}

inline void PushDown(int u)
{
	for (int i=0;i<20;i++)
	{
		if (~tree[u].lazy[i])
		{
			MakeSame(u<<1,i,tree[u].lazy[i]);
			MakeSame(u<<1|1,i,tree[u].lazy[i]);
			tree[u].lazy[i]=-1;
		}
		if (tree[u].rev[i])
		{
			Rev(u<<1,i);Rev(u<<1|1,i);
			tree[u].rev[i]=0;
		}
	}
	return ;
}

inline void mxor(int u,int l,int r,int v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		for (int i=0;i<20;i++) if (v&(1<<i)) Rev(u,i);
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) mxor(u<<1,l,r,v);
	else if (tree[u].m<=l) mxor(u<<1|1,l,r,v);
	else
	{
		mxor(u<<1,l,tree[u].m,v);
		mxor(u<<1|1,tree[u].m,r,v);
	}
	for (int i=0;i<20;i++) tree[u].x[i]=tree[u<<1].x[i]+tree[u<<1|1].x[i];
	return ;
}

inline void mor(int u,int l,int r,int v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		for (int i=0;i<20;i++) if (v&(1<<i)) MakeSame(u,i,1);
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) mor(u<<1,l,r,v);
	else if (tree[u].m<=l) mor(u<<1|1,l,r,v);
	else
	{
		mor(u<<1,l,tree[u].m,v);
		mor(u<<1|1,tree[u].m,r,v);
	}
	for (int i=0;i<20;i++) tree[u].x[i]=tree[u<<1].x[i]+tree[u<<1|1].x[i];
	return ;
}

inline void mand(int u,int l,int r,int v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		for (int i=0;i<20;i++) if (!(v&(1<<i))) MakeSame(u,i,0);
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) mand(u<<1,l,r,v);
	else if (tree[u].m<=l) mand(u<<1|1,l,r,v);
	else
	{
		mand(u<<1,l,tree[u].m,v);
		mand(u<<1|1,tree[u].m,r,v);
	}
	for (int i=0;i<20;i++) tree[u].x[i]=tree[u<<1].x[i]+tree[u<<1|1].x[i];
	return ;
}

inline long long query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		long long r=1,ans=0;
		for (int i=0;i<20;i++,r<<=1) ans+=r*tree[u].x[i];
		return ans;
	}
	PushDown(u);
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return query(u<<1,l,tree[u].m)+query(u<<1|1,tree[u].m,r);
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
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	read(m);
	while (m--)
	{
		read(o);read(l);read(r);if (o!=1) read(x);
		if (o==1) printf("%lld\n",query(1,l,r+1));
		else if (o==2) mxor(1,l,r+1,x);
		else if (o==3) mor(1,l,r+1,x);
		else mand(1,l,r+1,x);
	}
	return 0;
}