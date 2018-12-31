//Code By HeRaNO
#include <cstdio>
#include <climits>
#define MAXN 110
using namespace std;

int a[MAXN][MAXN], b[MAXN][MAXN];
int n, m, r, s;
int best = INT_MAX, besti, bestj;
int now;

int myabs(int a)
{
	return a > 0 ? a : -a;
}

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	scanf("%d %d", &r, &s);
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= s; j++)
			scanf("%d", &b[i][j]);
	for (int i = 1; i <= m - r + 1; i++)
		for (int j = 1; j <= n - s + 1; j++)
		{
			now = 0;
			for (int p = i; p <= i + r - 1; p++)
				for (int q = j; q <= j + s - 1; q++)
					now += myabs(a[p][q] - b[p - i + 1][q - j + 1]);
			if (now < best)
			{
				best = now;
				besti = i;
				bestj = j;
			}
		}
	for (int i = besti; i <= besti + r - 1; i++)
	{
		for (int j = bestj; j <= bestj + s - 1; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}
