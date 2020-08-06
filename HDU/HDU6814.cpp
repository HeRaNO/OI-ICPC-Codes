#include <bits/stdc++.h>
#define MAXN 6000005
using namespace std;

const int M=998244353;

long long f[MAXN],inv[MAXN];
int T,n;

inline void fadd(long long &x,long long y){x+=y;if (x>=M) x-=M;return ;}

inline void init(int n)
{
	inv[1]=1;
	for (int i=2;i<=n;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	for (int i=1;i<=n;i++) f[i]=inv[i]*inv[i]%M,fadd(f[i],f[i-1]);
	return ;
}

int main()
{
	init(6000000);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		printf("%lld\n",inv[n]*f[n]%M*3%M);
	}
	return 0;
}