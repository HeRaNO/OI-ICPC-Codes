#include <bits/stdc++.h>
using namespace std;

long long p,q,ans;

void gcd(long long p,long long q)
{
	if (!q) return ;
	ans+=p/q;gcd(q,p%q);
	return ;
}

int main()
{
	scanf("%lld %lld",&p,&q);
	gcd(p,q);
	printf("%lld\n",ans);
	return 0;
}