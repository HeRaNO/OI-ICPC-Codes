#include <cstdio>
#define MAXN 21

int C[MAXN][MAXN], n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++) printf("%d ", C[i][j]);
		printf("%d\n", C[i][i]);
	}
	return 0;
}
