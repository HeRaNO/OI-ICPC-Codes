#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 2005

int N, a[MAXN][MAXN], dp[MAXN][MAXN];

inline int Jury()
{
	memset(dp, 0x7f, sizeof dp);
	dp[1][1] = 0;
	for (int i = 2; i <= N; i++)
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = std::min((long long)dp[i][j], (long long)dp[i - 1][j] + a[i - 1][i]);
			dp[i][i - 1] = std::min((long long)dp[i][i - 1], (long long)dp[i - 1][j] + a[j][i]);
			dp[i][i] = std::min((long long)dp[i][i], (long long)dp[i - 1][j] + a[i - 1][i] + a[j][i]);
		}
	int ans = ~(1 << 31);
	for (int i = 1; i <= N; i++)
		ans = std::min(ans, dp[N][i]);
	return ans;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i < N; i++)
		for (int j = i + 1; j <= N; j++)
			scanf("%d", &a[i][j]);
	printf("%d\n", Jury());
	return 0;
}