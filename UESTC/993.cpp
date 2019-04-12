#include <bits/stdc++.h>
using namespace std;

int n,T;char x;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %c",&n,&x);
		for (int i=1;i<n;i++)
		{
			for (int j=1;j<=n-i;j++) putchar(' ');
			for (int j=1;j<=(i<<1)-1;j++) putchar(x);
			putchar('\n');
		}
		for (int j=1;j<=(n<<1)-1;j++) putchar(x);putchar('\n');
		for (int i=n-1;i;i--)
		{
			for (int j=1;j<=n-i;j++) putchar(' ');
			for (int j=1;j<=(i<<1)-1;j++) putchar(x);
			putchar('\n');
		}
	}
	return 0;
}
