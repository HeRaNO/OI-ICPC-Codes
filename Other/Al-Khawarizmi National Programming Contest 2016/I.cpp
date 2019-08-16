#include <bits/stdc++.h>
using namespace std;

int v[11],t[11],n,ans,kas;

int main()
{
	while (true)
	{
		scanf("%d",&n);if (n==-1) break;
		ans=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d",&v[i],&t[i]);
		}
		for (int i=1;i<=n;i++) ans+=v[i]*(t[i]-t[i-1]);
		printf("%d miles\n",ans);
	}
	return 0;
}