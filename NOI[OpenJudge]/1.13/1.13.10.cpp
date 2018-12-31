//Code By HeRaNO
#include <cstdio>
#include <algorithm>
#define MAXN 100100
using namespace std;

long long phi[MAXN];
long long prime[MAXN];
long long ans = 2;
bool not_prime[MAXN];
int tot, cnt;
int x, y;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void pre_work(int n)
{
	int i, j;
	phi[1] = 1;
	not_prime[1] = true;
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
	scanf("%d %d", &x, &y);
	if (x > y) swap(x, y);
	pre_work(mymax(x, y));
	for (int i = x; i <= y; i++)
		if (!not_prime[i]) cnt++;
	printf("%d\n", cnt);
	return 0;
}
