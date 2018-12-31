#include <cstdio>
using namespace std;

int V, n, C;
int dp[10010];
int v[10010], c[10010];
int i, j;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d %d %d", &V, &n, &C);
	for (i = 1; i <= n; i++)
		scanf("%d %d", &v[i], &c[i]);
	for (i = 1; i <= n; i++)
		for (j = C; j >= c[i]; j--)
			dp[j] = mymax(dp[j], dp[j - c[i]] + v[i]);
	for (i = 1; i <= C; i++)
		if (dp[i] >= V)
		{
			printf("%d", C - i);
			return 0;
		}
	printf("Impossible");
	return 0;
}
