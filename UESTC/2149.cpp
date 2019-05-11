#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct SegmentTree
{
	int p,r,m;bool se;
	long long x,b,mn,s;
};

SegmentTree tree[1<<18];
int n,T,o,l,r;
long long a[MAXN],b[MAXN],s[MAXN];

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=a[tree[u].p]-b[tree[u].p];
		tree[u].mn=tree[u].x;
		tree[u].b=b[tree[u].p];
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].mn=min(tree[u<<1].mn,tree[u<<1|1].mn);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	tree[u].b=tree[u<<1].b+tree[u<<1|1].b;
	return ;
}

inline void Pushdown(int u)
{
	if (!tree[u].se) return ;
	tree[u<<1].x=(tree[u<<1].r-tree[u<<1].p)*tree[u].s;
	tree[u<<1].mn=tree[u].s;
	tree[u<<1].se=true;tree[u<<1].s=tree[u].s;
	tree[u<<1|1].x=(tree[u<<1|1].r-tree[u<<1|1].p)*tree[u].s;
	tree[u<<1|1].mn=tree[u].s;
	tree[u<<1|1].se=true;tree[u<<1|1].s=tree[u].s;
	tree[u].se=false;
	return ;
}

void modify(int u,int l,int r,long long v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].s=v;
		tree[u].x=(r-l)*v;tree[u].mn=v;
		tree[u].se=true;
		return ;
	}
	Pushdown(u);
	if (r<=tree[u].m) modify(u<<1,l,r,v);
	else if (tree[u].m<=l) modify(u<<1|1,l,r,v);
	else
	{
		modify(u<<1,l,tree[u].m,v);
		modify(u<<1|1,tree[u].m,r,v);
	}
	tree[u].mn=min(tree[u<<1].mn,tree[u<<1|1].mn);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

inline long long modify_one(int u,int x,long long v)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x+=v;tree[u].mn+=v;return tree[u].x;
	}
	Pushdown(u);
	long long p;
	if (x<tree[u].m) p=modify_one(u<<1,x,v);
	else p=modify_one(u<<1|1,x,v);
	tree[u].mn=min(tree[u<<1].mn,tree[u<<1|1].mn);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return p;
}

inline int qmin(int u,int l,int r,long long x)
{
	if (tree[u].p+1==tree[u].r) return tree[u].x<x?l:-1;
	Pushdown(u);
	if (tree[u].mn>=x) return -1;
	if (r<=tree[u].m) return qmin(u<<1,l,r,x);
	else if (tree[u].m<=l) return qmin(u<<1|1,l,r,x);
	else
	{
		int t=qmin(u<<1|1,tree[u].m,r,x);
		if (~t) return t;
		else return qmin(u<<1,l,tree[u].m,x);
	}
}

inline pair<long long,long long> query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return make_pair(tree[u].x,tree[u].b);
	Pushdown(u);
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else
	{
		pair<long long,long long> ll,rr;
		ll=query(u<<1,l,tree[u].m);
		rr=query(u<<1|1,tree[u].m,r);
		return make_pair(ll.first+rr.first,ll.second+rr.second);
	}
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

inline void read(long long &x)
{
	x=0LL;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<n;i++) read(b[i]);
	for (int i=1;i<n;i++) b[i]+=b[i-1];
	for (int i=n;i;i--) b[i]=b[i-1];
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	read(T);
	while (T--)
	{
		read(o);read(l);read(r);--o;
		if (o)
		{
			pair<long long,long long> res=query(1,l,r+1);
			printf("%lld\n",res.first+res.second);
		}
		else
		{
			long long x=modify_one(1,l,r);
			int p=qmin(1,l,n+1,x);
			if (!~p) continue;
			if (l!=p&&l<n) modify(1,l+1,p+1,x);
		}
	}
	return 0;
}
