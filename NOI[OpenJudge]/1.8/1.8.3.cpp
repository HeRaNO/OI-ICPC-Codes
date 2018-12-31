//Code By HeRaNO
#include <cstdio>
#define MAXN 101
using namespace std;

int a[MAXN][MAXN];
int sum;
int n, m;

void work(int aa, bool flag)
{
	if (flag)
	{
		for (int i = 1; i <= aa; i++)
			sum += a[1][i];
	}
	else
	{
		for (int i = 1; i <= aa; i++)
			sum += a[i][1];
	}
	printf("%d\n", sum);
	return ;
}

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	if (m == 1 && n == 1)
	{
		printf("%d\n", a[1][1]);
		return 0;
	}
	else if (m == 1 || n == 1)
	{
		work(m == 1 ? n : m, m == 1);
		return 0;
	}
	for (int i = 1; i <= n; i++)
		sum = sum + a[1][i] + a[m][i];
	for (int i = 1; i <= m; i++)
		sum = sum + a[i][1] + a[i][n];
	sum = sum - a[1][1] - a[1][n] - a[m][1] - a[m][n];
	printf("%d\n", sum);
	return 0;
}
