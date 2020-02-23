#include <bits/stdc++.h>
using namespace std;

int T;
long long n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld",&n);
		printf("%lld\n",(n+1)^(n*(n+1)));
	}
	return 0;
}