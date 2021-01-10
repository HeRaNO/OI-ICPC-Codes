#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int T,n,prime[MAXN], phi[MAXN], mu[MAXN];
bool not_prime[MAXN];
int tot;

inline void LinearShaker(int n)
{
	phi[1] = 1LL;
	mu[1] = 1LL;
	for (int i = 2; i <= n; i++)
	{
		if (!not_prime[i])
		{
			prime[++tot] = i;
			phi[i] = i - 1;
			mu[i] = -1;
		}
		for (int j = 1; i * prime[j] <= n; j++)
		{
			not_prime[i * prime[j]] = true;
			if (!(i % prime[j]))
			{
				mu[i * prime[j]] = 0LL;
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			mu[i * prime[j]] = -mu[i];
			phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
	return ;
}

int main()
{
	LinearShaker(1000000);
	scanf("%d",&T);
	while (T--)
	{
		int cnt=0;
		scanf("%d",&n);
		for (int i=1;i<=tot;i++)
			if (prime[i]>n) break;
			else ++cnt;
		int cnto=cnt-1;
		if (cnto&1) puts("cxy");
		else puts("-1");
	}
	return 0;
}