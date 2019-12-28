#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		long long p=min(min(a,b),c);
		long long q=max(max(a,b),c);
		long long r=a+b+c-p-q;
		if (p+r+1>=q) puts("Yes");
		else puts("No");
	}
	return 0;
}