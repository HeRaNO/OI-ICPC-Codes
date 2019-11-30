#include <bits/stdc++.h>
using namespace std;

int T,r,b,k;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&r,&b,&k);
		int g=__gcd(r,b);r/=g;b/=g;
		if (r>b) swap(r,b);
		if (1LL*(k-1)*r+1<b) puts("REBEL");
		else puts("OBEY");
	}
	return 0;
}