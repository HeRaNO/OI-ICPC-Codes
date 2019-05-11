#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

const long long M=1e9+7;

struct SegmentTree
{
	int p,r,m;long long x,x2,mul,add;
};

SegmentTree tree[1<<19];
int n,T,a[MAXN],l,r,k,o;

inline void BuildTree(int u)
{
	tree[u].mul=1;tree[u].add=0;
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=a[tree[u].p];
		tree[u].x2=(1LL*a[tree[u].p]*a[tree[u].p])%M;
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=(tree[u<<1].x+tree[u<<1|1].x)%M;
	tree[u].x2=(tree[u<<1].x2+tree[u<<1|1].x2)%M;
	return ;
}

inline void PushDown(int u)
{
	if (tree[u].mul==1&&!tree[u].add) return;

	tree[u<<1].add=((tree[u<<1].add*tree[u].mul)%M+tree[u].add)%M;
	tree[u<<1|1].add=((tree[u<<1|1].add*tree[u].mul)%M+tree[u].add)%M;

	tree[u<<1].mul=(tree[u<<1].mul*tree[u].mul)%M;
	tree[u<<1|1].mul=(tree[u<<1|1].mul*tree[u].mul)%M;

	tree[u<<1].x=(tree[u<<1].x*tree[u].mul)%M;
	long long p=tree[u].mul*tree[u].mul%M;
	tree[u<<1].x2=tree[u<<1].x2*p%M;

	long long t=tree[u<<1].x*tree[u].add%M;
	t=t*2LL%M;p=tree[u<<1].r-tree[u<<1].p;
	p=p*tree[u].add%M;p=p*tree[u].add%M;
	(t+=p)%=M;
	(tree[u<<1].x2+=t)%=M;
	p=(tree[u<<1].r-tree[u<<1].p);p=p*tree[u].add%M;
	(tree[u<<1].x+=p)%=M;

	tree[u<<1|1].x=(tree[u<<1|1].x*tree[u].mul)%M;
	p=tree[u].mul*tree[u].mul%M;
	tree[u<<1|1].x2=(tree[u<<1|1].x2*p)%M;

	t=tree[u<<1|1].x*tree[u].add%M;
	t=t*2LL%M;p=tree[u<<1|1].r-tree[u<<1|1].p;
	p=p*tree[u].add%M;p=p*tree[u].add%M;
	(t+=p)%=M;
	(tree[u<<1|1].x2+=t)%=M;
	p=tree[u<<1|1].r-tree[u<<1|1].p;p=p*tree[u].add%M;
	(tree[u<<1|1].x+=p)%=M;

	tree[u].add=0;tree[u].mul=1;
	return ;
}

inline void add(int u,int l,int r,long long v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		long long t=tree[u].x*v%M;t=t*2LL%M;
		long long p=(v*v)%M;p=(p*(r-l))%M;(t+=p)%=M;
		(tree[u].x2+=t)%=M;
		(tree[u].add+=v)%=M;
		(tree[u].x+=1LL*(r-l)*v%M)%=M;
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) add(u<<1,l,r,v);
	else if (tree[u].m<=l) add(u<<1|1,l,r,v);
	else
	{
		add(u<<1,l,tree[u].m,v);
		add(u<<1|1,tree[u].m,r,v);
	}
	tree[u].x=(tree[u<<1].x+tree[u<<1|1].x)%M;
	tree[u].x2=(tree[u<<1].x2+tree[u<<1|1].x2)%M;
	return ;
}

inline void mul(int u,int l,int r,long long v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].add=(tree[u].add*v)%M;
		tree[u].mul=(tree[u].mul*v)%M;
		tree[u].x=(tree[u].x*v)%M;
		v=(v*v)%M;
		tree[u].x2=(tree[u].x2*v)%M;
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) mul(u<<1,l,r,v);
	else if (tree[u].m<=l) mul(u<<1|1,l,r,v);
	else
	{
		mul(u<<1,l,tree[u].m,v);
		mul(u<<1|1,tree[u].m,r,v);
	}
	tree[u].x=(tree[u<<1].x+tree[u<<1|1].x)%M;
	tree[u].x2=(tree[u<<1].x2+tree[u<<1|1].x2)%M;
	return ;
}

inline pair<long long,long long> query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return make_pair(tree[u].x,tree[u].x2);
	PushDown(u);
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else
	{
		pair<long long,long long> ll=query(u<<1,l,tree[u].m);
		pair<long long,long long> rr=query(u<<1|1,tree[u].m,r);
		return make_pair((ll.first+rr.first)%M,(ll.second+rr.second)%M);
	}
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
	read(n);read(T);
	for (int i=1;i<=n;i++) read(a[i]);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (T--)
	{
		read(o);read(l);read(r);
		if (o!=4) read(k);
		if (o==1) add(1,l,r+1,k);
		else if (o==2) mul(1,l,r+1,k);
		else if (o==3) mul(1,l,r+1,0),add(1,l,r+1,k);
		else
		{
			pair<long long,long long> t=query(1,l,r+1);
			long long ans=r-l+1;
			ans=(ans*t.second)%M;
			long long p=t.first*t.first%M;
			ans=(ans-p+M)%M;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
