#include <bits/stdc++.h>
#define MAXN 250005
using namespace std;

int n;
long long m,fac[MAXN],ans;

int main()
{
	scanf("%d %lld",&n,&m);fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%m;
	for (int i=1;i<=n;i++) (ans+=fac[i]*fac[n-i+1]%m*(n-i+1)%m)%=m;
	printf("%lld\n",ans);
	return 0;
}