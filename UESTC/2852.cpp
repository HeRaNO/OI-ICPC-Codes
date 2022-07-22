#include <cstdio>
#define MAXN 1000005

int prime[MAXN], lst[MAXN], tot;
bool not_prime[MAXN];

void init(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!not_prime[i]) prime[++tot] = i;
		lst[i] = prime[tot];
		for (int j = 1; i * prime[j] <= n; j++)
		{
			not_prime[i * prime[j]] = true;
			if (!(i % prime[j])) break;
		}
	}
	return ;
}

int main()
{
	init(1'000'000);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", lst[n] << 1);
	}
	return 0;
}