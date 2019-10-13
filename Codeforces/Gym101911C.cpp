#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF=~(1<<31),MAXN=3e5+10;

ll a[MAXN];
priority_queue <ll,vector<ll>,greater<ll> > pq;

int main()
{
	int n,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i==1)
		{
			ll tmp=a[i];
			while(!(tmp&1))
				tmp>>=1;
			b=tmp;
		}
		else
		{
			if(a[i]%b)
			{
				return puts("-1"),0;
			}
			else
			{
				int tmp=a[i]/b;
				while(tmp>1&&tmp%2==0)tmp>>=1;
				if(tmp>1)return puts("-1"),0;
			}
		}
		pq.push(a[i]);
	}
	int ans=0;
	while(pq.size()>1)
	{
		ll u=pq.top();
		pq.pop();
		if(u==pq.top())
		{
			pq.pop();
			pq.push(u<<1);
		}
		else
		{
			ans++;
			pq.push(u<<1);
		}
	}
	printf("%d",ans);
	return 0;
}