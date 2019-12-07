#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

const long long M=998244353;

int n,x,a[MAXN];
long long p=100,ans,inv[105];

int main()
{
	inv[1]=1;for (int i=2;i<=100;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x),a[i]=inv[x];
	for (int i=n;i;i--,(p*=100)%=M) (p*=a[i])%=M,(ans+=p)%=M;
	printf("%lld\n",ans);
	return 0;
}