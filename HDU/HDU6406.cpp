#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct SegmentTree
{
	int p,r,m,x,mx;
};

SegmentTree tree[1<<18];
int T,n,m,a[MAXN],p,b;

inline int query(int u,int v)
{
	if (tree[u].p+1==tree[u].r) return tree[u].mx>v;
	if (tree[u].mx<=v) return 0;
	if (tree[u<<1].mx<=v) return query(u<<1|1,v);
	else return tree[u].x-tree[u<<1].x+query(u<<1,v);
}

inline void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=1;
		tree[u].mx=a[tree[u].p];
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=tree[u<<1].x+query(u<<1|1,tree[u<<1].mx);
	tree[u].mx=max(tree[u<<1].mx,tree[u<<1|1].mx);
	return ;
}

inline void modify(int u,int x,int v)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].mx=v;tree[u].x=1;
		return ;
	}
	if (x<tree[u].m) modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	tree[u].x=tree[u<<1].x+query(u<<1|1,tree[u<<1].mx);
	tree[u].mx=max(tree[u<<1].mx,tree[u<<1|1].mx);
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		tree[1].p=1;tree[1].r=n+1;BuildTree(1);
		while (m--)
		{
			scanf("%d %d",&p,&b);
			modify(1,p,b);
			printf("%d\n",tree[1].x);
			modify(1,p,a[p]);
		}
	}
	return 0;
}