#include <cstdio>
#define MAXN 25
#define MAXW 15010
using namespace std;

int dis[MAXN], w[MAXN];
int c, g;
int dp[MAXN][MAXW];

int main()
{
	//freopen("overwatch.in","r",stdin);freopen("overwatch.out","w",stdout);
	scanf("%d %d", &c, &g);
	for (int i = 1; i <= c; i++) scanf("%d", &dis[i]);
	for (int i = 1; i <= g; i++) scanf("%d", &w[i]);
	dp[0][7500] = 1;
	for (int i = 1; i <= g; i++)
		for (int j = 0; j <= 15000; j++)
			if (dp[i - 1][j])
			{
				for (int k = 1; k <= c; k++)
					dp[i][j + w[i]*dis[k]] += dp[i - 1][j];
			}
	printf("%d\n", dp[g][7500]);
	return 0;
}
