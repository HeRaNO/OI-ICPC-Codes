//Code By HeRaNO
#include <cstdio>
#define MAXN 110
using namespace std;

int n, m, k;
int A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &A[i][j]);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= k; j++)
			scanf("%d", &B[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			for (int p = 1; p <= m; p++)
				C[i][j] += A[i][p] * B[p][j];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}
	return 0;
}
