#include <bits/stdc++.h>
using namespace std;

long long m,l,r,ans=-1;

inline long long check(long long mid)
{
	long long res=0LL;
	for (long long k=2;k*k*k<=mid;k++) res+=mid/(k*k*k);
	return res;
}

int main()
{
	scanf("%lld",&m);
	l=0;r=0x3f3f3f3f3f3f3f3fLL;
	while (l<=r)
	{
		long long mid=l+r>>1;
		if (check(mid)>=m){ans=mid;r=mid-1;}
		else l=mid+1;
	}
	printf("%lld\n",check(ans)==m?ans:-1);
	return 0;
}