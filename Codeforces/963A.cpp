#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
 
const long long M=1e9+9;
 
int n,m,a,b,k;
char s[MAXN];
long long ans,q;
 
inline long long f(char a)
{
	return a=='-'?-1:1;
}
 
inline long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,a=(a*a)%M) if (b&1) r=(r*a)%M;
	return r;
}
 
inline long long sum(long long a1,long long q,long long n)
{
	if (q==1) return a1*n%M;
	long long p=(fpow(q,n)-1+M)%M;
	long long qq=(q-1+M)%M;qq=fpow(qq,M-2);
	return a1*p%M*qq%M;
}
 
int main()
{
	scanf("%d %d %d %d",&n,&a,&b,&k);
	q=b*fpow(a,M-2)%M;q=fpow(q,k);m=(n+1)/k;
	scanf("%s",s);
	if (n<k)
	{
		for (int i=0;i<=n;i++)
		{
			long long t=fpow(a,n-i)*fpow(b,i)%M;
			if (s[i]=='-') t=M-t;
			(ans+=t)%=M;
		}
		return printf("%lld\n",ans),0;
	}
	for (int i=0;i<k;i++)
	{
		long long x=sum(fpow(a,n-i)*fpow(b,i)%M,q,m);
		if (s[i]=='-') x=M-x;
		(ans+=x)%=M;
	}
	printf("%lld\n",ans);
	return 0;
}