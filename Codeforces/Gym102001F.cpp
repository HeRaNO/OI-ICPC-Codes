#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1e6+10,INF=0x7fffffff;

ll a[MAXN],b[MAXN];
ll mx[MAXN];
ll ans[MAXN],cnt;


int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	ll sum=0,num=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum<=m)
			num++;
		else break;
	}
	for(int i=num;i>=1;i--)mx[i]=max(mx[i+1],b[i]);
	sum=0;
	for(int i=1;i<=num;i++)
	{
		sum+=b[i];
		if(sum>m)
		{
			cout<<"0";
			return 0;
		}
	}
	sum=0;
	ll pa=1,ballon=0,ta=0;
	bool yes=false;
	for(int i=1;i<=num;i++)
	{
		while(1)
		{
			sum+=b[i];
			if(sum>m)
			{
				yes=true;
				break;
			}
			while(a[pa]+ta<=sum&&pa<=n)
			{
				ballon++;
				ta+=a[pa++];
			}
			if(b[i]==mx[i]&&ballon)
			{
				ballon--;
				ans[++cnt]=sum;
				continue;
			}
			break;
		}
	}
	if(yes)
	{
		printf("%lld\n",cnt);
		for(int i=1;i<=cnt;i++)
			printf("%lld ",ans[i]);
	}
	else printf("-1");
	return 0;
}

