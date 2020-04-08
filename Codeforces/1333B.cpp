#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,m;
int a[MAXN],b[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		bool s=false,g=false,f=true;
		for (int i=1;i<=n&&f;i++)
		{
			if(b[i]<a[i]&&!s) f=false;
			if(b[i]>a[i]&&!g) f=false;
			if (a[i]>0) g=1;
			if (a[i]<0) s=1;
		}
		puts(f?"YES":"NO");
	}
	return 0;
}