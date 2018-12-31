#include <cstdio>
#define MAXN 10000010
using namespace std;

long long phi[MAXN];
long long prime[MAXN];
long long f[MAXN];
unsigned long long ans = 0;
bool not_prime[MAXN];
int tot;
int n;

void per_work()
{
	int i, j;
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!not_prime[i])
		{
			prime[++tot] = i;
			phi[i] = i - 1;
		}
		for (j = 1; i * prime[j] <= n; j++)
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
	for (int i = 1; i <= n; i++)
		f[i] = f[i - 1] + phi[i];
	return ;
}

int main()
{
	scanf("%d", &n);
	per_work();
	for (int i = 1; i <= tot; i++)
		ans += f[n / prime[i]] * 2 - 1;
	printf("%lld", ans);
	return 0;
}