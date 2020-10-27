#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

const int b=20201101;
const int M1=998244353;
const int M2=1000000007;

long long _1[MAXN],_2[MAXN],__1[MAXN],__2[MAXN];
long long x[1<<21][3],lazy[1<<21];
int n,q,a[MAXN];

inline int fadd1(long long x,int y){x+=y;if (x>=M1) x-=M1;return x;}
inline int fadd2(long long x,int y){x+=y;if (x>=M2) x-=M2;return x;}

inline void init(int n)
{
	_1[0]=_2[0]=1;
	for (int i=1;i<=n;i++)
	{
		_1[i]=_1[i-1]*b%M1;
		_2[i]=_2[i-1]*b%M2;
	}
	for (int i=1;i<=n;i++)
	{
		__1[i]=fadd1(__1[i-1],_1[i]);
		__2[i]=fadd2(__2[i-1],_2[i]);
	}
	return ;
}

inline long long fpow(long long a,long long b,int p)
{
	long long r=1;
	for (;b;b>>=1,(a*=a)%=p) if (b&1) (r*=a)%=p;
	return r;
}

inline void BuildTree(int u,int l,int r)
{
	if (l+1==r)
	{
		x[u][0]=_1[l]*a[l]%M1;
		x[u][1]=_2[l]*a[l]%M2;
		x[u][2]=a[l];
		return ;
	}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u][0]=fadd1(x[u<<1][0],x[u<<1|1][0]);
	x[u][1]=fadd2(x[u<<1][1],x[u<<1|1][1]);
	x[u][2]=max(x[u<<1][2],x[u<<1|1][2]);
	return ;
}

inline void PushDown(int u,int l,int r)
{
	if (!lazy[u]) return ;
	int m=l+r>>1;
	x[u<<1][2]+=lazy[u];x[u<<1|1][2]+=lazy[u];
	x[u<<1][0]=fadd1(x[u<<1][0],lazy[u]*fadd1(__1[m-1],M1-__1[l-1])%M1);
	x[u<<1][1]=fadd2(x[u<<1][1],lazy[u]*fadd2(__2[m-1],M2-__2[l-1])%M2);
	x[u<<1|1][0]=fadd1(x[u<<1|1][0],lazy[u]*fadd1(__1[r-1],M1-__1[m-1])%M1);
	x[u<<1|1][1]=fadd2(x[u<<1|1][1],lazy[u]*fadd2(__2[r-1],M2-__2[m-1])%M2);
	lazy[u<<1]+=lazy[u];lazy[u<<1|1]+=lazy[u];
	lazy[u]=0;return ;
}

inline void modify(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr)
	{
		++x[u][2];++lazy[u];
		x[u][0]=fadd1(x[u][0],fadd1(__1[r-1],M1-__1[l-1]));
		x[u][1]=fadd2(x[u][1],fadd2(__2[r-1],M2-__2[l-1]));
		return ;
	}
	int m=pl+pr>>1;PushDown(u,pl,pr);
	if (r<=m) modify(u<<1,l,r,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,m,pr);
	else
	{
		modify(u<<1,l,m,pl,m);
		modify(u<<1|1,m,r,m,pr);
	}
	x[u][0]=fadd1(x[u<<1][0],x[u<<1|1][0]);
	x[u][1]=fadd2(x[u<<1][1],x[u<<1|1][1]);
	x[u][2]=max(x[u<<1][2],x[u<<1|1][2]);
	return ;
}

void down(int u,int pl,int pr)
{
	if (x[u][2]<=65535) return ;
	if (pl+1==pr)
	{
		x[u][2]%=65536;
		x[u][0]=_1[pl]*x[u][2]%M1;
		x[u][1]=_2[pl]*x[u][2]%M2;
		return ;
	}
	int m=pl+pr>>1;PushDown(u,pl,pr);
	down(u<<1,pl,m);down(u<<1|1,m,pr);
	x[u][0]=fadd1(x[u<<1][0],x[u<<1|1][0]);
	x[u][1]=fadd2(x[u<<1][1],x[u<<1|1][1]);
	x[u][2]=max(x[u<<1][2],x[u<<1|1][2]);
	return ;
}

pair<long long,long long> query(int u,int l,int r,int pl,int pr)
{
	if (pl==l&&pr==r) return {x[u][0],x[u][1]};
	int m=pl+pr>>1;PushDown(u,pl,pr);
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else
	{
		auto x=query(u<<1,l,m,pl,m);
		auto y=query(u<<1|1,m,r,m,pr);
		return {fadd1(x.first,y.first),fadd2(x.second,y.second)};
	}
}

int main()
{
	init(500000);
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	BuildTree(1,1,n+1);
	while (q--)
	{
		int o,x,y;
		scanf("%d %d %d",&o,&x,&y);
		if (o==1)
		{
			modify(1,x,y+1,1,n+1);
			down(1,1,n+1);
		}
		else
		{
			int l;
			scanf("%d",&l);
			auto xx=query(1,x,x+l,1,n+1);
			auto yy=query(1,y,y+l,1,n+1);
			xx.first=xx.first*fpow(_1[x],M1-2,M1)%M1;
			xx.second=xx.second*fpow(_2[x],M2-2,M2)%M2;
			yy.first=yy.first*fpow(_1[y],M1-2,M1)%M1;
			yy.second=yy.second*fpow(_2[y],M2-2,M2)%M2;
			//printf("%lld %lld\n",xx.first,xx.second);
			//printf("%lld %lld\n",yy.first,yy.second);
			puts(xx==yy?"yes":"no");
		}
	}
	return 0;
}