#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

const int M=998244353;
int n,m,inv[MAXN],fac[MAXN],invfac[MAXN];

inline int C(int n,int m)
{
	return 1LL*fac[n]*invfac[m]%M*invfac[n-m]%M;
}

inline int fpow(int a,int b)
{
	int r=1;
	for (;b;b>>=1,a=(1LL*a*a)%M) if (b&1) r=1LL*r*a%M;
	return r;
}

int main()
{
	scanf("%d %d",&m,&n);inv[1]=1;invfac[0]=fac[0]=1;
	if (m==2) return puts("0"),0;
	for (int i=2;i<=n;i++) inv[i]=1LL*(M-M/i)*inv[M%i]%M;
	for (int i=1;i<=n;i++)
	{
		fac[i]=1LL*fac[i-1]*i%M;
		invfac[i]=1LL*invfac[i-1]*inv[i]%M;
	}
	printf("%d\n",1LL*C(n,m-1)*(m-2)%M*fpow(2,m-3)%M);
	return 0;
}