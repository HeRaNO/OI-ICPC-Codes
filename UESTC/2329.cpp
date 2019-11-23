#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;

int n,x,y,ans=~(1<<31),a[MAXN];

int main()
{
	scanf("%d",&n);
	scanf("%d %d",&x,&y);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<=5000;i++)
	{
		int cnt=0;
		for (int j=1;j<=n;j++) cnt+=max((a[j]-x*i+y-1)/y,0);
		ans=min(ans,cnt+i);
	}
	printf("%d\n",ans);
	return 0;
}