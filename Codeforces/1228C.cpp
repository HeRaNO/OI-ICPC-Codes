#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const long long M=1e9+7;

int x,v[MAXN],cnt;
long long n,ans=1;

long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,a=(a*a)%M) if (b&1) r=(r*a)%M;
	return r;
}

int main()
{
	scanf("%d %lld",&x,&n);int p=x;
	for (int i=2;i*i<=x;i++)
		if (!(p%i))
		{
			v[++cnt]=i;
			while (!(p%i)) p/=i;
		}
	if (p!=1) v[++cnt]=p;
	for(int i=1;i<=cnt;i++)
	{
		int now=v[i];
		long long p=n;
		while (p)
		{
			p/=now;
			(ans*=fpow(now,p))%=M;
		}
	}
	printf("%lld\n",ans);
	return 0;
}