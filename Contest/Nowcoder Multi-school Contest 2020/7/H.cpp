#include <bits/stdc++.h>
using namespace std;

const int M=1e9+7;

int main()
{
	long long n,k,sum=0;
	scanf("%lld %lld",&n,&k);
	for (long long i=1,j;i<=n;i=j+1)
	{
		j=n/(n/i);
		sum+=(min(j,k)-i+1)%M*(n/i)%M;
		sum%=M;
		if (j>=k) break;
	}
	n--;
	for (long long i=1,j;i<=n;i=j+1)
	{
		j=n/(n/i);
		sum+=(min(j,k)-i+1)%M*(n/i)%M;
		sum%=M;
		if (j>=k) break;
	}
	printf("%lld\n",((sum+k-n-1)%M+M)%M);
	return 0;
}