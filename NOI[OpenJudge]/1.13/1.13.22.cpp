//Code By HeRaNO
#include <cstdio>
#define MAXN 100
using namespace std;

int prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int prime_pos = 1;
int ans[MAXN][2];
int n;
bool first = true;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 25; i++)
		if (n == prime[i])
		{
			printf("%d\n", n);
			return 0;
		}
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}
	while (n > 1)
	{
		if (n % prime[prime_pos] == 0)
		{
			ans[prime_pos][0] = prime[prime_pos];
			ans[prime_pos][1]++;
			n /= prime[prime_pos];
		}
		else prime_pos++;
	}
	for (int i = 1; i <= prime_pos; i++)
	{
		if (!ans[i][0]) continue;
		else
		{
			if (first)
			{
				if (ans[i][1] != 1)
					printf("%d^%d", ans[i][0], ans[i][1]);
				else printf("%d", ans[i][0]);
				first = false;
			}
			else
			{
				if (ans[i][1] != 1)
					printf("*%d^%d", ans[i][0], ans[i][1]);
				else printf("*%d", ans[i][0]);
			}
		}
	}
	printf("\n");
	return 0;
}
