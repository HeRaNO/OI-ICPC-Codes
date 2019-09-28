#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=5e5+10,MAXM=2e5+10;
const int INF=~(1<<31),MOD=1e9+7;

ll a[MAXN];

int main()
{
	ll n,m;
	ll sum=0;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	ll upb,lob;
	if(sum%n==0) upb=lob=sum/n;
	else
	{
		lob=sum/n;
		upb=lob+1;
	}
	ll ans1=0,ans2=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<lob)
			ans1+=lob-a[i];
		if(a[i]>upb)
			ans2+=a[i]-upb;
	}
	if(m>=ans1&&m>=ans2)
	{
		if(upb==lob)
		{
			puts("0");
			return 0;
		}
		else
		{
			puts("1");
			return 0;
		}
	}
	sort(a+1,a+n+1);
	ll lst=m,now=0,lnum=a[1],rnum=a[n];
	for(int i=1;i<n;i++)
	{
		now++;
		if(a[i+1]==a[i])continue;
		if(lst>=(a[i+1]-a[i])*now)
		{
			lst-=(a[i+1]-a[i])*now;
			lnum=a[i+1];
		}
		else
		{
			lnum+=lst/now;
			break;
		}
	}
	lst=m,now=0;
	for(int i=n;i>=2;i--)
	{
		now++;
		if(a[i-1]==a[i])continue;
		if(lst>=(a[i]-a[i-1])*now)
		{
			lst-=(a[i]-a[i-1])*now;
			rnum=a[i-1];
		}
		else
		{
			rnum-=lst/now;
				break;
		}
	}
	printf("%lld\n",rnum-lnum);
	return 0;
}