#include <cstdio>
#include <algorithm>
#define MAXN 50010
using namespace std;

struct SegmentTree
{
	int p,r,m,x;
};

SegmentTree tree[1<<17];
int n,m,T,u,v,uu,vv,a[MAXN],d[MAXN],g[MAXN],y[MAXN];
bool m1,m2;

inline int max(int a,int b){return a>b?a:b;}

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r){tree[u].x=a[tree[u].p];return ;}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=max(tree[u<<1].x,tree[u<<1|1].x);return ;
}

int query(int u,int l,int r)
{
	if (l==r) return 0;
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return max(query(u<<1,l,tree[u].m),query(u<<1|1,tree[u].m,r));
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);
	for (int i=1;i<=n;i++) read(y[i]),read(a[i]);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	for (int i=2;i<=n;i++) d[i]=y[i]-y[i-1];
	for (int i=1;i<=n;i++){if (d[i]!=1) ++m;g[i]=m;}
	read(T);
	while (T--)
	{
		read(u);read(v);
		uu=lower_bound(y+1,y+n+1,u)-y;m1=(u==y[uu]);
		vv=lower_bound(y+1,y+n+1,v)-y;m2=(v==y[vv]);
		if (!m1&&!m2){puts("maybe");continue;}
		if (!m1) m=query(1,uu,vv);
		else m=query(1,uu+1,vv);
		if (!m2)
		{
			if (m>=a[uu]) puts("false");
			else puts("maybe");
			continue;
		}
		if (a[vv]<=m){puts("false");continue;}
		if (!m1){puts("maybe");continue;}
		if (a[vv]>a[uu]){puts("false");continue;}
		if (g[vv]!=g[uu]){puts("maybe");continue;}
		puts("true");
	}
	return 0;
}
