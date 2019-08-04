#include <bits/stdc++.h>
#define MAXN 500
using namespace std;

int n;
long long s,c=100LL,a[MAXN];
int d[MAXN],u[MAXN],cnt1,cnt2;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int dir=-1;a[0]=~(1LL<<63),a[n+1]=(1LL<<63);
	for(int i=1;i<=n;i++)
	{
		if(dir==-1&&a[i]<a[i+1])
		{
			d[++cnt1]=i;
			dir=1;
		}
		if(dir==1&&a[i]>a[i+1])
		{
			u[++cnt2]=i;
			dir=-1;
		}
	}
	for(int i=1;i<=min(cnt1,cnt2);i++)
	{
		s=min(100000LL,c/a[d[i]]);
		c-=s*a[d[i]];
		c+=s*a[u[i]];
		s=0;
	}
	printf("%lld\n",c);
	return 0;
}