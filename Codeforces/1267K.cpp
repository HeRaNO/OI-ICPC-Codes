#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=2e6+10;
const int INF=INT_MAX,MOD=1e9+7;
const ll llINF=~(1ll<<63);

int a[50];
ll num[25];
ll sum[25];
ll fac[25];

int main()
{
	int t;
	fac[0]=1;
	for(ll i=1;i<=23;i++)fac[i]=fac[i-1]*i;
	scanf("%d",&t);
	while(t--)
	{
		ll n,i;
		scanf("%lld",&n);
		memset(num,0,sizeof(num));
		memset(sum,0,sizeof(sum));
		for(i=2;n;i++)
		{
			num[n%i]++;
			n/=i;
		}
		sum[0]=num[0];
		for(int j=1;j<=20;j++)
			sum[j]=sum[j-1]+num[j];
		ll ans=1;
		for(int j=2;j<i;j++)
			ans*=(sum[j-1]-j+2);
		for(int j=0;j<i;j++)
			ans/=fac[num[j]];
		if(num[0])
		{
			ll res=1;
			num[0]--;
			for(int j=2;j<i-1;j++)
			res*=(sum[j-1]-j+1);
			for(int j=0;j<i-1;j++)
			res/=fac[num[j]];
			printf("%lld\n",ans-res-1);
		}
		else printf("%lld\n",ans-1);
	}
	return 0;
}