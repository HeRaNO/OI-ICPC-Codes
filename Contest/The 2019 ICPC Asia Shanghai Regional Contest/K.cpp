#include <bits/stdc++.h>
#define MAXN 20
#define MAXM 130
using namespace std;

int n,m,T,a[MAXM],b[MAXM];

int main()
{
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		scanf("%d %d",&n,&m);int ans=0;
		for (int i=1;i<=m;i++)
		{
			scanf("%d %d",&a[i],&b[i]);
			--a[i];--b[i];
		}
		for (int i=0;i<(1<<n);i++)
		{
			int now=0;
			for (int j=1;j<=m;j++)
			{
				int p=(i>>a[j])&1,q=(i>>b[j])&1;
				if (p^q) ++now;
			}
			ans=max(ans,now);
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}