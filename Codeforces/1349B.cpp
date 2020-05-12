#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int T,n,k,x,a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&k);bool f=false,g=false;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			a[i]=(x>=k);
			if (x==k) g=true;
		}
		if (n==1) f=true;
		for (int i=1;i<n&&!f;i++) if (a[i]+a[i+1]==2) f=true;
		for (int i=2;i<n&&!f;i++) if (!a[i]&&a[i-1]==a[i+1]&&a[i-1]==1) f=true;
		puts((f&&g)?"yes":"no");
	}
	return 0;
}