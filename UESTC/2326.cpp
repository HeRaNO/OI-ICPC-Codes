#include <bits/stdc++.h>
#define MAXX 205
#define MAXY 20105
#define MAXN 10005
using namespace std;

int n,k,b,cnt[MAXX][MAXY],ans[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&k,&b);
		for (int j=0;j<=200;j++) ++cnt[j][k*j+b];
	}
	for (int i=0;i<=200;i++)
		for (int j=0;j<=20100;j++)
			++ans[cnt[i][j]];
	for (int i=2;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}