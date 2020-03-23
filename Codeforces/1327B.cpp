#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,m,x;
bool a[MAXN],b[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);int ans=0;
		for (int i=1;i<=n;i++) a[i]=b[i]=false;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for (int j=1;j<=m;j++)
			{
				scanf("%d",&x);
				if (!a[x]&&!b[i])
				{
					a[x]=b[i]=true;++ans;
				}
			}
		}
		if (ans==n){puts("OPTIMAL");continue;}
		int p=0,q=0;
		for(int i=1;i<=n;i++)
		{
			if (!a[i]) p=i;
			if (!b[i]) q=i;
		}
		puts("IMPROVE");
		printf("%d %d\n",q,p);
	}
	return 0;
}