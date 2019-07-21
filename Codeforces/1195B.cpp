#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;
 
long long n,k;
 
int main()
{
	scanf("%lld %lld",&n,&k);long long ans=0;
	long long p=8*(n+k)+9;
	for (long long i=1;i*i<=p&&!ans;i++)
		if (i*i==p) ans=i;
	printf("%lld\n",n-(ans-3)/2);
	return 0;
}