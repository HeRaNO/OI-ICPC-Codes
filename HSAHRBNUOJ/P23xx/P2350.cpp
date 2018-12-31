#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 510
#define MOD 1000000
using namespace std;

int n, m;
int dp[MAXN][1 << 12];
int i;
int x1, x2, y11, y2;

void dfs(int c, int s1, int s2)
{
	if (c == n)
	{
		dp[i][s1] = (dp[i][s1] + dp[i - 1][s2]) % MOD;
		return ;
	}
	if (c + 1 <= n)
	{
		dfs(c + 1, s1 << 1, s2 << 1 | 1);
		dfs(c + 1, s1 << 1 | 1, s2 << 1);
	}
	if (c + 2 <= n) dfs(c + 2, s1 << 2 | 3, s2 << 2 | 3);
}

int main()
{
	//freopen("chess.in","r",stdin);freopen("chess.out","w",stdout);
	scanf("%d %d", &n, &m);
	if (n > m)
	{
		swap(n, m);
		fan = 1;
	}
	dp[0][(1 << n) - 1] = 1;
	for (i = 1; i <= m; i++) dfs(0, 0, 0);
	printf("%d\n", dp[m][(1 << n) - 1] % MOD);
	scanf("%d %d %d %d", &x1, &y11, &x2, &y2);
	if ((x1 + x2 + y11 + y2) & 1 && dp[m][(1 << n) - 1]) puts("yes");
	else puts("no");
	return 0;
}