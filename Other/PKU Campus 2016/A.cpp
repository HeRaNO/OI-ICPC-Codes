#include <bits/stdc++.h>
using namespace std;

int n,p,a,b,c,ans,mx,T;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&p);mx=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d.%d",&a,&b,&c);
			if (p<a) continue;
			if (b*100+c>mx)
			{
				mx=b*100+c;ans=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}