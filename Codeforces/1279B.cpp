#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,S,a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		long long s=0;int pt=0;
		scanf("%d %d",&n,&S);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i];
		if (s<=S){puts("0");continue;}
		s=0;
		for (int i=1;i<=n;i++)
		{
			s+=a[i];int p=pt;
			if (a[i]>a[pt]) pt=i;
			if (s-a[pt]>S)
			{
				pt=p;
				break;
			}
		}
		printf("%d\n",pt);
	}
	return 0;
}