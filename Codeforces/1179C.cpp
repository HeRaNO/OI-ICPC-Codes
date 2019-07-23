#include <bits/stdc++.h>
#define MAXN 300010
using namespace std;

const int R=1e6;

struct SegmentTree
{
	int p,r,m,x,lazy;
};

SegmentTree tree[1<<21];
int n,m,T,a[MAXN],b[MAXN],o,p,x;

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
	tree[u<<1].lazy+=tree[u].lazy;tree[u<<1].x+=tree[u].lazy;
	tree[u<<1|1].lazy+=tree[u].lazy;tree[u<<1|1].x+=tree[u].lazy;
	tree[u].lazy=0;
	return ;
}

inline void modify(int u,int l,int r,int v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].lazy+=v;tree[u].x+=v;
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
	tree[u].x=max(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline int query(int u)
{
	if (tree[u].x<=0) return -1;
	if (tree[u].p+1==tree[u].r) return tree[u].p;
	PushDown(u);
	if (tree[u<<1|1].x>0) return query(u<<1|1);
	return query(u<<1);
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
	tree[1].p=1;tree[1].r=R+1;BuildTree(1);
	read(n);read(m);
	for (int i=1;i<=n;i++)
	{
		read(a[i]);
		modify(1,1,a[i]+1,1);
	}
	for (int i=1;i<=m;i++)
	{
		read(b[i]);
		modify(1,1,b[i]+1,-1);
	}
	read(T);
	while (T--)
	{
		read(o);read(p);read(x);
		if (!--o)
		{
			modify(1,1,a[p]+1,-1);
			a[p]=x;
			modify(1,1,a[p]+1,1);
		}
		else
		{
			modify(1,1,b[p]+1,1);
			b[p]=x;
			modify(1,1,b[p]+1,-1);
		}
		printf("%d\n",query(1));
	}
	return 0;
}