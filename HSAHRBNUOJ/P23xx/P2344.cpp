#include <cstdio>
#include <cstring>
#define MAXN 70
#define MAXK 1100
using namespace std;

int n, beginlevel, maxlevel;
bool dp[MAXN][MAXK];
int diff[MAXN];
int ans;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	memset(dp, false, sizeof(dp));
	scanf("%d %d %d", &n, &beginlevel, &maxlevel);
	for (int i = 1; i < n; i++)
		scanf("%d", &diff[i]);
	dp[0][beginlevel] = true;
	for (int i = 1; i < n; i++)
	{
		for (int k = maxlevel; k >= diff[i]; k--)
			if (dp[i - 1][k - diff[i]])
				dp[i][k] = true;
		for (int k = 0; k <= maxlevel - diff[i]; k++)
			if (dp[i - 1][k + diff[i]])
				dp[i][k] = true;
	}
	for (int i = maxlevel; ~i; i--)
		if (dp[n - 1][i])
		{
			printf("%d\n", i);
			return 0;
		}
	printf("-1\n");
	return 0;
}
