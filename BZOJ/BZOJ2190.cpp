#include <cstdio>
#define MAXN 40010
using namespace std;

unsigned long long phi[MAXN];
unsigned long long prime[MAXN];
unsigned long long ans = 2;
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
	return ;
}

int main()
{
	scanf("%d", &n);
	per_work();
	if (n <= 1)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 2; i < n; i++) ans += phi[i];
	printf("%lld\n", ans * 2 - 1);
	return 0;
}