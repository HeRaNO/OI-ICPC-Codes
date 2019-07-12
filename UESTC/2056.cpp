#include <bits/stdc++.h>

long long n,ans;

int main()
{
	scanf("%lld",&n);
	for (long long i=1;i<n;i<<=1LL) ans+=i*(((n-1)/i+1)/2);
	printf("%lld\n",ans);
	return 0;
}