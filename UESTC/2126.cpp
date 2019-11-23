#include <bits/stdc++.h>
using namespace std;

int n,x;
long long ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x),ans+=x;
	printf("%lld\n",ans-(n-1));
	return 0;
}