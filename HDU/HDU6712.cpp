#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int M=8388607;
const int t1m1=427819008;
const int t2m2=587202560;
const int t3m3=981467137;
const int _fac7[]={1,1,2,6,3,1,6};
const int _fac17[]={1,1,2,6,7,1,6,8,13,15,14,1,12,3,8,1,16};
const int _invfac7[]={1,1,4,6,5,1,6};
const int _invfac17[]={1,1,9,3,5,1,3,15,4,8,11,1,10,6,15,1,16};
int t1,t2,p,q,n,m,ans,_fac[1<<23|1];
int x,y,v;

void exgcd(int a,int b,int &x,int &y)
{
	if (!b){x=1;y=0;return ;}
	exgcd(b,a%b,x,y);int t=x;x=y;y=t-(a/b)*y;
	return ;
}

inline int inv(int n)
{
	int x,y;exgcd(n,M+1,x,y);
	return (x+M+1)&M;
}

inline int add(int a,int b)
{
	int r=a+b;if (r>=998244352) r-=998244352;
	return r;
}

inline int fpow(int a,int b,int p)
{
	if (a==1||!b) return 1;
	int r=1;
	for (;b;a=(1LL*a*a)%p,b>>=1) if (b&1) r=(1LL*r*a)%p;
	return r;
}

inline int _fpow(int a,int b)
{
	if (a==1||!b) return 1;
	int r=1;
	for (;b;a=(1LL*a*a)&M,b>>=1) if (b&1) r=(1LL*r*a)&M;
	return r;
}

inline int LucasC7(int n,int m)
{
	if (n<m) return 0;
	if (n<7&&m<7) return _fac7[n]*_invfac7[m]*_invfac7[n-m]%7;
	return LucasC7(n/7,m/7)*LucasC7(n%7,m%7)%7;
}

inline int LucasC17(int n,int m)
{
	if (n<m) return 0;
	if (n<17&&m<17) return _fac17[n]*_invfac17[m]*_invfac17[n-m]%17;
	return LucasC17(n/17,m/17)*LucasC17(n%17,m%17)%17;
}

inline int fac(int x)
{
	if (!x) return 1;
	int ans=_fpow(_fac[M],x>>23);
	ans=(1LL*ans*_fac[x&M])&M;
	ans=(1LL*ans*fac(x>>1))&M;
	return ans;
}

inline int LucasC223(int n,int m)
{
	int res=0;
	for (int i=n;i;i>>=1) res+=(i>>1);
	for (int i=m;i;i>>=1) res-=(i>>1);
	for (int i=n-m;i;i>>=1) res-=(i>>1);
	if (res>=23) return 0;
	int fn=fac(n),fm=fac(m),fnm=fac(n-m);
	fn=(1LL*(1<<res)*fn)&M;
	fn=(1LL*inv(fm)*fn)&M;
	fn=(1LL*inv(fnm)*fn)&M;
	return fn;
}

inline int C(int n,int m)
{
	if (n<m) return 0;
	int a=LucasC7(n,m);
	int b=LucasC17(n,m);
	int c=LucasC223(n,m);
	int res=1LL*a*t1m1%998244352;
	res=add(res,1LL*b*t2m2%998244352);
	res=add(res,1LL*c*t3m3%998244352);
	return res;
}

int main()
{
	_fac[0]=1;
	for (int i=1;i<=M;i+=2)
	{
		_fac[i]=(1LL*_fac[i-1]*i)&M;
		_fac[i+1]=_fac[i];
	}
	while (~scanf("%d",&t1))
	{
		scanf("%d %d %d %d %d",&t2,&p,&q,&n,&m);ans=1;
		if (t1>=998244352) t1-=998244352;
		if (t2>=998244352) t2-=998244352;
		for (int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&x,&y,&v);
			if (x%p||y%q) continue;
			x/=p;y/=q;
			if (v>=998244353) v-=998244353;
			int e=fpow(t1,x,998244352);
			e=1LL*e*fpow(t2,y,998244352)%998244352;
			e=1LL*e*C(n,x)%998244352;
			e=1LL*e*C(n-x,y)%998244352;
			ans=1LL*ans*fpow(v,e,998244353)%998244353;
		}
		printf("%d\n",ans);
	}
	return 0;
}