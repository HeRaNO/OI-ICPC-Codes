#include <bits/stdc++.h>
using namespace std;

int T;
long long n,a,b;

inline long long f(long long y)
{
	return a*(n-2*y)+b*y;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%I64d %I64d %I64d",&n,&a,&b);
		if (b-2*a>=0) printf("%I64d\n",n*a);
		else
		{
			if (n&1) printf("%I64d\n",(n/2)*b+a);
			else printf("%I64d\n",(n/2)*b);
		}
	}
	return 0;
}
