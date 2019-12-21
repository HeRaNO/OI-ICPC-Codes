#include <bits/stdc++.h>
#define MAXN 100005
#define MAXP 32000
using namespace std;

const long long M=1e9+7;

struct Matrix
{
	long long m[2][2];
	Matrix(){
		m[0][0]=m[1][1]=1;
		m[1][0]=m[0][1]=0;
	}
	Matrix operator * (const Matrix &a)const{
		Matrix res;
		res.m[0][0]=(m[0][0]*a.m[0][0]%M+m[0][1]*a.m[1][0]%M)%M;
		res.m[0][1]=(m[0][0]*a.m[0][1]%M+m[0][1]*a.m[1][1]%M)%M;
		res.m[1][0]=(m[1][0]*a.m[0][0]%M+m[1][1]*a.m[1][0]%M)%M;
		res.m[1][1]=(m[1][0]*a.m[0][1]%M+m[1][1]*a.m[1][1]%M)%M;
		return res;
	}
	Matrix operator + (const Matrix &a)const{
		Matrix res;
		res.m[0][0]=(m[0][0]+a.m[0][0])%M;
		res.m[0][1]=(m[0][1]+a.m[0][1])%M;
		res.m[1][0]=(m[1][0]+a.m[1][0])%M;
		res.m[1][1]=(m[1][1]+a.m[1][1])%M;
		return res;
	}
	bool empty() {
		return m[0][0]==1&&m[1][1]==1&&m[1][0]==0&&m[0][1]==0;
	}
};

struct SegmentTree
{
	int p,r,m;Matrix lazy,x;
};

SegmentTree tree[1<<19];
int n,m,a[MAXN],o,l,r,x;
Matrix p[MAXP],q[MAXP];

inline Matrix getFib(int x)
{
	--x;
	return q[x/MAXP]*p[x%MAXP];
}

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=getFib(a[tree[u].p]);
		tree[u].x.m[1][0]=tree[u].x.m[1][1]=0;
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

inline void PushDown(int u)
{
	if (tree[u].lazy.empty()) return ;
	tree[u<<1].lazy=tree[u<<1].lazy*tree[u].lazy;
	tree[u<<1].x=tree[u<<1].x*tree[u].lazy;
	tree[u<<1|1].lazy=tree[u<<1|1].lazy*tree[u].lazy;
	tree[u<<1|1].x=tree[u<<1|1].x*tree[u].lazy;
	tree[u].lazy.m[0][0]=tree[u].lazy.m[1][1]=1;
	tree[u].lazy.m[0][1]=tree[u].lazy.m[1][0]=0;
	return ;
}

inline void modify(int u,int l,int r,int x)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		Matrix p=getFib(x+1);
		tree[u].x=tree[u].x*p;
		tree[u].lazy=tree[u].lazy*p;
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) modify(u<<1,l,r,x);
	else if (tree[u].m<=l) modify(u<<1|1,l,r,x);
	else
	{
		modify(u<<1,l,tree[u].m,x);
		modify(u<<1|1,tree[u].m,r,x);
	}
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

inline long long query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x.m[0][0];
	PushDown(u);
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return (query(u<<1,l,tree[u].m)+query(u<<1|1,tree[u].m,r))%M;
}

inline void init()
{
	Matrix r;
	r.m[0][0]=1;r.m[0][1]=1;r.m[1][0]=1;r.m[1][1]=0;
	for (int i=1;i<MAXP;i++) p[i]=p[i-1]*r;
	r=p[MAXP-1]*r;
	for (int i=1;i<MAXP;i++) q[i]=q[i-1]*r;
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
	scanf("%d %d",&n,&m);init();
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (m--)
	{
		scanf("%d %d %d",&o,&l,&r);
		if (o==1) scanf("%d",&x),modify(1,l,r+1,x);
		else printf("%lld\n",query(1,l,r+1));
	}
	return 0;
}