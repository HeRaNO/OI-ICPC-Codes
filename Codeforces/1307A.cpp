#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int T,n,d,a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&d);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=d;i++)
		{
			for (int j=2;j<=n;j++)
				if (a[j])
				{
					++a[j-1];--a[j];break;
				}
		}
		printf("%d\n",a[1]);
	}
	return 0;
}