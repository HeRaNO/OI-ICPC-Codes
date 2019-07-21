#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int n;scanf("%d",&n);
		if (n==2||n==3) puts("second");
		else puts("first");
	}
	return 0;
}