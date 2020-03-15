#include <bits/stdc++.h>
using namespace std;

int T,n,x,ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		scanf("%d",&x);ans=3*x;
		for (int i=2;i<=n;i++) scanf("%d",&x),ans=max(ans,x+1);
		if (ans&1) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}