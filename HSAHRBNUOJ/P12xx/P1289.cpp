#include <cstdio>
#include <climits>
#define MAXM 13
#define MAXP 1010
using namespace std;

int need[MAXM];
int dp[MAXM][MAXP];
int n, m, hire, fire, salary;
int t;
int ans = INT_MAX;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%d", &n);
	scanf("%d %d %d", &hire, &salary, &fire);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &need[i]);
		m = mymax(m, need[i]);
	}
	for (int i = need[1]; i <= m; i++) dp[1][i] = i * (hire + salary);
	for (int i = 2; i <= n; i++)
		for (int j = need[i]; j <= m; j++)
		{
			dp[i][j] = INT_MAX;
			for (int k = need[i - 1]; k <= m; k++)
			{
				if (j < k) t = dp[i - 1][k] + j * salary + (k - j) * fire;
				else t = dp[i - 1][k] + k * salary + (j - k) * (hire + salary);
				dp[i][j] = mymin(dp[i][j], t);
			}
		}
	for (int i = need[n]; i <= m; i++)
		ans = mymin(dp[n][i], ans);
	printf("%d\n", ans);
	return 0;
}
