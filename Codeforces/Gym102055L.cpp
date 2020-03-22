#include <bits/stdc++.h>
using namespace std;

int T;
long long n;

inline bool isPrime(long long x)
{
	if (x==1) return false;
	if (x==2) return true;
	for (long long i=2;i*i<=x;i++)
		if (!(x%i)) return false;
	return true;
}

void fix(long long n,int s)
{
	long long p=n>>1;
	for (long long i=2;i<=p;i++) 
		if (isPrime(i)&isPrime(n-i))
		{
			printf("%d %lld %lld\n",s,i,n-i);
			return ;
		}
	assert(false);
	return ;
}

int main()
{
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		printf("Case %d: ",cas);
		scanf("%lld",&n);
		if (n<=11)
		{
			puts("IMPOSSIBLE");
			continue;
		}
		printf("2 2 2 ");n-=6;
		if (n&1) fix(n-3,3);
		else fix(n-2,2);
	}
	return 0;
}
