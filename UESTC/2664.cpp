#include <cstdio>
using namespace std;

int T;

inline void solve(long long a,long long b,long long &x,long long &y,long long c,long long d)
{
	if (c<=d) solve(d,c,y,x,b,a);
	else if (a>=b)
	{
		long long t=a/b;
		solve(a-b*t,b,x,y,c-d*t,d);
		x+=y*t;
	}
	else x=y=1;
	return ;
}

inline void Solve()
{
	long long p,b,x,y;
	scanf("%lld %lld",&x,&p);
	solve(p,x,b,y,p,x-1);
	printf("%lld/%lld\n",b*x-p*y,b);
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}
