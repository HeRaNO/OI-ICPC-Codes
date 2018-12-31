//Code By HeRaNO
#include <cstdio>
#define MAXN 10010
using namespace std;

long long phi[MAXN];
long long prime[MAXN];
long long ans = 2;
bool not_prime[MAXN];
int tot;
int n;
bool out = false;

void pre_work()
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
	pre_work();
	for (int i = 2; i <= n - 2; i++)
	{
		if (!not_prime[i] && !not_prime[i + 2])
		{
			out = true;
			printf("%d %d\n", i, i + 2);
		}
	}
	if (!out) printf("empty\n");
	return 0;
}
