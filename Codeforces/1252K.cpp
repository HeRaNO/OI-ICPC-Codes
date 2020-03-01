#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const long long M=1e9+7;

struct Matrix
{
	long long m[2][2];
	Matrix(){m[0][0]=m[0][1]=m[1][0]=m[1][1]=0;}
	Matrix(int p,int q){
		m[0][0]=p;m[0][1]=q;
		m[1][0]=m[1][1]=0;
	}
	Matrix operator * (const Matrix &a)const{
		Matrix res;
		res.m[0][0]=(m[0][0]*a.m[0][0]+m[0][1]*a.m[1][0])%M;
		res.m[0][1]=(m[0][0]*a.m[0][1]+m[0][1]*a.m[1][1])%M;
		res.m[1][0]=(m[1][0]*a.m[0][0]+m[1][1]*a.m[1][0])%M;
		res.m[1][1]=(m[1][0]*a.m[0][1]+m[1][1]*a.m[1][1])%M;
		return res;
	}
}a,b,x[1<<18][2];

bool lazy[1<<18];
int n,m,o,l,r,p,q;
char s[MAXN];

inline void BuildTree(int u,int l,int r)
{
	if (l+1==r)
	{
		if (s[l]=='A')
		{
			x[u][0]=a;x[u][1]=b;
		}
		else
		{
			x[u][0]=b;x[u][1]=a;
		}
		return ;
	}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u][0]=x[u<<1][0]*x[u<<1|1][0];
	x[u][1]=x[u<<1][1]*x[u<<1|1][1];
	return ;
}

inline void toggle(int u)
{
	lazy[u]^=1;swap(x[u][0],x[u][1]);
	return ;
}

inline void PushDown(int u)
{
	if (!lazy[u]) return ;
	toggle(u<<1);toggle(u<<1|1);
	lazy[u]=false;
	return ;
}

inline void modify(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr)
	{
		toggle(u);
		return ;
	}
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) modify(u<<1,l,r,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,m,pr);
	else
	{
		modify(u<<1,l,m,pl,m);
		modify(u<<1|1,m,r,m,pr);
	}
	x[u][0]=x[u<<1][0]*x[u<<1|1][0];
	x[u][1]=x[u<<1][1]*x[u<<1|1][1];
	return ;
}

inline Matrix query(int u,int l,int r,int pl,int pr)
{
	if (pl==l&&pr==r) return x[u][0];
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return query(u<<1,l,m,pl,m)*query(u<<1|1,m,r,m,pr);
}

int main()
{
	scanf("%d %d",&n,&m);
	a.m[0][0]=a.m[1][0]=a.m[1][1]=1;
	b.m[0][0]=b.m[0][1]=b.m[1][1]=1;
	scanf("%s",s+1);BuildTree(1,1,n+1);
	while (m--)
	{
		scanf("%d %d %d",&o,&l,&r);
		if (o==1) modify(1,l,r+1,1,n+1);
		else
		{
			scanf("%d %d",&p,&q);
			Matrix k(p,q);
			k=k*query(1,l,r+1,1,n+1);
			printf("%lld %lld\n",k.m[0][0],k.m[0][1]);
		}
	}
	return 0;
}