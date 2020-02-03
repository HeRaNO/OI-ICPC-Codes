#include <cstdio>
using namespace std;

bool f[2010][2010];
int h[101];
int i, j, k;
int n, sum;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &h[i]);
		sum += h[i];
	}
	f[0][0] = true;
	for (i = 1; i <= n; i++)
		for (j = sum / 2; j >= 0; j--)
			for (k = sum / 2; k >= 0; k--)
			{
				if (f[j][k])
				{
					f[j][k + h[i]] = true;
					f[j + h[i]][k] = true;
				}
			}
	for (i = sum; i >= 1; i--)
		if (f[i][i])
		{
			printf("%d", i);
			return 0;
		}
	printf("Impossible");
	return 0;
}