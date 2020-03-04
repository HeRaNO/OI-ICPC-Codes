#include <bits/stdc++.h>
#define MAXN 200005
#define MAXM 1005
using namespace std;

int n,m,a[MAXN],ans=1;

int main()
{
	scanf("%d %d",&n,&m);
	if (n>m) return puts("0"),0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			(ans*=abs(a[i]-a[j])%m)%=m;
	printf("%d\n",ans);
	return 0;
}
