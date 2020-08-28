#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;

const int M=1e9+7;

int n,a[MAXN],cnt[MAXN];
long long inv[MAXN],invfac[MAXN],f[MAXN],fac[MAXN];

inline void init(int n)
{
	inv[1]=invfac[0]=fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%M;
	for (int i=2;i<=n;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	for (int i=1;i<=n;i++) invfac[i]=invfac[i-1]*inv[i]%M;
	return ;
}

inline void Solve()
{
	memset(f,0,sizeof f);
	scanf("%d",&n);f[0]=1;a[0]=1;
	for (int i=1;i<n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) cnt[i]=cnt[i-1]+a[i];
	for (int i=1;i<=n;i++)
		for (int j=i-1;j>=0;j--)
			if (a[j])
			{
				long long t=f[j];
				(t*=invfac[i-j])%=M;
				int tt=cnt[i-1]-cnt[j];
				if (tt&1) t=M-t;
				f[i]+=t;
				if (f[i]>=M) f[i]-=M;
			}
	printf("%lld\n",f[n]*fac[n]%M);
	return ;
}

int main()
{
	init(5000);
	int T;scanf("%d",&T);
	while (T--) Solve();
	return 0;
}
