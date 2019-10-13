#include <bits/stdc++.h>
#define MAXN 505
using namespace std;

int n,p,a[MAXN],ans[MAXN];
bool dp[MAXN][MAXN];

int main()
{
	scanf("%d %d",&n,&p);dp[0][0]=1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=p;j>=a[i];j--)
			for (int k=0;k+a[i]<=j;k++)
				if (dp[j-a[i]][k]) dp[j][k]=dp[j][k+a[i]]=true;
	for (int i=0;i<=p;i++) if (dp[p][i]) ans[++ans[0]]=i;
	printf("%d\n",ans[0]);
	for (int i=1;i<=ans[0];i++) printf("%d%c",ans[i],i==ans[0]?'\n':' ');
	return 0;
}