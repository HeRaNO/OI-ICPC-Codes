#include <cstdio>
#define MAXN 5010
#define MOD 1000000007LL
using namespace std;

int n, A, B, k, kk;
long long dp[2][MAXN];

int main()
{
	scanf("%d %d %d %d", &n, &A, &B, &k);
	for (int i = A; i <= n; i++) dp[0][i] = 1LL;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
		{
			dp[i & 1][j] = dp[i & 1][j - 1];
			if (j == B) continue;
			//if ((j+B)&1)
			kk = (j + B) >> 1;
			//else kk=((j+B)>>1)-1;
			if (j < B)
			{
				if ((B + j) % 2 == 0) kk--;
				dp[i & 1][j] = (dp[i & 1][j] + dp[(i - 1) & 1][kk] - dp[(i - 1) & 1][j] + dp[(i - 1) & 1][j - 1]) % MOD;
			}
			else
			{
				//if ((j+B)&1==0) kk++;
				dp[i & 1][j] = (dp[i & 1][j] + dp[(i - 1) & 1][n] - dp[(i - 1) & 1][kk] - dp[(i - 1) & 1][j] + dp[(i - 1) & 1][j - 1] + MOD) % MOD;
			}
		}
	printf("%lld\n", dp[k & 1][n]);
	return 0;
}
