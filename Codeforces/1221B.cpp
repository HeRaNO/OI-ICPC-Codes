#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			putchar((i+j)&1?'W':'B');
		putchar('\n');
	}
	return 0;
}