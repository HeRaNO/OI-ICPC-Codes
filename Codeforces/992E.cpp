#include <bits/stdc++.h>
#define MAXN 300010
using namespace std;

struct SegmentTree
{
	int p,r,m;long long x,mx,lazy;
};

SegmentTree tree[1<<19];
int n,q,p,x;
long long a[MAXN];

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=a[tree[u].p];tree[u].mx=a[tree[u].p];
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	tree[u].mx=max(tree[u<<1].mx,tree[u<<1|1].mx);
	return ;
}

void modify(int u,int x,int v)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=tree[u].mx=v;return ;
	}
	if (x<tree[u].m) modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	tree[u].mx=max(tree[u<<1].mx,tree[u<<1|1].mx);
	return ;
}

long long query(int u,int l,int r)
{
	if (l==r) return 0;
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return query(u<<1,l,tree[u].m)+query(u<<1|1,tree[u].m,r);
}

int querypos(int u,int l,int r,long long v)
{
	if (tree[u].p+1==tree[u].r) return tree[u].mx<v?-1:l;
	if (tree[u].mx<v) return -1;
	if (r<=tree[u].m) return querypos(u<<1,l,r,v);
	else if (tree[u].m<=l) return querypos(u<<1|1,l,r,v);
	else
	{
		int re=querypos(u<<1,l,tree[u].m,v);
		if (~re) return re;
		return querypos(u<<1|1,tree[u].m,r,v);
	}
}

int solve(int x,long long v)
{
	modify(1,x,v);
	int p=1,pt;
	while (true)
	{
		if (p>n) return -1;
		long long s=query(1,1,p);
		pt=querypos(1,p,n+1,s);
		if (!~pt) return -1;
		if (query(1,1,pt)==query(1,pt,pt+1)) return pt;
		p=pt+1;
	}
}

int main()
{
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (q--)
	{
		scanf("%d %d",&p,&x);
		printf("%d\n",solve(p,x));
	}
	return 0;
}