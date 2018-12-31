#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 500
using namespace std;

int n, k, t, x = 1;
long long dp[MAXN][MAXN];
int a[MAXN];

int main()
{
	scanf("%d %d", &k, &n);
	dp[0][0] = 1LL;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j + i <= n; j++)
			for (int r = 0; r < k; r++)
				dp[i + j][r + 1] += dp[j][r];
	printf("%lld\n", dp[n][k]);
	scanf("%d", &t);
	if (!t)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= t; i++) scanf("%d", &a[i]);
	sort(a + 1, a + t + 1);
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1LL;
	for (int i = 1; i <= n; i++)
	{
		if (i == a[x])
		{
			x++;
			continue;
		}
		for (int j = 0; j + i <= n; j++)
			for (int r = 0; r < k; r++)
				dp[i + j][r + 1] += dp[j][r];
	}
	printf("%lld\n", dp[n][k]);
	return 0;
}
