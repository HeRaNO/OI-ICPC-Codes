#include <cstdio>
#include <cstring>
#define MAXN 110
#define MAXM 10
#define MOD 10
using namespace std;

int n, m;
int a[MAXN], dp1[MAXN][MAXM], dp2[MAXN][MAXM], sum[MAXN];
int ans1 = 0x7f7f7f7f, ans2;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for (int i = 1; i <= (n << 1); i++) sum[i] = sum[i - 1] + a[i];
	for (int l = 0; l < n; l++)
	{
		memset(dp1, 0, sizeof dp1);
		memset(dp2, 0x7f, sizeof dp2);
		for (int i = 1; i <= n; i++)
		{
			dp1[i + l][1] = dp2[i + l][1] = ((sum[i + l] - sum[l]) % MOD + MOD) % MOD;
			for (int j = 2; j <= mymin(i, m); j++)
				for (int k = j - 1; k < i; k++)
				{
					dp1[i + l][j] = mymax(dp1[i + l][j], dp1[k + l][j - 1] * (((sum[i + l] - sum[k + l]) % MOD + MOD) % MOD));
					dp2[i + l][j] = mymin(dp2[i + l][j], dp2[k + l][j - 1] * (((sum[i + l] - sum[k + l]) % MOD + MOD) % MOD));
				}
		}
		ans1 = mymin(ans1, dp2[n + l][m]);
		ans2 = mymax(ans2, dp1[n + l][m]);
	}
	printf("%d\n%d\n", ans1, ans2);
	return 0;
}
