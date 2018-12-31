#include <cstdio>
#define MAXN 1025
using namespace std;

long long dp[MAXN][MAXN];
long long ans;
long long n, r, g, b, t;

long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%lld %lld %lld %lld %lld", &n, &r, &g, &b, &t);
	for (int i = 0; i <= n; i++) //i为蓝法师塔
		for (int j = 0; j <= n - i; j++) //j为绿法师塔
		{
			if (i) dp[i][j] = mymax(dp[i][j], dp[i - 1][j] + g * j * (t + b * (i - 1))); //只有走出塔才生效
			if (j) dp[i][j] = mymax(dp[i][j], dp[i][j - 1] + g * (j - 1) * (t + b * i));
			ans = mymax(ans, dp[i][j] + (n - i - j) * (g * j + r) * (t + i * b));
		}
	printf("%lld\n", ans);
	return 0;
}
