#include <cstdio>
using namespace std;

bool f[201][10000] = {false};
int a[201];
int i, j, k;
int n, sum;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	f[0][0] = true;
	for (i = 1; i <= n; i++)
		for (j = n / 2; j >= 0; j--)
			for (k = 40 * j; k >= 0; k--)
				if (f[j][k]) f[j + 1][k + a[i]] = true;
	for (i = sum / 2; i >= 0; i--)
	{
		if (f[n / 2][i])
		{
			printf("%d %d", i, sum - i);
			return 0;
		}
	}
	return 0;
}
