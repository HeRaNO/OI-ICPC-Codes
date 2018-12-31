#include <cstdio>
#include <algorithm>
#define MAXN 2010
using namespace std;

int n, m;
int line[MAXN], row[MAXN];
int dp[MAXN][MAXN];

int mymin(int a, int b)
{
	return a < b ? a : b;
}

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; i++) scanf("%d", &line[i]);
	for (int i = 1; i < m; i++) scanf("%d", &row[i]);
	sort(line + 1, line + n, cmp);
	sort(row + 1, row + m, cmp);
	for (int i = 1; i < n; i++)
		dp[i][0] = dp[i - 1][0] + line[i];
	for (int i = 1; i < m; i++)
		dp[0][i] = dp[0][i - 1] + row[i];
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			dp[i][j] = mymin(dp[i - 1][j] + line[i] * (j + 1), dp[i][j - 1] + row[j] * (i + 1));
	printf("%d\n", dp[n - 1][m - 1]);
	return 0;
}
