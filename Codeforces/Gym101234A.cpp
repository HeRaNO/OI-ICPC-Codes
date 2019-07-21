#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

struct SegmentTree
{
	int p,r,m,x,lazy;
};

SegmentTree tree[1<<18];
int n,m,l,r,a[MAXN],ans;
pair <int,int> q[MAXN+1];

void BuildTree(int u,int v)
{
	tree[u].lazy=-1;
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=(a[tree[u].p]>=v);
		return;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1,v);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1,v);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

inline void PushDown(int u)
{
	if (!~tree[u].lazy) return ;
	tree[u<<1].lazy=tree[u].lazy;tree[u<<1].x=(tree[u<<1].r-tree[u<<1].p)*tree[u].lazy;
	tree[u<<1|1].lazy=tree[u].lazy;tree[u<<1|1].x=(tree[u<<1|1].r-tree[u<<1|1].p)*tree[u].lazy;
	tree[u].lazy=-1;
	return ;
}

inline void modify(int u,int l,int r,int v)
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

inline int query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	PushDown(u);
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return query(u<<1,l,tree[u].m)+query(u<<1|1,tree[u].m,r);
}

inline int query_pos(int x)
{
	int u=1;
	while (tree[u].p+1!=tree[u].r)
	{
		PushDown(u);
		if (x<tree[u].m) u<<=1;
		else u=u<<1|1;
	}
	return tree[u].x;
}

inline bool check(int p)
{
	tree[1].p=1;tree[1].r=n+1;BuildTree(1,p);
	for (int i=1;i<=m;i++)
	{
		int l=q[i].first,r=q[i].second;
		int x=query(1,min(l,r),max(l,r)+1);
		if (l>r)
		{
			swap(l,r);
			if (x>0) modify(1,l,l+x,1);
			if (x<r-l+1) modify(1,l+x,r+1,0);
		}
		else
		{
			if (x>0) modify(1,r-x+1,r+1,1);
			if (x<r-l+1) modify(1,l,r-x+1,0);
		}
	}
	return query_pos(n/2+1);
}

int main()
{
	scanf("%d %d",&n,&m);l=1;r=n;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d %d",&q[i].first,&q[i].second);
	while (l<=r)
	{
		int mid=l+r>>1;
		if (check(mid)){ans=mid;l=mid+1;}
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
