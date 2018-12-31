//Code By HeRaNO
#include <cstdio>
#define MAXN 11
using namespace std;
int table[MAXN][MAXN];
int n, cnt;
int main()
{
	scanf("%d", &n);
	for (int a = 2; a <= 2 * n; a++)
	{
		if (a % 2)
		{
			for (int i = 1; i <= n; i++)
				if (a - i >= 1 && a - i <= n) table[i][a - i] = ++cnt;
		}
		else
		{
			for (int i = n; i; i--)
				if (a - i >= 1 && a - i <= n) table[i][a - i] = ++cnt;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", table[i][j]);
		printf("\n");
	}
	return 0;
}
