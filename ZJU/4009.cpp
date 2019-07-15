#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

const long long M=99971LL;

struct SegmentTree
{
	int p,r,m,cnt;
	long long x[48];
};

SegmentTree tree[1<<18];
int n,T,q,a[MAXN],l,r,o;

void BuildTree(int x)
{
	tree[x].cnt=0;
	if (tree[x].p+1==tree[x].r)
	{
		tree[x].x[0]=a[tree[x].p]%M;
		long long mm=tree[x].x[0];
		for (int i=1;i<48;i++)
		{
			mm=mm*mm%M*mm%M;
			tree[x].x[i]=mm;
		}
		return ;
	}
	tree[x].m=tree[x].p+tree[x].r>>1;
	tree[x<<1].p=tree[x].p;tree[x<<1].r=tree[x].m;BuildTree(x<<1);
	tree[x<<1|1].p=tree[x].m;tree[x<<1|1].r=tree[x].r;BuildTree(x<<1|1);
	for (int i=0;i<48;i++)
		tree[x].x[i]=(tree[x<<1].x[i]+tree[x<<1|1].x[i])%M;
	return ;
}

void modify(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		++tree[u].cnt;
		return ;
	}
	if (r<=tree[u].m) modify(u<<1,l,r);
	else if (tree[u].m<=l) modify(u<<1|1,l,r);
	else
	{
		modify(u<<1,l,tree[u].m);
		modify(u<<1|1,tree[u].m,r);
	}
	for (int i=0;i<48;i++)
		tree[u].x[i]=(tree[u<<1].x[(tree[u<<1].cnt+i)%48]+tree[u<<1|1].x[(tree[u<<1|1].cnt+i)%48])%M;
	return ;
}

long long query(int u,int l,int r,int cnt)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x[(cnt+tree[u].cnt)%48];
	if (r<=tree[u].m) return query(u<<1,l,r,cnt+tree[u].cnt);
	else if (tree[u].m<=l) return query(u<<1|1,l,r,cnt+tree[u].cnt);
	else return (query(u<<1,l,tree[u].m,cnt+tree[u].cnt)+query(u<<1|1,tree[u].m,r,cnt+tree[u].cnt))%M;
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
	read(T);
	while (T--)
	{
		read(n);read(q);for (int i=1;i<=n;i++) read(a[i]);
		tree[1].p=1;tree[1].r=n+1;BuildTree(1);
		while (q--)
		{
			read(o);read(l);read(r);
			if (o==1) modify(1,l,r+1);
			else printf("%lld\n",query(1,l,r+1,0));
		}
	}
	return 0;
}