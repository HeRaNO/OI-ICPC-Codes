//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXN 100010
using namespace std;

long long prime[MAXN];
long long ans = 2;
bool not_prime[MAXN], first = true;
int tot;
int n, m;

void pre_work(int n)
{
	memset(not_prime, false, sizeof(not_prime));
	int i, j;
	not_prime[1] = true;
	for (int i = 2; i <= n; i++)
	{
		if (!not_prime[i]) prime[++tot] = i;
		for (j = 1; i * prime[j] <= n; j++)
			not_prime[i * prime[j]] = true;
	}
	return ;
}

bool work(int n)
{
	int ne = 0;
	while (n)
	{
		ne = ne * 10 + n % 10;
		n /= 10;
	}
	if (!not_prime[ne]) return true;
	else return false;
}

int main()
{
	pre_work(MAXN);
	scanf("%d %d", &n, &m);
	for (int i = n; i <= m; i++)
	{
		if (!not_prime[i])
			if (work(i))
			{
				if (first)
				{
					first = false;
					printf("%d", i);
				}
				else printf(",%d", i);
			}
	}
	if (first) printf("No");
	printf("\n");
	return 0;
}
