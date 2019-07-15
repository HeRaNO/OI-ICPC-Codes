#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;

struct SegmentTree
{
	int p,r,m,x;
};

SegmentTree tree[1<<20];
int n,q,a[MAXN],cnt,o,l,r,x;

inline int gcd(int a,int b){return !b?a:gcd(b,a%b);}

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r){tree[u].x=a[tree[u].p];return ;}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=gcd(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline void modify(int u,int x,int v)
{
	if (tree[u].p+1==tree[u].r){tree[u].x=v;return ;}
	if (x<tree[u].m) modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	tree[u].x=gcd(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline void query(int u,int l,int r,int x)
{
	if (cnt>1) return ;
	if (tree[u].p+1==tree[u].r){++cnt;return ;}
	if (l<=tree[u].m&&tree[u<<1].x%x!=0) query(u<<1,l,r,x);
	if (r>tree[u].m&&tree[u<<1|1].x%x!=0) query(u<<1|1,l,r,x);
	return ;
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
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	read(q);
	while (q--)
	{
		read(o);
		if (o==1)
		{
			read(l);read(r);read(x);cnt=0;
			query(1,l,r+1,x);
			if (cnt>1) puts("NO");
			else puts("YES");
		}
		else
		{
			read(l);read(x);
			modify(1,l,x);
		}
	}
	return 0;
}
