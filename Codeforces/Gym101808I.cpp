#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int T,n,a[MAXN],s,mn;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);s=0;mn=~(1<<31);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i],mn=min(mn,a[i]);
		if (n&1)
		{
			if (s&1) puts("Yalalov");
			else puts("Shin");
		}
		else
		{
			if (s&1) puts("Yalalov");
			else
			{
				if (mn&1) puts("Yalalov");
				else puts("Shin");
			}
		}
	}
	return 0;
}