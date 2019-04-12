#include <bits/stdc++.h>
using namespace std;

int T,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		printf("%d %d\n",n*(n-1)+1,n*(n+1)-1);
	}
	return 0;
}
