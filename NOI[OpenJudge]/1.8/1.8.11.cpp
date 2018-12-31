//Code By HeRaNO
#include <cstdio>
#define MAXN 110
using namespace std;

int n, m;
int a[MAXN][MAXN];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= m; i++)
	{
		for (int j = n; j; j--)
			printf("%d ", a[j][i]);
		printf("\n");
	}
	return 0;
}
