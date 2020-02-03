#include <cstdio>
#include <cstring>
#define MAXN 110
using namespace std;

int n, m;
char a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	while (~scanf("%s %s", a + 1, b + 1))
	{
		memset(dp, 0, sizeof dp);
		n = strlen(a + 1);
		m = strlen(b + 1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				dp[i][j] = mymax(dp[i - 1][j - 1] + (a[i] == b[j]), mymax(dp[i][j - 1], dp[i - 1][j]));
		printf("%d\n", n + m - dp[n][m]);
	}
	return 0;
}
