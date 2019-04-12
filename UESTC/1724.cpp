#include <cstdio>
#define MAXN 1000010

long long prime[MAXN], phi[MAXN];
bool not_prime[MAXN];
int T,n,tot;
long long ans;

inline void Linear_Shaker(int n)
{
	phi[1] = 1LL;
	for (int i = 2; i <= n; i++)
	{
		if (!not_prime[i])
		{
			prime[++tot] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; i * prime[j] <= n; j++)
		{
			not_prime[i * prime[j]] = true;
			if (!(i % prime[j]))
			{
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
	return ;
}

int main()
{
	Linear_Shaker(1000000);
	scanf("%d",&T);
	for (int q=1;q<=T;q++)
	{
		scanf("%d",&n);
		for (long long i=1;i*i<=n;i++)
			if (!(n%i))
			{
				ans+=phi[n/i]*i;
				if (i*i<n) ans+=phi[i]*(n/i);
			}
		ans-=n;
	}
	printf("%lld\n",ans);
	return 0;
}
