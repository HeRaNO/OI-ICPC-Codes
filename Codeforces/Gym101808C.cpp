#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,t[MAXN];
char a[MAXN],b[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",a);scanf("%s",b);int ans=0;
		n=strlen(a);
		for (int i=0;i<n&&ans!=-1;i++)
			if (a[i]!=b[i]&&a[i]!=b[n-i-1])
				ans=-1;
		if (!~ans){puts("-1");continue;}
		for (int i=0;i<(n>>1);i++)
		{
			if (ans&1)
			{
				if (a[i]!=b[n-i-1]) ++ans;
			}
			else
			{
				if (a[i]!=b[i]) ++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}