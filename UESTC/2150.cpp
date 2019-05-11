#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct SegmentTree
{
	int p,r,m;long long x;
};

SegmentTree tree[1<<18];
int n,m,a[MAXN];
long long s[MAXN],ans=1LL<<63;

inline long long min(long long a,long long b){return a<b?a:b;}
inline long long max(long long a,long long b){return a>b?a:b;}

inline void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=s[tree[u].p];
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=min(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline long long query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return min(query(u<<1,l,tree[u].m),query(u<<1|1,tree[u].m,r));
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
	read(n);read(m);
	for (int i=1;i<=n;i++)
	{
		read(a[i]);
		s[i]=s[i-1]+a[i];
	}
	tree[1].p=0;tree[1].r=n+1;BuildTree(1);
	for (int i=1;i<=n;i++)
	{
		if (i<=m) ans=max(ans,s[i]-query(1,0,i));
		else ans=max(ans,s[i]-query(1,i-m,i));
	}
	printf("%lld\n",ans);
	return 0;
}
