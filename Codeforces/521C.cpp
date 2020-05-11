#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const long long M=1e9+7;

int n,k;
long long fac[MAXN],inv[MAXN],invfac[MAXN],_10[MAXN],ans,a[MAXN];
char s[MAXN];

inline void init(int n)
{
	fac[0]=inv[1]=invfac[0]=_10[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%M;
	for (int i=2;i<=n;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	for (int i=1;i<=n;i++) invfac[i]=invfac[i-1]*inv[i]%M;
	for (int i=1;i<=n;i++) _10[i]=_10[i-1]*10%M;
	return ;
}

inline long long C(int n,int m)
{
	if (n<m||m<0) return 0;
	return fac[n]*invfac[m]%M*invfac[n-m]%M;
}

int main()
{
	scanf("%d %d",&n,&k);
	scanf("%s",s+1);
	init(100000);
	for (int i=1;i<n;i++) a[i]=C(n-1-i,k-1)*_10[i-1]%M;
	for (int i=1;i<n;i++) (a[i]+=a[i-1])%=M;
	for (int i=1;i<=n;i++)
	{
		long long t=a[n-i];
		t+=C(i-1,k)*_10[n-i]%M;t%=M;
		(ans+=t*(s[i]-'0')%M)%=M;
	}
	printf("%lld\n",ans);
	return 0;
}