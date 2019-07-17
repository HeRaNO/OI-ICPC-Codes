#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		long long R,r;
		scanf("%lld %lld",&R,&r);
		if (R*R>r*r*2) puts("1");
		else puts("2");
	}
	return 0;
}