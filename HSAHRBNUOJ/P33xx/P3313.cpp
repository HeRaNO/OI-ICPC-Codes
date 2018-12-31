#include <cstdio>
#define MAXN 210
using namespace std;

int n, q[MAXN];
int a[MAXN][MAXN];
bool dp[MAXN][MAXN];
bool first = true;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++) q[i] = q[i + n] = i;
	for (int i = 1; i < n * 2; i++) dp[i][i + 1] = true;
	for (int i = n * 2 - 2; i; i--)
		for (int j = i + 2; j <= 2 * n; j++)
			for (int k = i + 1; k < j; k++)
				if (dp[i][k] && dp[k][j] && (a[q[i]][q[k]] || !a[q[k]][q[j]]))
				{
					dp[i][j] = true;
					break;
				}
	for (int i = 1; i <= n; i++)
		if (dp[i][i + n])
		{
			if (first)
			{
				printf("%d", i);
				first = false;
			}
			else printf(" %d", i);
		}
	puts("");
	return 0;
}
