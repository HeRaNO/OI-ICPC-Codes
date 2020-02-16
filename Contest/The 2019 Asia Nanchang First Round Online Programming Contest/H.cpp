#include <bits/stdc++.h>
#define MAXP 31595
using namespace std;

const long long M=998244353;

struct matrix
{
	long long m[2][2];
	matrix(){
		m[0][0]=m[1][1]=1;
		m[1][0]=m[0][1]=0;
	}
	matrix operator * (const matrix &a)const{
		matrix res;
		res.m[0][0]=(m[0][0]*a.m[0][0]%M+m[0][1]*a.m[1][0]%M)%M;
		res.m[0][1]=(m[0][0]*a.m[0][1]%M+m[0][1]*a.m[1][1]%M)%M;
		res.m[1][0]=(m[1][0]*a.m[0][0]%M+m[1][1]*a.m[1][0]%M)%M;
		res.m[1][1]=(m[1][0]*a.m[0][1]%M+m[1][1]*a.m[1][1]%M)%M;
		return res;
	}
};

matrix p[MAXP],r,q[MAXP];
int T;
long long x,ans;

inline long long f(long long x)
{
	if (x<=1) return x;matrix r,a;
	--x;x%=(M-1);
	r.m[0][0]=1;r.m[1][1]=0;
	a=q[x/MAXP]*p[x%MAXP];r=r*a;
	return r.m[0][0];
}

int main()
{
	scanf("%d %lld",&T,&x);
	r.m[0][0]=3;r.m[0][1]=2;r.m[1][0]=1;r.m[1][1]=0;
	for (int i=1;i<MAXP;i++) p[i]=p[i-1]*r;
	r=p[MAXP-1]*r;
	for (int i=1;i<MAXP;i++) q[i]=q[i-1]*r;
	while (T--)
	{
		long long res=f(x);
		if (!ans) ans=res;
		else ans^=res;
		x=x^(res*res);
	}
	printf("%lld\n",ans);
	return 0;
}