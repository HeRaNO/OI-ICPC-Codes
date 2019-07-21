#include <bits/stdc++.h>
#define MAXN 155
using namespace std;

long long s;

int main()
{
	scanf("%lld",&s);
	long long p=sqrt(s),x1,x2,x3,y1,y2,y3;
	if (p*p==s)
	{
		printf("0 0 0 %lld %lld 0\n",p,p);
		return 0;
	}
	if (p*p<s) ++p;
	x1=0;y1=0;
	x2=p;y2=1;
	y3=x2;x3=x2*y3-s;
	if (x3>1000000000)
	{
		y2=1;y3=x2-1;x3=x2*y3-s;
	}
	printf("%lld %lld %lld %lld %lld %lld\n", x1,y1,x2,y2,x3,y3);
	return 0;
}