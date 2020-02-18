#include <bits/stdc++.h>
using namespace std;

int T,n,x,a;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&x);int ans=0,mx=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a),mx=max(mx,a);
			if (a==x) ans=1;
		}
		if (!ans) ans=max(2,(x-1)/mx+1);
		printf("%d\n",ans);
	}
	return 0;
}