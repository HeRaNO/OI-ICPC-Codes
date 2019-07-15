#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n,m,T;
long long a[MAXN],ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);ans=0LL;
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		m<<=1;
		sort(a+1,a+n+1);
		for (int i=1;i<=m;i++) ans+=a[i]*a[m-i+1];
		printf("%lld\n",ans>>1);
	}
	return 0;
}