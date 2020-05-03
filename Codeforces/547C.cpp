#include <bits/stdc++.h>
#define MAXN 200005
#define MAXM 500005
using namespace std;

int n,x,q,all,a[MAXN],mu[MAXM],prime[MAXM],cnt[MAXM],vis[MAXN],tot;
bool not_prime[MAXM];
vector <int> v[MAXM];
long long ans;

inline void LinearShaker(int n)
{
	mu[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i])
		{
			prime[++tot]=i;
			mu[i]=-1;
		}
		for (int j=1;i*prime[j]<=n;j++)
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
	for (int i=2;i<=n;i++)
		for (int j=i;j<=n;j+=i)
			v[j].push_back(i);
	return ;
}

inline void C(int x,int t)
{
	x=a[x];all+=t;
	for (auto p:v[x]) cnt[p]+=t;
	return ;
}

inline int Q(int x)
{
	x=a[x];int res=0;
	for (auto p:v[x]) res+=mu[p]*cnt[p];
	return res;
}

int main()
{
	LinearShaker(500000);
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	while (q--)
	{
		scanf("%d",&x);
		if (a[x]==1)
		{
			if (vis[x]) all--,ans-=all;
			else ans+=all,all++;
			printf("%lld\n",ans);vis[x]^=1;
			continue;
		}
		if (vis[x])
		{
			ans-=all+Q(x);
			C(x,-1);
		}
		else
		{
			ans+=all+Q(x);
			C(x,1);
		}
		printf("%lld\n",ans);vis[x]^=1;
	}
	return 0;
}