#include <bits/stdc++.h>
using namespace std;

long long a[10],m[10],mx,q,M=1;

long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if (!b){x=1;y=0;return a;}
	long long res=exgcd(b,a%b,x,y);
	long long t=x;x=y;y=t-(a/b)*y;
	return res;
}

inline long long exCRT(int n)
{
	long long M=m[1],ans=a[1],x,y;
	for (int i=2;i<=n;i++)
	{
		long long g=exgcd(M,m[i],x,y);
		if ((a[i]-ans)%g) return -1LL;
		x=(a[i]-ans)/g*x%(m[i]/g);
		ans+=x*M;M=M/g*m[i];ans%=M;
	}
	return (ans+M)%M;
}

int main()
{
	for (int i=1;i<=6;i++) scanf("%lld",&m[i]),M*=m[i];
	for (int i=1;i<=6;i++)
	{
		scanf("%lld",&a[i]);mx=max(a[i],mx);
		a[i]%=m[i];if (!a[i]) a[i]=m[i];
	}
	q=exCRT(6);
	while (q<mx) q+=M;
	printf("%lld\n",q);
	return 0;
}
