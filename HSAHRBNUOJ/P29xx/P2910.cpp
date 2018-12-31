#include <cstdio>
#include <cstring>
#define MAXN 1010
using namespace std;

int dp[MAXN];
int n, c;
int a[MAXN][MAXN];

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	while (~scanf("%d", &c))
	{
		memset(dp, 0x7f, sizeof(dp));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n + 1; j++)
				scanf("%d", &a[i][j]);
		dp[1] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n + 1; j++)
				dp[j] = mymin(dp[j], dp[i] + c + a[i][j]);
		printf("%d\n", dp[n + 1]);
	}
	return 0;
}
