#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
int a[100];

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1,x,y;i<=n;i++)
	{
		scanf("%d",&x);
		for (int j=1;j<=x;j++)
		{
			scanf("%d",&y);++a[y];
		}
	}
	for (int i=1;i<=m;i++) if (a[i]==n) ++ans;
	printf("%d\n", ans);
	return 0;
}