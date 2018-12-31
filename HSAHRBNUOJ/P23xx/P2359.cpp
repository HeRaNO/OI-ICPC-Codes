#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

int dp[1000][101];
int w, h, n = 1;
int maxt = INT_MIN;
int v[1000][101];
int a, b, c, d;
int ans;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d %d", &w, &h);
	while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF)
	{
		n++;
		if ((h - 1) % c) continue;
		else v[(h - 1) / c + a][b] += d;
		maxt = mymax(maxt, (h - 1) / c + a);
		ans += d;
	}
	n--;
	if (!n)
	{
		printf("0\n");
		return 0;
	}
	if (w == 1)
	{
		printf("%d\n", ans);
		return 0;
	}
	dp[0][w / 2 + 1] = v[0][w / 2 + 1];
	for (int i = 1; i <= maxt; i++)
		for (int j = 1; j <= w + 1; j++)
			for (int k = -2; k <= 2; k++)
				if (j + k >= 0 && j + k <= w)
					dp[i][j] = mymax(dp[i][j], dp[i - 1][j + k] + v[i][j]);
	ans = 0;
	for (int i = 1; i <= w; i++)
		ans = mymax(ans, dp[maxt][i]);
	printf("%d\n", ans);
	return 0;
}