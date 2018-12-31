#include <cstdio>
#include <cstring>
#define MAXN 1100
#define MAXD 33000
using namespace std;

int up[MAXN], down[MAXN];
int i, n, m;
int dp[MAXN][MAXN];
int up_pos[MAXD], down_pos[MAXD];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &up[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &down[i]);
	for (int i = 1; i <= n; i++)
	{
		memset(down_pos, 0, sizeof(down_pos));
		up_pos[up[i]] = i;
		for (int j = 1; j <= m; j++)
		{
			down_pos[down[j]] = j;
			dp[i][j] = mymax(dp[i][j - 1], dp[i - 1][j]);
			if (up[i] != down[j] && down_pos[up[i]] && up_pos[down[j]])
				dp[i][j] = mymax(dp[i][j], dp[up_pos[down[j]] - 1][down_pos[up[i]] - 1] + 2);
		}
	}
	printf("%d\n", dp[n][m]);
	return 0;
}
