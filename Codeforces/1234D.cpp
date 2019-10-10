#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct SegmentTree
{
	int p,r,m,x;
};

SegmentTree tree[1<<18];
int m,o,l,r;
char a[MAXN],p[3];

inline void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=(1<<(a[tree[u].p]-'a'));
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=tree[u<<1].x|tree[u<<1|1].x;
	return ;
}

inline void modify(int u,int x,int v)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=v;
		return ;
	}
	if (x<tree[u].m) modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	tree[u].x=tree[u<<1].x|tree[u<<1|1].x;
	return ;
}

inline int query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return query(u<<1,l,tree[u].m)|query(u<<1|1,tree[u].m,r);
}

int main()
{
	scanf("%s",a+1);
	tree[1].p=1;tree[1].r=strlen(a+1)+1;BuildTree(1);
	scanf("%d",&m);
	while (m--)
	{
		scanf("%d %d",&o,&l);
		if (o==1)
		{
			scanf("%s",p);
			modify(1,l,1<<(p[0]-'a'));
		}
		else
		{
			scanf("%d",&r);
			printf("%d\n",__builtin_popcount(query(1,l,r+1)));
		}
	}
	return 0;
}