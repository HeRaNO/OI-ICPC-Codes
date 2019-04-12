#include <bits/stdc++.h>
using namespace std;

int n;char a[16];

int main()
{
	while (true)
	{
		scanf("%d",&n);
		if (!n) break;
		scanf("%s",a);
		int cnt=0;
		if (a[n-1]=='B')
		{
			for (int i=0;i<n-1;i++) cnt+=a[i]=='R';
			if (cnt==7) puts("Red");
			else puts("Yellow");
		}
		else
		{
			for (int i=0;i<n-1;i++) cnt+=a[i]=='Y';
			if (cnt!=7) puts("Red");
			else puts("Yellow");
		}
	}
	return 0;
}