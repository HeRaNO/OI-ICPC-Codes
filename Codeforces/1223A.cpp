#include <bits/stdc++.h>
using namespace std;

int T,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		if (n<=4) printf("%d\n",4-n);
		else printf("%d\n",n&1);
	}
	return 0;
}