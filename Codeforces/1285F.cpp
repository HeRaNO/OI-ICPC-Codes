#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const int S=100000;

int n,pt,tot,s[MAXN],prime[MAXN],mu[MAXN],cnt[MAXN];
long long ans;
bool a[MAXN],not_prime[MAXN];
vector <int> d[MAXN];

inline void init()
{
	mu[1]=1;
	for (int i=1;i<=S;i++) d[i].push_back(1);
	for (int i=2;i<=S;i++)
	{
		for (int j=i;j<=S;j+=i) d[j].push_back(i);
		if (!not_prime[i])
		{
			prime[++tot]=i;
			mu[i]=-1;
		}
		for (int j=1;i*prime[j]<=S;j++)
		{
			not_prime[i*prime[j]]=true;
			if (!(i%prime[j]))
			{
				mu[i*prime[j]]=0;
				break;
			}
			mu[i*prime[j]]=-mu[i];
		}
	}
	return ;
}

inline int get(int x)
{
	int r=0;
	for (auto i:d[x]) r+=cnt[i]*mu[i];
	return r;
}

inline void add(int x,int v){for (auto i:d[x]) cnt[i]+=v;return ;}

int main()
{
	init();
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		if (a[x]) ans=max(ans,(long long)x);
		a[x]=true;
	}
	for (int g=1;g<=S;g++)
	{
		for (int i=S/g;i;i--)
		{
			if (!a[i*g]) continue;
			int cnt=get(i);
			while (cnt&&pt)
			{
				if (__gcd(s[pt],i)==1)
				{
					ans=max(ans,1LL*s[pt]*i*g);
					--cnt;
				}
				add(s[pt--],-1);
			}
			add(s[++pt]=i,1);
		}
		while (pt) add(s[pt--],-1);
	}
	printf("%lld\n",ans);
	return 0;
}