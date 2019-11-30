#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct SegmentTree
{
	int p,r,m;long long x,lazy;
};

SegmentTree tree[1<<18];
int n,m,o,l,r,w,a[MAXN];

inline void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r){tree[u].x=a[tree[u].p];return ;}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

inline void PushDown(int u)
{
	if (!tree[u].lazy) return ;
	tree[u<<1].x+=(tree[u<<1].r-tree[u<<1].p)*tree[u].lazy;
	tree[u<<1].lazy+=tree[u].lazy;
	tree[u<<1|1].x+=(tree[u<<1|1].r-tree[u<<1|1].p)*tree[u].lazy;
	tree[u<<1|1].lazy+=tree[u].lazy;
	tree[u].lazy=0;return ;
}

inline void modify(int u,int l,int r,int w)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].lazy+=w;tree[u].x+=1LL*(r-l)*w;
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) modify(u<<1,l,r,w);
	else if (tree[u].m<=l) modify(u<<1|1,l,r,w);
	else
	{
		modify(u<<1,l,tree[u].m,w);
		modify(u<<1|1,tree[u].m,r,w);
	}
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

inline long long query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
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
	read(n);read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (m--)
	{
		read(o);read(l);read(r);
		if (!o) printf("%lld\n",query(1,l,r+1));
		else read(w),modify(1,l,r+1,w);
	}
	return 0;
}