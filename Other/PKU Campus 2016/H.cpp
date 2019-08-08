#include <bits/stdc++.h>
#define MAXN 20010
using namespace std;

const long long M=1e9+7;

struct Matrix
{
	long long m[2][2];
	Matrix(){m[0][0]=m[1][1]=1LL;m[0][1]=m[1][0]=0LL;}
	Matrix(long long _1,long long _2,long long _3,long long _4){
		m[0][0]=_1;m[0][1]=_2;m[1][0]=_3;m[1][1]=_4;
		return ;
	}
	Matrix operator * (const Matrix &a)const{
		Matrix res;
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
			{
				res.m[i][j]=0;
				for (int k=0;k<2;k++) (res.m[i][j]+=m[i][k]*a.m[k][j]%M)%=M;
			}
		return res;
	}
};

Matrix p;
int T,m,u,d,l,r;
long long n,x,y,a[MAXN],b[MAXN];

inline Matrix fpow(Matrix a,long long b)
{
	Matrix r=Matrix(1,0,0,1);
	for (;b;b>>=1,a=a*a) if (b&1) r=r*a;
	return r;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld %d %lld %lld",&n,&m,&x,&y);
		x=(x%M+M)%M;y=(y%M+M)%M;
		for (int i=1;i<=m;i++)
		{
			scanf("%d %d %d %d",&u,&d,&l,&r);
			a[i]=(1+u+d+l+r)%M;
			b[i]=(u-d-l+r+M)%M;
		}
		p=Matrix(1,0,0,1);
		for (int i=1;i<=m;i++) p=p*Matrix(a[i],b[i],0,a[i]);
		p=fpow(p,n/m);
		for (int i=1,o=n%m;i<=o;i++) p=p*Matrix(a[i],b[i],0,a[i]);
		printf("%lld\n",(p.m[0][1]+p.m[0][0]*(x+y)%M)%M);
	}
	return 0;
}