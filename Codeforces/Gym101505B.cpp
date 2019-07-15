#include <bits/stdc++.h>
using namespace std;

int p[1100],n,a;

int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=1;i<=n;i++)
		{
			int c=0,ok=0;
			scanf("%d",&a);
			while (a)
			{
				c|=1<<(a%10);a/=10;
			}
			for (int i=1;i<=9;i++) if (c&(1<<i)) ok=ok*10+i;
			p[i]=ok;
		}
		sort(p+1,p+n+1);
		n=unique(p+1,p+n+1)-(p+1);
		printf("%d\n",n);
	}
	return 0;
}
