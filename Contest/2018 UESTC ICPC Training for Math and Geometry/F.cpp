#include <cstdio>
using namespace std;

int prime[22001], tot, k;
bool not_prime[249440], flag;
double f[249440];

int main()
{
	for (int i = 2; i <= 249439; i++)
	{
		if (!not_prime[i]) prime[++tot] = i;
		for (int j = 1; i * prime[j] <= 249439; j++)
		{
			not_prime[i * prime[j]] = true;
			if (!(i % prime[j])) break;
		}
	}
	prime[1] = 3;
	prime[2] = 4;
	f[1] = f[2] = 1;
	for (int i = 3; i <= 249439; i++)
	{
		if (flag)
		{
			f[i] = f[i - 1] + f[i - 2] / 10;
			flag = false;
		}
		else f[i] = f[i - 1] + f[i - 2];
		if (f[i] > 1e9)
		{
			f[i] /= 10;
			flag = true;
		}
	}
	while (~scanf("%d", &k)) printf("%d\n", (int)f[prime[k]]);
	return 0;
}
