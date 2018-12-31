#include <cstdio>
#include <cstring>
#define MAXS 110
#define MAXN 10010
#define MAXT 10010
using namespace std;

struct lesson
{
	int mi;
	int last;
	int ai;
};

lesson a[MAXS];
int T, s, n, x, y;
int dp[MAXT][MAXS];
int need[MAXS];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int dfs(int dep, int ability)
{
	if (dep > T) return -1;
	if (dep == T) return 0;
	if (dp[dep][ability] != -1) return dp[dep][ability];
	dp[dep][ability] = 0;
	for (int i = 1; i <= s; i++)
	{
		if (a[i].mi < dep) continue;
		dp[dep][ability] = mymax(dp[dep][ability], dfs(a[i].mi + a[i].last, a[i].ai));
	}
	dp[dep][ability] = mymax(dp[dep][ability], dfs(dep + 1, ability));
	dp[dep][ability] = mymax(dp[dep][ability], dfs(dep + need[ability], ability) + 1);
	return dp[dep][ability];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	memset(need, 0x7f, sizeof(need));
	scanf("%d %d %d", &T, &s, &n);
	for (int i = 1; i <= s; i++)
		scanf("%d %d %d", &a[i].mi, &a[i].last, &a[i].ai);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		need[x] = mymin(need[x], y);
	}
	for (int i = 1; i < MAXS; i++)
		need[i] = mymin(need[i], need[i - 1]);
	printf("%d\n", dfs(0, 1));
	return 0;
}
