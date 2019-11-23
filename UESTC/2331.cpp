#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n,m,x,ans,a[MAXN];

int main()
{
	memset(a,0x3f,sizeof a);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&x);
			if (~x) a[j]=min(a[j],x);
		}
	for (int i=1;i<=n;i++) ans+=a[i];
	printf("%d\n",ans);
	return 0;
}