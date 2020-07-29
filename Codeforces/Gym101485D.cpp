#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,r,p;
long long f[MAXN];

long long getf(int x)
{
	if(f[x]<1e17)return f[x];
	x--;
	for (int i=1,j;i<=x;i=j+1)
	{
		j=x/(x/i);
		f[x+1]=min(f[x+1],getf(i)+1LL*(x/i)*p+r);
	}
	return f[x+1];
}

int main()
{
	scanf("%d %d %d",&n,&r,&p);
	memset(f,0x3f,sizeof f);f[1]=0;f[2]=r+p;
	printf("%lld\n",getf(n));
	return 0;
}
