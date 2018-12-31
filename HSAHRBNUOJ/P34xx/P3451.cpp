#include <cstdio>
#define MAXN 1010
#define MAXV 10010
#define MOD 1000000007LL
using namespace std;

int n, V;
int c[MAXN];
long long dp[2][2][MAXV], ans;

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	//freopen("backpack.in","r",stdin);freopen("backpack.out","w",stdout);
	read(n);
	read(V);
	for (int i = 1; i <= n; i++) read(c[i]);
	dp[0][0][0] = 1LL;
	for (int i = 1; i <= n; i++)
	{
		for (int j = V; j >= c[i]; j--)
		{
			dp[1][1][j] = (dp[1][1][j] + dp[1][1][j - c[i]] + dp[1][0][j] + dp[0][1][j - c[i]]) % MOD;
			dp[1][0][j] = (dp[1][0][j] + dp[1][0][j - c[i]] + dp[0][0][j - c[i]]) % MOD;
			dp[0][1][j] = (dp[0][1][j] + dp[0][1][j - c[i]] + dp[0][0][j]) % MOD;
			dp[0][0][j] = (dp[0][0][j] + dp[0][0][j - c[i]]) % MOD;
		}
		for (int j = c[i] - 1; ~j; j--)
		{
			dp[1][1][j] = (dp[1][1][j] + dp[1][0][j]) % MOD;
			dp[0][1][j] = (dp[0][1][j] + dp[0][0][j]) % MOD;
		}
	}
	for (int i = 1; i <= V; i++) ans = (ans + dp[1][1][i]) % MOD;
	printf("%lld\n", ans);
	return 0;
}
