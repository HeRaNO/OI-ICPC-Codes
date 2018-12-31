#include <cstdio>
#include <climits>
#define MAXN 21
#define MAXM 510
using namespace std;

int n, m;
int a[MAXN][MAXM];
int sum[MAXM], dp[MAXM];
int ans = INT_MIN;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

void dpit(int pos)
{
	for (int i = 1; i <= m; i++) sum[i] += a[pos][i];
	int maxv[2] = {INT_MIN, INT_MIN};
	for (int i = 1; i <= m; i++)
	{
		dp[i] = sum[i];
		dp[i] += mymax(0, maxv[(i & 1) ^ 1]);
		maxv[i & 1] = mymax(maxv[i & 1], dp[i]);
		ans = mymax(ans, dp[i]);
	}
	for (int i = pos + 1; i <= n; i += 2) dpit(i);
	for (int i = 1; i <= m; i++) sum[i] -= a[pos][i];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++) dpit(i);
	printf("%d\n", ans);
	return 0;
}
