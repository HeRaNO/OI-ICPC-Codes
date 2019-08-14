#include <bits/stdc++.h>
using namespace std;

int a,x,n,mn=~(1<<31);

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a+=x;mn=min(mn,x);
	}
	if (n&1)
	{
		if (a&1) puts("Iori");
		else puts("Yayoi");
	}
	else
	{
		if (a&1) puts("Iori");
		else
		{
			if (mn&1) puts("Iori");
			else puts("Yayoi");
		}
	}
	return 0;
}