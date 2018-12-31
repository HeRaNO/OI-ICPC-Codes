#include <cstdio>
#include <cstring>
#define MAXL 1010
#define MAXM 5500
using namespace std;

int m, n;
char num[MAXL];
int dp[MAXL][MAXM];
int mod_num[MAXL][MAXL];
int best, pos;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	//freopen("chars.in","r",stdin);freopen("chars.out","w",stdout);
	scanf("%s", num);
	scanf("%d", &m);
	n = strlen(num);
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			mod_num[i + 1][j + 1] = (mod_num[i + 1][j] * 10 + num[j] - '0') % m;
	memset(dp, 0x7f, sizeof(dp));
	dp[0][1] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			for (int k = 0; k < m; k++)
				dp[i][(k * mod_num[j + 1][i]) % m] = mymin(dp[j][k] + 1, dp[i][(k * mod_num[j + 1][i]) % m]);
	for (int i = 0; i < m - 1; i++)
	{
		if (dp[n][i] != 0x7f7f7f7f)
		{
			printf("%d %d ", i, dp[n][i] - 1);
			break;
		}
	}
	for (int i = m - 1; ~i; i--)
	{
		if (dp[n][i] != 0x7f7f7f7f)
		{
			printf("%d %d\n", i, dp[n][i] - 1);
			break;
		}
	}
	return 0;
}
