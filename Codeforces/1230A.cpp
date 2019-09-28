#include <bits/stdc++.h>
using namespace std;

int a[5];

int main()
{
	scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]);
	int all=a[0]+a[1]+a[2]+a[3];
	for (int i=0;i<(1<<4);i++)
	{
		int ans=0;
		for (int j=0;j<4;j++)
			if (i&(1<<j)) ans+=a[j];
		if ((ans<<1)==all) return puts("YES"),0;
	}
	puts("NO");
	return 0;
}