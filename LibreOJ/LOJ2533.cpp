#include <bits/stdc++.h>
#define MAXN 200
using namespace std;

long long M;

inline void add(long long &a,long long b)
{
	a+=b;if (a>=M) a-=M;return ;
}

inline long long add2(long long a,long long b)
{
	if (a+b>=M) return a+b-M;
	return a+b;
}

struct Matrix
{
	int n,m;long long ma[MAXN][MAXN];
	Matrix(){}
	Matrix operator * (const Matrix &a)const{
		Matrix res;res.n=n;res.m=a.m;
		for (int i=0;i<n;i++)
			for (int j=0;j<a.m;j++)
			{
				res.ma[i][j]=0;
				for (int k=0;k<m;k++) res.ma[i][j]+=ma[i][k]*a.ma[k][j];
				res.ma[i][j]%=M;
			}
		return res;
	}
};

int n,m,a,b;
Matrix r,bs;
long long ans,pn=1,C[MAXN][MAXN];

int main()
{
	scanf("%d %d %d %lld",&n,&a,&b,&M);m=a+b+1;C[0][0]=1;
	for (int i=1;i<=m;i++)
	{
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=add2(C[i-1][j],C[i-1][j-1]);
	}
	bs.n=bs.m=m<<1;r.n=1;r.m=m<<1;r.ma[0][0]=1;
	for (int i=0;i<m;i++)
	{
		bs.ma[i][i]=bs.ma[i+m][i]=1;
		for (int j=i;j<m;j++) bs.ma[i][j+m]=C[j][i];
	}
	for (int p=n;p;p>>=1,bs=bs*bs) if (p&1) r=r*bs;
	for (int i=0;i<=a;i++)
	{
		long long x=C[a][i];
		(x*=pn)%=M;(pn*=n)%=M;
		(x*=add2(r.ma[0][a+b-i],r.ma[0][a+b-i+m]))%=M;
		if ((a-i)&1) x=M-x;
		add(ans,x);
	}
	printf("%lld\n",ans);
	return 0;
}