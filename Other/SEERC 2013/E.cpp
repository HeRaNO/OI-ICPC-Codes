#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+10;
const int INF=0x7fffffff;

ll a,b,s,x,y;

long long exgcd(long long a, long long b, long long &x, long long &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long res = exgcd(b, a % b, x, y);
	long long t = x;
	x = y;
	y = t - (a / b) * y;
	return res;
}

inline int solve()
{
	if (a==s||b==s) return puts("YES"),0;
	if (!a)
	{
		if (b==0) return puts(!s?"YES":"NO"),0;
		return puts(s%b?"NO":"YES"),0;
	}
	else if (!b)
	{
		if (a==0) return puts(!s?"YES":"NO"),0;
		return puts(s%a?"NO":"YES"),0;
	}
	ll res=INF;
	res=exgcd(a,b,x,y);
	if(s%res) return puts("NO"),0;
	a/=res;
	b/=res;
	s/=res;
	x*=s%b;
	x%=b;
	while(x<0)x+=b;
	y=(s-a*x)/b;
	while(y>=0)
	{
		if(__gcd(x,y)==1)
		{
			return puts("YES"),0;
		}
		x+=b;
		y-=a;
	}
	puts("NO");
	return 0;
}

int main()
{
	while (~scanf("%lld%lld%lld",&a,&b,&s)) solve();
	return 0;
}
