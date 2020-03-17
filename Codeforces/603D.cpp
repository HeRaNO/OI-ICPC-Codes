#include <bits/stdc++.h>
#define MAXN 2005
using namespace std;

map <pair<long long,long long>,int> mp;
int n,x[MAXN],y[MAXN],z[MAXN];
long long ans;

pair <long long,long long> calc(long long x,long long y)
{
	long long g=__gcd(abs(x),abs(y));
	if (g){x/=g;y/=g;}
	if (y<0||(y==0&&x<0)){x=-x;y=-y;}
	return {x,y};
}

int main()
{
	scanf("%d",&n);int cnt=0;
	for (int i=1,a,b,c;i<=n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		x[i]=a*c;y[i]=b*c;z[i]=a*a+b*b;
	}
	for (int i=1;i<=n;i++)
	{
		int cnt=0,not_exist=0;mp.clear();
		for (int j=i+1;j<=n;j++)
		{
			long long p=1LL*x[j]*z[i]-1LL*x[i]*z[j];
			long long q=1LL*y[j]*z[i]-1LL*y[i]*z[j];
			pair <long long,long long> ang=calc(p,q);
			if (!ang.first&&!ang.second)
			{
				ans+=cnt;++not_exist;
			}
			else
			{
				ans+=mp[ang]+not_exist;
				++mp[ang];
			}
			++cnt;
		}
	}
	printf("%lld\n",ans);
	return 0;
}