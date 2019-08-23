#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
typedef long long ll;

template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
	return ;
}

int n;
ll a[MAXN],k;
int main()
{
	int t;read(t);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+n+1,greater<ll>());
		priority_queue<ll> pq;
		ll ans=k;
		ll num=1;
		for(int i=1;i<=n;i++)
		{
			if(num==0)
			{
				ll temp=pq.top();
				pq.pop();
				ans+=k-temp;
				num++;
			}
			ans+=a[i];
			num+=a[i]/k;
			num--;
			pq.push(a[i]%k);
		}
		printf("%lld\n",ans);
	}
	return 0;
}