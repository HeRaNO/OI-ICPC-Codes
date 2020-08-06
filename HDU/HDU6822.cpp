#include <bits/stdc++.h>
using namespace std;

const int M=998244353;
inline void fadd(long long &x,long long y){x+=y;if (x>=M) x-=M;return ;}

inline long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,(a*=a)%=M) if (b&1) (r*=a)%=M;
	return r;
}

int main(int argc, char const *argv[])
{
	int T;scanf("%d",&T);
	while (T--)
	{
		long long n;
		scanf("%lld",&n);
		long long ans=fpow(2,n%(M-1));fadd(ans,1);
		(ans*=fpow(2,n%(M-1)))%=M;
		ans+=2*fpow(3,n%(M-1))%M;
		printf("%lld\n",ans*fpow(fpow(2,n%(M-1)),M-2)%M);
	}
	return 0;
}