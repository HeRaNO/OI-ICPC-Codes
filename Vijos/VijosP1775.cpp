#include <cstdio>
#define MAXN 41
using namespace std;

int dp[MAXN][MAXN][MAXN][MAXN];
int card[5], a[351];
int n, m;
int i, j, k, l, flag;
int pos;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	//freopen("tortoise.in","r",stdin);freopen("tortoise.out","w",stdout);
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &flag);
		card[flag]++;
	}
	dp[0][0][0][0] = a[1];
	for (i = 0; i <= card[1]; i++)
		for (j = 0; j <= card[2]; j++)
			for (k = 0; k <= card[3]; k++)
				for (l = 0; l <= card[4]; l++)
				{
					pos = i + j * 2 + k * 3 + l * 4 + 1;
					if (i > 0) dp[i][j][k][l] = mymax(dp[i][j][k][l], dp[i - 1][j][k][l] + a[pos]);
					if (j > 0) dp[i][j][k][l] = mymax(dp[i][j][k][l], dp[i][j - 1][k][l] + a[pos]);
					if (k > 0) dp[i][j][k][l] = mymax(dp[i][j][k][l], dp[i][j][k - 1][l] + a[pos]);
					if (l > 0) dp[i][j][k][l] = mymax(dp[i][j][k][l], dp[i][j][k][l - 1] + a[pos]);
				}
	printf("%d", dp[card[1]][card[2]][card[3]][card[4]]);
	return 0;
}