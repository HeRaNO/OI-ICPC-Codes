#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

struct SegmentTree
{
	int p,r,m;
	long long x,mx,mn,lazy;
};

SegmentTree tree[1<<21];
int n,T,l,r,k,o;

inline void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r) return ;
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	return ;
}

inline void PushDown(int u)
{
	if (!tree[u].lazy) return ;
	tree[u<<1].lazy+=tree[u].lazy;
	tree[u<<1].x+=(tree[u<<1].r-tree[u<<1].p)*tree[u].lazy;
	tree[u<<1].mn+=tree[u].lazy;tree[u<<1].mx+=tree[u].lazy;
	tree[u<<1|1].lazy+=tree[u].lazy;
	tree[u<<1|1].x+=(tree[u<<1|1].r-tree[u<<1|1].p)*tree[u].lazy;
	tree[u<<1|1].mn+=tree[u].lazy;tree[u<<1|1].mx+=tree[u].lazy;
	tree[u].lazy=0;
	return ;
}

inline void add(int u,int l,int r,long long v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].x+=(r-l)*v;
		tree[u].mn+=v;tree[u].mx+=v;tree[u].lazy+=v;
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) add(u<<1,l,r,v);
	else if (tree[u].m<=l) add(u<<1|1,l,r,v);
	else
	{
		add(u<<1,l,tree[u].m,v);
		add(u<<1|1,tree[u].m,r,v);
	}
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	tree[u].mn=min(tree[u<<1].mn,tree[u<<1|1].mn);
	tree[u].mx=max(tree[u<<1].mx,tree[u<<1|1].mx);
	return ;
}

inline long long qsum(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	PushDown(u);
	if (r<=tree[u].m) return qsum(u<<1,l,r);
	else if (tree[u].m<=l) return qsum(u<<1|1,l,r);
	else return qsum(u<<1,l,tree[u].m)+qsum(u<<1|1,tree[u].m,r);
}

inline long long qmin(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].mn;
	PushDown(u);
	if (r<=tree[u].m) return qmin(u<<1,l,r);
	else if (tree[u].m<=l) return qmin(u<<1|1,l,r);
	else return min(qmin(u<<1,l,tree[u].m),qmin(u<<1|1,tree[u].m,r));
}

inline long long qmax(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].mx;
	PushDown(u);
	if (r<=tree[u].m) return qmax(u<<1,l,r);
	else if (tree[u].m<=l) return qmax(u<<1|1,l,r);
	else return max(qmax(u<<1,l,tree[u].m),qmax(u<<1|1,tree[u].m,r));
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
	read(n);read(T);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (T--)
	{
		read(o);read(l);read(r);
		if (o==1)
		{
			read(k);add(1,l,r+1,k);
		}
		else if (o==2) printf("%lld\n",qsum(1,l,r+1));
		else printf("%lld\n",qmax(1,l,r+1)-qmin(1,l,r+1));
	}
	return 0;
}
