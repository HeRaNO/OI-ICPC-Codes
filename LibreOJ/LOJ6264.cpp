#include <bits/stdc++.h>
using namespace std;

const long long M=1e9+7;
const long long _5=400000003;

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

long long n,ans;

inline long long L(long long n)
{
	Matrix r,a,b;n-=2;
	a.m[0][0]=1;a.m[0][1]=1;a.m[1][0]=1;a.m[1][1]=0;
	for (;n;n>>=1,a=a*a) if (n&1) r=r*a;
	b.m[0][0]=3;b.m[0][1]=1;b.m[1][0]=1;b.m[1][1]=0;
	return (r*b).m[0][0];
}

inline long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,(a*=a)%=M) if (b&1) (r*=a)%=M;
	return r;
}

int main()
{
	scanf("%lld",&n);ans=L(n<<1|1);
	if (n&1) (++ans)%=M;
	else ans=(ans-1+M)%M;
	printf("%lld\n",ans*_5%M);
	return 0;
}