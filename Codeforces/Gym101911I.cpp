#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int n,a[MAXN],ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++) ans+=a[i]-a[i-1]-1;
	printf("%d\n",ans);
	return 0;
}