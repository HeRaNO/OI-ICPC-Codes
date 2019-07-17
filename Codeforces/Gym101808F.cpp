#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

const int M=7901;

int n,T,ans,fac[MAXN],a[MAXN];

int main()
{
	fac[0]=1;
	for (int i=1;i<=1000;i++) fac[i]=fac[i-1]*i%M;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);ans=1;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);a[n+1]=0;
		sort(a+1,a+n+1);int i=1;
		while (i<=n)
		{
			int pt=i;
			while (i<=n&&a[i]==a[i+1]) i++;
			ans=ans*fac[i-pt+1]%M;
			++i;
		}
		printf("%d\n",ans);
	}
	return 0;
}