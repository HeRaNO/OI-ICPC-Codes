#include <cstdio>
#define MAXT 3010
#define POS 30
#define MAXN 6
using namespace std;

int n, m, ans;
int x, y, l, r;
int dp[MAXT][POS][3];
int a[POS][MAXT];
int locate_on_side[] = {0, 1, 2, 3, 4, 5, 6, 10, 11, 15, 16, 20, 21, 22, 23, 24, 25};
int g[POS][MAXN] =
{
	{0, 0, 0}, //0
	{3, 1, 2, 6}, //1
	{4, 1, 2, 3, 7}, //2
	{4, 2, 3, 4, 8}, //3
	{4, 3, 4, 5, 9}, //4
	{3, 4, 5, 10}, //5
	{4, 1, 6, 7, 11}, //6
	{5, 2, 6, 7, 8, 12}, //7
	{5, 3, 7, 8, 9, 13}, //8
	{5, 4, 8, 9, 10, 14}, //9
	{4, 5, 9, 10, 15}, //10
	{4, 6, 11, 12, 16}, //11
	{5, 7, 11, 12, 13, 17}, //12
	{5, 8, 12, 13, 14, 18}, //13
	{5, 9, 13, 14, 15, 19}, //14
	{4, 10, 14, 15, 20}, //15
	{4, 11, 16, 17, 21}, //16
	{5, 12, 16, 17, 18, 22}, //17
	{5, 13, 17, 18, 19, 23}, //18
	{5, 14, 18, 19, 20, 24}, //19
	{4, 15, 19, 20, 25}, //20
	{3, 16, 21, 22}, //21
	{4, 17, 21, 22, 23}, //22
	{4, 18, 22, 23, 24}, //23
	{4, 19, 23, 24, 25}, //24
	{3, 20, 24, 25} //25
};

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d %d", &x, &y, &l, &r);
		for (int j = l; j <= r; j++) a[x * 5 + y - 5][j] = 1;
	}
	for (int i = 1; i <= 25; i++) if (a[i][1]) dp[1][i][1] = 1;
	for (int i = 2; i <= m; i++)
	{
		for (int j = 1; j <= 16; j++) dp[i][0][0] = mymax(dp[i][0][0], dp[i - 1][locate_on_side[j]][2]);
		for (int j = 1; j <= 16; j++) dp[i][locate_on_side[j]][1] = dp[i - 1][0][0] + a[locate_on_side[j]][i];
		for (int j = 1; j <= 25; j++)
			for (int k = 1; k <= g[j][0]; k++)
				dp[i][j][2] = mymax(dp[i][j][2], mymax(dp[i - 1][g[j][k]][1], dp[i - 1][g[j][k]][2]) + a[j][i]);
	}
	ans = dp[m][0][0];
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= 25; j++)
			ans = mymax(ans, dp[m][j][i]);
	printf("%d\n", ans);
	return 0;
}
