#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

const int Z=9999;

int n,p,ans,a[MAXN],b[MAXN],cnt[Z<<1|1];

int main()
{
	scanf("%d",&n);p=n>>1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]),++cnt[a[i]-b[i]+Z],ans+=b[i];
	for (int i=0;p;i++)
		while (cnt[i]&&p) ans+=(i-Z),--p,--cnt[i];
	printf("%d\n",ans);
	return 0;
}