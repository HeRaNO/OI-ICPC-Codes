#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int T,prime[MAXN],mu[MAXN],tot;
bool not_prime[MAXN];
long long n;

inline void LinearShaker(int n)
{
	mu[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]){prime[++tot]=i;mu[i]=-1;}
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
	return ;
}

inline int getMu(long long n)
{
	int ret=1;
	if (n<=1000000) return mu[n];
	for (int i=1;1LL*prime[i]*prime[i]<=n&&i<=tot;i++)
		if (!(n%prime[i]))
		{
			n/=prime[i];
			if (!(n%prime[i])) return 0;
			ret=-ret;
		}
	if (n!=1) ret=-ret;
	return ret;
}

int main()
{
	LinearShaker(1000000);
	scanf("%d",&T);
	while (T--) scanf("%lld",&n),printf("%d\n",getMu(n));
	return 0;
}