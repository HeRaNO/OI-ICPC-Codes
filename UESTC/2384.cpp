#include <bits/stdc++.h>
#define MAXP 31630
#define MAXN 200005
using namespace std;

// Magic number part
const int M=1e9+9;        // modular
const int a=691504013;    // a=\frac{1+\sqrt 5}{2}
const int a2=691504014;   // a^2=\frac{3+\sqrt 5}{2}
const int _2=1e9+7;       // -2=M-2
const int b=308495997;    // b=\frac{1-\sqrt 5}{2}
const int b2=308495998;   // b^2=\frac{3-\sqrt 5}{2}
const int _ia2=M-b;       // \frac{1}{a^2-1}=-\frac{1}{b}
const int _ib2=M-a;       // \frac{1}{b^2-1}=-\frac{1}{a}
const int _i5=200000002;  // \frac{1}{5}

int qA[MAXP],qB[MAXP],pA[MAXP],pB[MAXP];
int n,m,o,l,r,pt,w[MAXN],inv[MAXN];
int x[1<<19],lazy[1<<19][3];
// 0: a2^n 1: 2*(-1)^(n-1) 2: b2^n

// O(\sqrt p)-O(1)
inline void init()
{
	inv[1]=1;
	for (int i=2;i<=n;i++) inv[i]=1LL*(M-M/i)*inv[M%i]%M;
	pA[0]=pB[0]=1;qA[0]=qB[0]=1;
	for (int i=1;i<MAXP;i++)
	{
		pA[i]=1LL*pA[i-1]*a2%M;
		pB[i]=1LL*pB[i-1]*b2%M;
	}
	int rA=1LL*pA[MAXP-1]*a2%M,rB=1LL*pB[MAXP-1]*b2%M;
	for (int i=1;i<MAXP;i++)
	{
		qA[i]=1LL*qA[i-1]*rA%M;
		qB[i]=1LL*qB[i-1]*rB%M;
	}
	return ;
}

inline void fadd(int &x,int y){x+=y;if (x>=M) x-=M;return ;}
inline int fpowA(int x){return 1LL*qA[x/MAXP]*pA[x%MAXP]%M;}
inline int fpowB(int x){return 1LL*qB[x/MAXP]*pB[x%MAXP]%M;}

inline void BuildTree(int u,int l,int r)
{
	if (l+1==r){x[u]=w[l];return ;}
	int m=l+r>>1;
	BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	fadd(x[u],x[u<<1]+x[u<<1|1]);
	return ;
}

inline void add(int u,int l,int r,int a,int y,int b)
{
	fadd(lazy[u][0],a);fadd(lazy[u][1],y);fadd(lazy[u][2],b);
	int t=fpowA(r-l);fadd(t,M-1);t=1LL*t*_ia2%M;t=1LL*t*a%M;fadd(x[u],1LL*t*_i5%M);
	if ((r-l)&1) fadd(x[u],1LL*y*_i5%M);
	t=fpowB(r-l);fadd(t,M-1);t=1LL*t*_ib2%M;t=1LL*t*b%M;fadd(x[u],1LL*t*_i5%M);
	return ;
}

inline void PushDown(int u,int l,int r)
{
	if (!lazy[u][0]&&!lazy[u][1]&&!lazy[u][2]) return ;
	int m=l+r>>1;
	add(u<<1,l,m,lazy[u][0],lazy[u][1],lazy[u][2]);
	int a=1LL*lazy[u][0]*fpowA(m-l)%M;
	int b=1LL*lazy[u][2]*fpowB(m-l)%M;
	int y=(m-l-1)&1?lazy[u][1]:M-lazy[u][1];
	add(u<<1|1,m,r,a,y,b);
	lazy[u][0]=lazy[u][1]=lazy[u][2]=0;
	return ;
}

inline void modify(int u,int l,int r,int pt,int pl,int pr)
{
	if (l==pl&&r==pr)
	{
		int a=fpowA(pt+l),b=fpowB(pt+l);
		int y=(pt+l)&1?2:M-2;
		add(u,l,r,a,y,b);
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
	x[u]=0;fadd(x[u],x[u<<1]+x[u<<1|1]);
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
	read(n);read(m);init();
	for (int i=1;i<=n;i++) read(w[i]);
	BuildTree(1,1,n+1);
	while (m--)
	{
		read(o);read(l);read(r);
		if (o==1) printf("%lld\n",1LL*query(1,l,r+1,1,n+1)*inv[r-l+1]%M);
		else
		{
			read(pt);
			modify(1,l,r+1,pt-l,1,n+1);
		}
	}
	return 0;
}
