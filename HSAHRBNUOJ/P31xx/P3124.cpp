#include <cstdio>
#define MAXN 110
#define MAXK 310
#define MOD 1000000007LL
using namespace std;

long long dp[MAXN][MAXK][MAXN];
long long sum;
int n, k, p, T;

int main()
{
	for (int i = 1; i <= 300; i++) dp[1][i][0] = 1;
	for (int i = 2; i <= 100; i++)
		for (int j = 0; j < i; j++)
		{
			sum = 0LL;
			for (int k = 1; k <= 300; k++)
			{
				sum = (sum + dp[i - 1][k - 1][j - 1]) % MOD;
				dp[i][k][j] = (sum + dp[i - 1][k][j] * (long long)k) % MOD;
			}
		}
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d", &n, &k, &p);
		sum = 0LL;
		for (int i = 1; i <= k; i++) sum = (sum + dp[n][i][p]) % MOD;
		printf("%lld\n", sum);
	}
	return 0;
}
