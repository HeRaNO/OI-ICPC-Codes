#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int n;
long long a[MAXN];

int main()
{
	while (~scanf("%d",&n))
	{
		for (int i=0;i<=n;i++) scanf("%lld",&a[i]);a[n+1]=0;
		for (int i=n;~i;i--) a[i]+=a[i+1];
		for (int i=n;~i;i--) if (a[i]>=i){printf("%d\n",i);break;}
	}
	return 0;
}