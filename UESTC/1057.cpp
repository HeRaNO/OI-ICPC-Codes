#include <cstdio>

struct SegmentTree
{
	int p,r,m;long long x,lazy;
};

SegmentTree tree[1<<18];
int n,T,a,b,c;

inline void read(int &x)
{
	x=0;bool f=false;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		int c;read(c);tree[u].x=c;return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

inline void PushDown(int u)
{
	if (!tree[u].lazy) return ;
	tree[u<<1].x+=(tree[u<<1].r-tree[u<<1].p)*tree[u].lazy;
	tree[u<<1].lazy+=tree[u].lazy;
	tree[u<<1|1].x+=(tree[u<<1|1].r-tree[u<<1|1].p)*tree[u].lazy;
	tree[u<<1|1].lazy+=tree[u].lazy;
	tree[u].lazy=0LL;return ;
}

long long dfs(int u,int l,int r,long long v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].x+=(r-l)*v;
		tree[u].lazy+=v;
		return tree[u].x;
	}
	PushDown(u);
	if (r<=tree[u].m)
	{
		long long x=dfs(u<<1,l,r,v);
		tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
		return x;
	}
	else if (tree[u].m<=l)
	{
		long long x=dfs(u<<1|1,l,r,v);
		tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
		return x;
	}
	else
	{
		long long x=dfs(u<<1,l,tree[u].m,v),y=dfs(u<<1|1,tree[u].m,r,v);
		tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
		return x+y;
	}
}

int main()
{
	read(n);tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	read(T);
	while (T--)
	{
		read(a);read(b);read(c);
		printf("%lld\n",dfs(1,a,b+1,c));
	}
	return 0;
}