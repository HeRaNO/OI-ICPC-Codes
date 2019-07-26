#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

const long long M=1e9+7;

struct Matrix
{
	long long m[3][3];
	Matrix(){
		memset(m,0,sizeof m);
		m[0][0]=m[1][1]=m[2][2]=1LL;
	}
	Matrix operator * (const Matrix &a)const{
		Matrix res;
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
			{
				res.m[i][j]=0LL;
				for (int k=0;k<3;k++)
					res.m[i][j]=(res.m[i][j]+(m[i][k]*a.m[k][j]%(M-1)))%(M-1);
			}
		return res;
	}
}A,B;

Matrix fpow(Matrix a,long long b)
{
	Matrix r;
	for (;b;b>>=1,a=a*a) if (b&1) r=r*a;
	return r;
}

long long qpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,a=(a*a)%M) if (b&1) r=(r*a)%M;
	return r;
}

long long n,c,f1,f2,f3,ans;

int main()
{
	scanf("%lld %lld %lld %lld %lld",&n,&f1,&f2,&f3,&c);
	if (n==4)
	{
		ans=c*c%M;ans=ans*f3%M;ans=ans*f2%M;ans=ans*f1%M;
		return printf("%lld\n",ans),0;
	}
	B.m[0][0]=1;B.m[0][1]=1;B.m[0][2]=0;
	B.m[1][0]=1;B.m[1][1]=0;B.m[1][2]=1;
	B.m[2][0]=1;B.m[2][1]=0;B.m[2][2]=0;
	A.m[0][0]=4;A.m[0][1]=2;A.m[0][2]=1;
	A.m[1][0]=6;A.m[1][1]=2;A.m[1][2]=1;
	A.m[2][0]=2;A.m[2][1]=1;A.m[2][2]=0;
	B=fpow(B,n-5)*A;
	//printf("%lld\n",B.m[0][1]);
	ans=qpow(f3*c%M*c%M*c%M,B.m[0][1])%M;
	B.m[0][0]=1;B.m[0][1]=1;B.m[0][2]=0;
	B.m[1][0]=1;B.m[1][1]=0;B.m[1][2]=1;
	B.m[2][0]=1;B.m[2][1]=0;B.m[2][2]=0;
	A.m[0][0]=3;A.m[0][1]=2;A.m[0][2]=1;
	A.m[1][0]=5;A.m[1][1]=1;A.m[1][2]=1;
	A.m[2][0]=2;A.m[2][1]=1;A.m[2][2]=0;
	B=fpow(B,n-5)*A;
	//printf("%lld\n",B.m[0][1]);
	ans*=qpow(f2*c%M*c%M,B.m[0][1]);ans%=M;
	B.m[0][0]=1;B.m[0][1]=1;B.m[0][2]=0;
	B.m[1][0]=1;B.m[1][1]=0;B.m[1][2]=1;
	B.m[2][0]=1;B.m[2][1]=0;B.m[2][2]=0;
	A.m[0][0]=2;A.m[0][1]=1;A.m[0][2]=1;
	A.m[1][0]=1;A.m[1][1]=1;A.m[1][2]=0;
	A.m[2][0]=1;A.m[2][1]=1;A.m[2][2]=0;
	B=fpow(B,n-5)*A;
	//printf("%lld\n",B.m[0][1]);
	ans*=qpow(f1*c%M,B.m[0][1]);ans%=M;
	printf("%lld\n",ans*qpow(qpow(c,n),M-2)%M);
	return 0;
}