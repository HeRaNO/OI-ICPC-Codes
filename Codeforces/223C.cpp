#include <cstdio>
#define MAXN 2005
using namespace std;

const long long M=1000000007;

int n,m;
long long a[MAXN],c[MAXN],r[MAXN<<1],inv[MAXN],x=1LL,invn,k;

int main()
{
	scanf("%d %lld",&n,&k);inv[1]=1LL;
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=2;i<=n;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	for (int i=0;i<n;i++)
	{
		c[i]=x;(x*=(i+k))%=M;(x*=inv[i+1])%=M;
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			(r[i+j]+=a[i]*c[j]%M)%=M;
	for (int i=0;i<n;i++) printf("%lld%c",r[i],i==n-1?'\n':' ');
	return 0;
}