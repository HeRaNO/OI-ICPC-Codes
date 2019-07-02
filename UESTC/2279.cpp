#include <bits/stdc++.h>
using namespace std;

const long long M=1e9+7;
const long long _inv2=500000004LL;

int T;
long long p1,p2,n,p;

long long phi(long long x)
{
	long long res=x;
	for (long long i=2;i*i<=x;i++)
		if (x%i==0)
		{
			res/=i;res*=(i-1);
			while (x%i==0) x/=i;
		}
	if (x!=1) res/=x,res*=(x-1);
	return res;
}

inline long long f(long long x,long long i)
{
	long long t=phi(x/i);
	t=(t*(x/i))%M;
	if (i==x) (t=t+1)%M;
	t=(t*_inv2)%M;
	t=(t*i*i)%M;
	return t;
}

inline long long calc(int x)
{
	long long ans=0;
	for (int i=1;i*i<=x;i++)
		if (!(x%i))
		{
			ans+=f(x,i);ans%=M;
			if (i!=x/i){ans+=f(x,x/i);ans%=M;}
		}
	return ans;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld %lld",&n,&p);
		p1=calc(p-1);
		p2=p*(p-1)%M*_inv2%M;
		printf("%lld\n",(n*(p1-p2+M))%M);
	}
	return 0;
}
