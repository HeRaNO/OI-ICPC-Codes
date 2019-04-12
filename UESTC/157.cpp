#include <bits/stdc++.h>
using namespace std;

int T,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int x=sqrt(n);
		printf("%d\n",x*x);
	}
	return 0;
}
