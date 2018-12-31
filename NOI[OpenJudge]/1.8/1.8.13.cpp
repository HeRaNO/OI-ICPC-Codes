//Code By HeRaNO
#include <cmath>
#include <cstdio>
#define MAXN 101
using namespace std;

double a[MAXN][MAXN];
int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%lf", &a[i][j]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 || i == n || j == 1 || j == m) printf("%.0lf ", a[i][j]);
			else printf("%.0lf ", round((a[i + 1][j] + a[i][j + 1] + a[i - 1][j] + a[i][j - 1] + a[i][j]) / 5.0));
		}
		printf("\n");
	}
	return 0;
}
