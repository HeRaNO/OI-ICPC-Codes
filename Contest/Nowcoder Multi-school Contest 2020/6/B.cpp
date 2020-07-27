#include <bits/stdc++.h>
#define MAXN 20000005
using namespace std;

const long long M=1e9+7;

int T;
int f[MAXN],_2[MAXN],inv[MAXN];

inline long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,(a*=a)%=M) if (b&1) (r*=a)%=M;
	return r;
}

void init(int n)
{
	_2[0]=1;f[0]=1;
	for (int i=1;i<=n;i++) _2[i]=2LL*_2[i-1]%M;
	inv[n]=fpow(fpow(2,1LL*n*(n+1)/2),M-2);
	for (int i=n-1;i;i--) inv[i]=1LL*inv[i+1]*_2[i+1]%M;
	for (int i=1;i<=n;i++) f[i]=1LL*f[i-1]*(_2[i]-1)%M;
	for (int i=1;i<=n;i++) f[i]=1LL*f[i]*inv[i]%M;
	f[0]=0;for (int i=1;i<=n;i++) f[i]^=f[i-1];
	return ;
}

int main()
{
	init(20000000);
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",f[n]);
	}
	return 0;
}