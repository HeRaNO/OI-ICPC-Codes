#include <cstdio>
#define MAXN 100010
using namespace std;

const long long M=1e9+7;

long long a,b,ans,inv[MAXN];
int n,k;

long long fpow(int b)
{
	long long r,a=2;
	for (r=1;b;(a*=a)%=M,b>>=1) if (b&1) (r*=a)%=M;
	return r;
}

int main()
{
	scanf("%d %d",&n,&k);inv[1]=1LL;
	ans=fpow(n);
	for (int i=2;i<k;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	ans=(ans-n-1+M)%M;
	a=1LL*n*(n-1)%M;b=inv[2];
	for (int i=2;i<k;i++)
	{
		ans=(ans-a*b%M+M)%M;
		(a*=(n-i))%=M;(b*=inv[i+1])%=M;
	}
	printf("%lld\n",ans);
	return 0;
}