#include <cstdio>
#include <cstring>
#define MAXN 100
using namespace std;

int dp[MAXN], c[11], n;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	memset(dp, 0x7f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= 10; i++) scanf("%d", &c[i]);
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= 10 && i + j <= n; j++)
			dp[i + j] = mymin(dp[i + j], dp[i] + c[j]);
	printf("%d\n", dp[n]);
	return 0;
}
