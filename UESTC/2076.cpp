#include <cstdio>
using namespace std;

struct SegmentTree{int p,r,m;long long x;};

SegmentTree tree[1<<18];
int n,T,l,r,x;

void BuildTree(int x)
{
	if (tree[x].p+1==tree[x].r) return ;
	tree[x].m=tree[x].p+tree[x].r>>1;
	tree[x<<1].p=tree[x].p;tree[x<<1].r=tree[x].m;BuildTree(x<<1);
	tree[x<<1|1].p=tree[x].m;tree[x<<1|1].r=tree[x].r;BuildTree(x<<1|1);
	return ;
}

void modify(int u,int x,long long v,bool f)
{
	if (tree[u].p+1==tree[u].r)
	{
		if (f) tree[u].x+=v;
		else tree[u].x=v;
		return ;
	}
	if (x<tree[u].m) modify(u<<1,x,v,f);
	else modify(u<<1|1,x,v,f);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

long long query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
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
	read(n);read(T);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (T--)
	{
		read(x);read(l);read(r);
		if (x==1) modify(1,l,r,true);
		else if (x==2) modify(1,l,r,false);
		else printf("%lld\n",query(1,l,r+1));
	}
	return 0;
}