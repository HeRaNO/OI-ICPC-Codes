#include <bits/stdc++.h>
using namespace std;

int n,x;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		printf("%d%c",n-x+1,i==n?'\n':' ');
	}
	return 0;
}