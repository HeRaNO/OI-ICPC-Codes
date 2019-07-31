#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int a[MAXN],n,x,y;

int main()
{
	scanf("%d %d %d",&n,&x,&y);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		bool f=true;
		for (int j=max(i-x,1);j<=min(i+y,n)&&f;j++)
		{
			if (j==i) continue;
			if (a[i]>=a[j]) f=false;
		}
		if (f) return printf("%d\n",i),0;
	}
	return 0;
}