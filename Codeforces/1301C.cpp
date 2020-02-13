#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,m;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		if (!m){puts("0");continue;}
		long long ans=1LL*n*(n+1)/2;
		long long p=(n-m)/(m+1),q=(n-m)%(m+1);
		ans-=p*(p+1)/2*(m-q+1)+(p+1)*(p+2)/2*q;
		printf("%lld\n",ans);
	}
	return 0;
}
