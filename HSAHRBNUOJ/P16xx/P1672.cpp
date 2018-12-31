#include <cstdio>
#include <climits>
#define MAXN 110
using namespace std;

int n, m;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];
int left, right, middle;
int ans;

int mymin(int a, int b)
{
	return a > b ? a : b;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

bool check(int used)
{
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			dp[i][j] = INT_MIN;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= used / a[i]; k++)
				if (k <= j) dp[i][j] = mymax(dp[i][j], dp[i - 1][j - k] + (used - a[i] * k) / b[i]);
	return dp[n][m] >= m;
}

int main()
{
	scanf("%d %d", &n, &m);
	left = m * 2 / n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a[i], &b[i]);
		right = mymax(right, mymax(a[i], b[i]));
	}
	right *= m;
	while (left <= right)
	{
		middle = (left + right) >> 1;
		if (check(middle)) right = middle - 1, ans = middle;
		else left = middle + 1;
	}
	printf("%d\n", ans);
	return 0;
}
