#include <bits/stdc++.h>
using namespace std;

int n,T;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		if (n==2) puts("2");
		else if (n==4) puts("262144");
		else puts("0");
	}
	return 0;
}