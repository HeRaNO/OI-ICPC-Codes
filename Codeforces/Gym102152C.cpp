#include <bits/stdc++.h>
using namespace std;

int T,n,m;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		if (n&1)
		{
			if (m&1) puts("12");
			else puts("2");
		}
		else puts("2");
	}
	return 0;
}