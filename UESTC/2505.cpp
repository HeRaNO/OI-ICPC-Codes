#include <bits/stdc++.h>
using namespace std;

unordered_map <long long,long long> mp;
int T,a,m,b;

void exgcd(long long a,long long b,long long &x,long long &y)
{
	if (!b){x=1;y=0;return ;}
	exgcd(b,a%b,y,x);y-=x*(a/b);return ;
}

inline long long inv(long long a,long long m)
{
	long long x,y;exgcd(a,m,x,y);
	return (x+m)%m;
}

long long exBSGS(long long a,long long b,long long M)
{
	if (b==1) return 0;
	long long w=1;int c=0;
	for (long long d;(d=__gcd(a,M))!=1;)
	{
		if (b%d) return -1;
		b/=d;M/=d;++c;w=w*(a/d)%M;
		if (w==b) return c;
	}
	b=b*inv(w,M)%M;mp.clear();
	long long t=1LL,r=b,x,y,B=ceil(sqrt(M));
	for (long long i=0;i<B;i++,t=t*a%M) if (!mp.count(t)) mp.insert({t,i});
	t=inv(t,M);
	for (long long i=0;i<B;i++,b=b*t%M) if (mp.count(b)) return i*B+mp[b]+c;
	return -1LL;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&a,&b,&m);
		int ret=exBSGS(a,b,m);
		if (!~ret) puts("QAQ");
		else printf("%d\n",ret);
	}
	return 0;
}