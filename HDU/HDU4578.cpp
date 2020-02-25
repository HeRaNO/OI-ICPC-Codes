#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const int M=10007;

struct Matrix
{
	int m[4][4];
	Matrix(){
		memset(m,0,sizeof m);
	}
	Matrix(int v){
		int v2=v*v%M;int v3=v2*v%M;
		int _2v=v+v;if (_2v>=M) _2v-=M;
		int _3v=_2v+v;if (_3v>=M) _3v-=M;
		int _3v2=v2+v2;if (_3v2>=M) _3v2-=M;
		_3v2+=v2;if (_3v2>=M) _3v2-=M;
		m[0][0]=1;m[0][1]=v;m[0][2]=v2;m[0][3]=v3;
		m[1][0]=0;m[1][1]=1;m[1][2]=_2v;m[1][3]=_3v2;
		m[2][0]=0;m[2][1]=0;m[2][2]=1;m[2][3]=_3v;
		m[3][0]=0;m[3][1]=0;m[3][2]=0;m[3][3]=1;
	}
	Matrix operator + (const Matrix &a)const{
		Matrix res;
		for (int i=0;i<4;i++)
		{
			res.m[0][i]=m[0][i]+a.m[0][i];
			if (res.m[0][i]>=M) res.m[0][i]-=M;
		}
		return res;
	}
	Matrix operator * (const Matrix &a)const{
		Matrix res;
		for (int i=0;i<4;i++)
		{
			for (int j=0;j<=i;j++) res.m[0][i]+=m[0][j]*a.m[j][i];
			res.m[0][i]%=M;
		}
		return res;
	}
	void I()
	{
		for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
				m[i][j]=(i==j);
		return ;
	}
	void set()
	{
		memset(m,0,sizeof m);m[0][0]=1;
		return ;
	}
};

Matrix x[1<<18];
int lazy[1<<18][2];
int n,m,o,l,r,v;

inline void BuildTree(int u,int l,int r)
{
	lazy[u][0]=0;lazy[u][1]=1;
	if (l+1==r){x[u].set();return ;}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u]=x[u<<1]+x[u<<1|1];
	return ;
}

inline void add(int u,int v)
{
	Matrix p(v);x[u]=x[u]*v;lazy[u][0]+=v;
	if (lazy[u][0]>=M) lazy[u][0]-=M;
	return ;
}

inline void mul(int u,int v)
{
	for (int i=0,p=1;i<4;i++,(p*=v)%=M) (x[u].m[0][i]*=p)%=M;
	(lazy[u][1]*=v)%=M;(lazy[u][0]*=v)%=M;
	return ;
}

inline void PushDown(int u)
{
	if (lazy[u][1]!=1)
	{
		mul(u<<1,lazy[u][1]);mul(u<<1|1,lazy[u][1]);
		lazy[u][1]=1;
	}
	if (lazy[u][0])
	{
		add(u<<1,lazy[u][0]);add(u<<1|1,lazy[u][0]);
		lazy[u][0]=0;
	}
	return ;
}

inline void add(int u,int l,int r,int v,int pl,int pr)
{
	if (l==pl&&r==pr)
	{
		add(u,v);
		return ;
	}
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) add(u<<1,l,r,v,pl,m);
	else if (m<=l) add(u<<1|1,l,r,v,m,pr);
	else
	{
		add(u<<1,l,m,v,pl,m);
		add(u<<1|1,m,r,v,m,pr);
	}
	x[u]=x[u<<1]+x[u<<1|1];
	return ;
}

inline void mul(int u,int l,int r,int v,int pl,int pr)
{
	if (l==pl&&r==pr)
	{
		mul(u,v);
		return ;
	}
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) mul(u<<1,l,r,v,pl,m);
	else if (m<=l) mul(u<<1|1,l,r,v,m,pr);
	else
	{
		mul(u<<1,l,m,v,pl,m);
		mul(u<<1|1,m,r,v,m,pr);
	}
	x[u]=x[u<<1]+x[u<<1|1];
	return ;
}

inline Matrix query(int u,int l,int r,int pl,int pr)
{
	if (pl==l&&pr==r) return x[u];
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return query(u<<1,l,m,pl,m)+query(u<<1|1,m,r,m,pr);
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
	while (true)
	{
		read(n);read(m);if (!n&&!m) break;
		BuildTree(1,1,n+1);
		while (m--)
		{
			read(o);read(l);read(r);read(v);
			if (o==1) add(1,l,r+1,v,1,n+1);
			else if (o==2) mul(1,l,r+1,v,1,n+1);
			else if (o==3) mul(1,l,r+1,0,1,n+1),add(1,l,r+1,v,1,n+1);
			else printf("%d\n",query(1,l,r+1,1,n+1).m[0][v]);
		}
	}
	return 0;
}