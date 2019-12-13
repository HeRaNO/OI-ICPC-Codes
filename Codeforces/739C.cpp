#include <bits/stdc++.h>
#define MAXN 300005
using namespace std;

inline int sgn(long long a)
{
	if (a<0) return -1;
	return a==0?0:1;
}

struct C
{
	long long lc,rc;
	int pre,suf,ans,len;
	C(){}
	C(long long _x) {
		lc=_x;rc=_x;len=1;
		if (_x) pre=suf=ans=1;
		else pre=suf=ans=0;
	}
	C operator + (const C &a)const{
		C res;res.len=len+a.len;
		res.lc=lc;res.rc=a.rc;res.ans=max(ans,a.ans);
		res.pre=pre;res.suf=a.suf;
		if (rc&&a.lc&&sgn(rc)>=sgn(a.lc))
		{
			res.ans=max(res.ans,suf+a.pre);
			if (ans==len) res.pre+=a.pre;
			if (a.ans==a.len) res.suf+=suf;
		}
		return res;
	}
};

struct SegmentTree
{
	int p,r,m;C x;
};

SegmentTree tree[1<<20];
int n,T,a[MAXN],d[MAXN],l,r,v;

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=C(d[tree[u].p]);
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

void modify(int u,int x,int v)
{
	if (tree[u].p+1==tree[u].r)
	{
		long long p=tree[u].x.lc+v;
		tree[u].x=C(p);
		return ;
	}
	if (x<tree[u].m) modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) d[i]=a[i+1]-a[i];
	if (n>1)
	{
		tree[1].p=1;tree[1].r=n;BuildTree(1);
	}
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&l,&r,&v);
		if (l>1) modify(1,l-1,v);
		if (r<n) modify(1,r,-v);
		printf("%d\n",tree[1].x.ans+1);
	}
	return 0;
}