#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int n,m,pt;
long long x,s[MAXN];

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&x),s[i]=s[i-1]+x;
	for (int i=1;i<=m;i++)
	{
		scanf("%lld",&x);
		pt=lower_bound(s+1,s+n+1,x)-(s+1);
		printf("%d %lld\n",pt+1,x-s[pt]);
	}
	return 0;
}