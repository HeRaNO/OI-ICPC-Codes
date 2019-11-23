#include <bits/stdc++.h>
using namespace std;

int n,x,ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		ans+=x-1;
	}
	printf("%d\n",ans);
	return 0;
}