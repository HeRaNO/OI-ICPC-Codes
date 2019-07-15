#include <bits/stdc++.h>
using namespace std;

struct SegmentTree
{
	int p,r,m,x;
};

SegmentTree tree[1<<19];
int h,w,n,ans,v;

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r){tree[u].x=w;return ;}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=max(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

void add(int u,int v)
{
	if (tree[u].p+1==tree[u].r)
	{
		ans=tree[u].p;
		tree[u].x-=v;
		return ;
	}
	if (v<=tree[u<<1].x) add(u<<1,v);
	else add(u<<1|1,v);
	tree[u].x=max(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

int main()
{
	while (~scanf("%d %d %d",&h,&w,&n))
	{
		tree[1].p=1;tree[1].r=min(n,h)+1;BuildTree(1);
		for (int i=1;i<=n;i++)
		{
			ans=-1;
			scanf("%d",&v);
			if (v<=tree[1].x) add(1,v);
			printf("%d\n",ans);
		}
	}
	return 0;
}