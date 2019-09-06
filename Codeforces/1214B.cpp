#include <cstdio>

int main()
{
	int b,g,n,ans=0;
	scanf("%d %d %d",&b,&g,&n);
	for (int i=0;i<=n;i++) if (b>=i&&g>=n-i) ++ans;
	printf("%d\n",ans);
	return 0;
}