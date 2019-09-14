#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct SegmentTree
{
	int p,r,m,mx,mn;long long x,lazy;
};

SegmentTree tree[1<<18];
int n,m,o,l,r,x;

inline void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].mn=tree[u].mx=tree[u].p;
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].mx=max(tree[u<<1].mx,tree[u<<1|1].mx);
	tree[u].mn=min(tree[u<<1].mn,tree[u<<1|1].mn);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

inline void PushDown(int u)
{
	if (!tree[u].lazy) return ;
	tree[u<<1].lazy+=tree[u].lazy;
	tree[u<<1].x+=1LL*(tree[u<<1].r-tree[u<<1].p)*tree[u].lazy;
	tree[u<<1].mx=tree[u].mx;tree[u<<1].mn=tree[u].mn;
	tree[u<<1|1].lazy+=tree[u].lazy;
	tree[u<<1|1].x+=1LL*(tree[u<<1|1].r-tree[u<<1|1].p)*tree[u].lazy;
	tree[u<<1|1].mx=tree[u].mx;tree[u<<1|1].mn=tree[u].mn;
	tree[u].lazy=0;
	return ;
}

inline void modify(int u,int l,int r,int x)
{
	if (tree[u].p==l&&tree[u].r==r&&tree[u].mx==tree[u].mn)
	{
		tree[u].x+=1LL*(r-l)*abs(x-tree[u].mx);
		tree[u].lazy+=abs(x-tree[u].mx);
		tree[u].mx=tree[u].mn=x;
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) modify(u<<1,l,r,x);
	else if (tree[u].m<=l) modify(u<<1|1,l,r,x);
	else
	{
		modify(u<<1,l,tree[u].m,x);
		modify(u<<1|1,tree[u].m,r,x);
	}
	tree[u].mx=max(tree[u<<1].mx,tree[u<<1|1].mx);
	tree[u].mn=min(tree[u<<1].mn,tree[u<<1|1].mn);
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

int main()
{
	scanf("%d %d",&n,&m);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (m--)
	{
		scanf("%d %d %d",&o,&l,&r);
		if (o==1)
		{
			scanf("%d",&x);
			modify(1,l,r+1,x);
		}
		else printf("%lld\n",query(1,l,r+1));
	}
	return 0;
}
