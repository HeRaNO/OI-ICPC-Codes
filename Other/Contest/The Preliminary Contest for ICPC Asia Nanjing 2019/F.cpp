#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct SegmentTree
{
	int p,r,m,x;
};

SegmentTree tree[1<<18];
int T,n,k,a[MAXN],pos[MAXN],ans[MAXN];

void BuildTree(int u)
{
	tree[u].x=0;
	if (tree[u].p+1==tree[u].r) return ;
	tree[u].m=(tree[u].p+tree[u].r)>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=max(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline void modify(int u,int x,int v)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=v;return ;
	}
	if (x<tree[u].m) modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	tree[u].x=max(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline int query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return max(query(u<<1,l,tree[u].m),query(u<<1|1,tree[u].m,r));
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&k);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			pos[a[i]]=i;
		}
		tree[1].p=1;tree[1].r=n+1;BuildTree(1);
		for (int i=1;i<=n;i++)
		{
			int temp;
			temp=query(1,max(pos[i]-k,1),min(pos[i]+k+1,n+1));
			ans[i]=ans[temp]+1;
			modify(1,pos[i],i);
		}
		for (int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	}
	return 0;
}