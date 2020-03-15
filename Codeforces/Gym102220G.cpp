#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
struct rectangle
{
	int xl,yl,xr,yr;
}a[100050];
int r[200050],c[200050];
int totr,totc;
ll ans;

int main()
{
	int Test;cin>>Test;
	while(Test--)
	{
		cin>>n;totr=totc=ans=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d%d",&a[i].xl,&a[i].yl,&a[i].xr,&a[i].yr);
			r[++totr]=a[i].xl;c[++totc]=a[i].yl;
			r[++totr]=a[i].xr;c[++totc]=a[i].yr;
		}
		sort(r+1,r+totr+1);
		sort(c+1,c+totc+1);
		int midr=(r[n]+r[n+1])>>1;
		int midc=(c[n]+c[n+1])>>1;
		for(int i=1;i<=n;++i)
		{
			ans+=(abs(a[i].xl-midr)+abs(a[i].xr-midr)-abs(a[i].xl-a[i].xr))/2
				+(abs(a[i].yl-midc)+abs(a[i].yr-midc)-abs(a[i].yl-a[i].yr))/2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
