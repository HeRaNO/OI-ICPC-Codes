#include <bits/stdc++.h>
using namespace std;

int T,n,m,ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);ans=0;
		for (int i=1,x;i<=n;i++) scanf("%d",&x),ans+=x;
		printf("%d\n",min(ans,m));
	}
	return 0;
}