#include <cstdio>
#include <cstring>
#define MAXN 210
using namespace std;

long long a[MAXN], dp[MAXN];
int n;

inline long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

int main()
{
	memset(dp, 0x7f, sizeof dp);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	dp[1] = 0LL;
	for (int i = 2; i <= n; i++)
	{
		if (a[i - 1] + 1 == a[i] && dp[i] != 0x7f7f7f7f) dp[i] = dp[i - 1] + 1;
		for (int j = 1; j < i; j++)
		{
			long long sum = 1LL;
			for (int k = 1; j + k < i; k++)
			{
				sum <<= 1LL;
				if (sum + a[j] >= a[i]) dp[i] = mymin(dp[i], dp[j + k] + k + 1);
			}
		}
	}
	if (dp[n] == 9187201950435737473LL) puts("-1");
	else printf("%lld\n", dp[n]);
	return 0;
}
