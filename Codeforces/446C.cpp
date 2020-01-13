#include <bits/stdc++.h>
#define MAXP 550
#define MAXN 300005
using namespace std;

const int M=1e9+9;

struct Matrix
{
	int m[2][2];
	Matrix(){
		m[0][0]=m[1][1]=1;
		m[1][0]=m[0][1]=0;
	}
	Matrix operator * (const Matrix &a)const{
		Matrix res;
		res.m[0][0]=(1LL*m[0][0]*a.m[0][0]+1LL*m[0][1]*a.m[1][0])%M;
		res.m[0][1]=(1LL*m[0][0]*a.m[0][1]+1LL*m[0][1]*a.m[1][1])%M;
		res.m[1][0]=(1LL*m[1][0]*a.m[0][0]+1LL*m[1][1]*a.m[1][0])%M;
		res.m[1][1]=(1LL*m[1][0]*a.m[0][1]+1LL*m[1][1]*a.m[1][1])%M;
		return res;
	}
};

Matrix p[MAXP],q[MAXP];
int n,m,o,l,r,pt,a[MAXN];
int x[MAXN<<2],lazy[MAXN<<2][2];

inline void init()
{
	Matrix r;
	r.m[0][0]=1;r.m[0][1]=1;r.m[1][0]=1;r.m[1][1]=0;
	for (int i=1;i<MAXP;i++) p[i]=p[i-1]*r;
	r=p[MAXP-1]*r;
	for (int i=1;i<MAXP;i++) q[i]=q[i-1]*r;
	return ;
}

inline void BuildTree(int u,int l,int r)
{
	if (l+1==r){x[u]=a[l];return ;}
	int m=l+r>>1;
	BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u]=x[u<<1]+x[u<<1|1];if (x[u]>=M) x[u]-=M;
	return ;
}

inline Matrix getFib(int x){--x;return q[x/MAXP]*p[x%MAXP];}

inline int getFibAB(int a,int b,int k)
{
	if (k==1) return a;
	if (k==2) return b;
	Matrix r=getFib(k-1);
	a=1LL*a*r.m[0][1]%M;b=1LL*b*r.m[0][0]%M;
	a+=b;if (a>=M) a-=M;return a;
}

inline int sum(int a,int b,int l)
{
	if (l==1) return a;
	if (l==2) return a+b>=M?a+b-M:a+b;
	int r=getFibAB(a,b,l+2)-b;
	if (r<0) r+=M;return r;
}

inline void add(int u,int l,int r,int a,int b)
{
	lazy[u][0]+=a;if (lazy[u][0]>=M) lazy[u][0]-=M;
	lazy[u][1]+=b;if (lazy[u][1]>=M) lazy[u][1]-=M;
	x[u]+=sum(a,b,r-l);if (x[u]>=M) x[u]-=M;
	return ;
}

inline void PushDown(int u,int l,int r)
{
	if (!lazy[u][0]&&!lazy[u][1]) return ;
	int m=l+r>>1;
	add(u<<1,l,m,lazy[u][0],lazy[u][1]);
	int a=getFibAB(lazy[u][0],lazy[u][1],m-l+1);
	int b=getFibAB(lazy[u][0],lazy[u][1],m-l+2);
	add(u<<1|1,m,r,a,b);
	lazy[u][0]=lazy[u][1]=0;
	return ;
}

inline void modify(int u,int l,int r,int pt,int pl,int pr)
{
	if (l==pl&&r==pr)
	{
		Matrix fm=getFib(l+pt+1);
		add(u,l,r,fm.m[0][1],fm.m[0][0]);
		return ;
	}
	PushDown(u,pl,pr);int m=pl+pr>>1;
	if (r<=m) modify(u<<1,l,r,pt,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,pt,m,pr);
	else
	{
		modify(u<<1,l,m,pt,pl,m);
		modify(u<<1|1,m,r,pt,m,pr);
	}
	x[u]=x[u<<1]+x[u<<1|1];if (x[u]>=M) x[u]-=M;
	return ;
}

inline int query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return x[u];
	PushDown(u,pl,pr);int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	int res=query(u<<1,l,m,pl,m)+query(u<<1|1,m,r,m,pr);
	if (res>=M) return res-M;
	return res;
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
	init();read(n);read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	BuildTree(1,1,n+1);
	while (m--)
	{
		read(o);read(l);read(r);
		if (o==2) printf("%d\n",query(1,l,r+1,1,n+1));
		else
		{
			/*read(pt);*/pt=1;modify(1,l,r+1,pt-l,1,n+1);
		}
	}
	return 0;
}