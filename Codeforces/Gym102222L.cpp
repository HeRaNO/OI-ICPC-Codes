#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

const long long INF=1e15;

struct L
{
	int a,b;
	L(){}
	L(int _,int __):a(_),b(__){}
};

struct SegmentTree
{
	int p,r,m;long long lazy,x,mn;
};

L mx[MAXN],mn[MAXN];
SegmentTree tree[1<<18];
int T,n,x,l,v,cas,pmx,pmn;
long long ans;
map <int,int> hsh;

inline void PushUp(int u)
{
	tree[u].mn=min(tree[u<<1].mn,tree[u<<1|1].mn);
	if (tree[u<<1].mn==tree[u<<1|1].mn) tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	else if (tree[u<<1].mn<tree[u<<1|1].mn) tree[u].x=tree[u<<1].x;
	else tree[u].x=tree[u<<1|1].x;
	return ;
}

inline void PushDown(int u)
{
	if (!tree[u].lazy) return ;
	tree[u<<1].lazy+=tree[u].lazy;tree[u<<1|1].lazy+=tree[u].lazy;
	tree[u<<1].mn+=tree[u].lazy;tree[u<<1|1].mn+=tree[u].lazy;
	tree[u].lazy=0;
	return ;
}

void BuildTree(int u)
{
	tree[u].lazy=0;
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=0;
		tree[u].mn=INF;
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	PushUp(u);
	return ;
}

void add(int u,int x)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=1;tree[u].mn=-1;
		return ;
	}
	PushDown(u);
	if (x<tree[u].m) add(u<<1,x);
	else add(u<<1|1,x);
	PushUp(u);
	return ;
}

void modify(int u,int l,int r,int v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].lazy+=v;
		tree[u].mn+=v;
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
	PushUp(u);
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);ans=0;pmx=pmn=0;hsh.clear();
		tree[1].p=1;tree[1].r=n+1;BuildTree(1);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&x);add(1,i);
			l=i;
			while (pmx&&mx[pmx].b<=x)
			{
				l=mx[pmx].a;v=x-mx[pmx].b;
				modify(1,mx[--pmx].a+1,l+1,v);
			}
			mx[++pmx]=L(i,x);l=i;
			while (pmn&&mn[pmn].b>=x)
			{
				l=mn[pmn].a;v=x-mn[pmn].b;
				modify(1,mn[--pmn].a+1,l+1,-v);
			}
			mn[++pmn]=L(i,x);
			if (hsh.find(x)!=hsh.end()) l=hsh[x]+1;
			else l=1;
			if (l<i) modify(1,l,i,-1);
			hsh[x]=i;
			ans+=tree[1].x;
		}
		printf("Case #%d: %lld\n",++cas,ans);
	}
	return 0;
}