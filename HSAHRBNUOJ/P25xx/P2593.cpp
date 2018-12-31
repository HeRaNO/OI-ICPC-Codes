#include <cstdio>
#include <cstring>
using namespace std;

int m;
int dp[100010];

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	//freopen("square1.in","r",stdin);freopen("square1.out","w",stdout);
	scanf("%d", &m);
	memset(dp, 0x7f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i <= m; i++)
		for (int j = 1; j <= 17; j++)
		{
			if (i + j * j * j * j > m) break;
			dp[i + j * j * j * j] = mymin(dp[i] + 1, dp[i + j * j * j * j]);
		}
	printf("%d\n", dp[m]);
	return 0;
}
