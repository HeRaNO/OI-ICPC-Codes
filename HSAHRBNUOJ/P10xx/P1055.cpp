#include <cstdio>
#include <cstring>
#define MAXN 110
using namespace std;

long long dp[MAXN][MAXN];
int n, m;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

int dfs(int a, int b)
{
	if (a == b) return dp[a][b] = 1;
	if (dp[a][b]) return dp[a][b];
	dp[a][b] = 0x7f7f7f7f;
	for (int i = 1; i < a; i++) dp[a][b] = mymin(dp[a][b], dfs(i, b) + dfs(a - i, b));
	for (int i = 1; i < b; i++) dp[a][b] = mymin(dp[a][b], dfs(a, i) + dfs(a, b - i));
	return dp[a][b];
}

int main()
{
	scanf("%d %d", &n, &m);
	printf("%d\n", dfs(n, m));
	return 0;
}
