#include <bits/stdc++.h>
using namespace std;

int T,n,s,f,t,ans;

int main()
{
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		scanf("%d %d",&n,&s);ans=1<<31;
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d",&f,&t);
			if (t<=s) ans=max(ans,f);
			else ans=max(ans,f-t+s);
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}