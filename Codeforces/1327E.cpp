#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

const long long M=998244353;
int n;

inline long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,(a*=a)%=M) if (b&1) (r*=a)%=M;
	return r;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		long long ans1=180*fpow(10,n-i-1)%M;
		long long ans2=0;
		if (n>=i+2)
			ans2=810*fpow(10,n-i-2)%M*(n-i-1)%M;
		printf("%lld ",(ans1+ans2)%M);
	}
	printf("10\n");
	return 0;
}