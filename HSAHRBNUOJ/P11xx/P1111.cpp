#include <cstdio>
#define MAXN 11000010
using namespace std;

long long prime[MAXN];
bool not_prime[MAXN];
int tot;
int n;

void per_work()
{
	int i, j;
	for (int i = 2; i <= n; i++)
	{
		if (!not_prime[i])
			prime[++tot] = i;
		for (j = 1; i * prime[j] <= n; j++)
		{
			not_prime[i * prime[j]] = true;
			if (!(i % prime[j]))
				break;
		}
	}
	return ;
}

int main()
{
	scanf("%d", &n);
	per_work();
	printf("%d\n", tot);
	for (int i = 1; i < tot; i++)
		printf("%d ", prime[i]);
	printf("%d\n", prime[tot]);
	return 0;
}
