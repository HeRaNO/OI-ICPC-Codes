#include <bits/stdc++.h>
using namespace std;

int T,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		if (n&1) putchar('7'),n-=3;
		for (int i=1,p=n>>1;i<=p;i++) putchar('1');
		putchar('\n');
	}
	return 0;
}