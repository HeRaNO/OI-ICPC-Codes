#include <cstdio>
#include <cstring>
#define MAXN 10010
using namespace std;

char a[MAXN];
char b[MAXN];
int dp[2][MAXN];
int a_len, b_len;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%s", a);
	scanf("%s", b);
	a_len = strlen(a);
	b_len = strlen(b);
	for (int i = 1; i <= b_len; i++)
		dp[0][i] = i;
	for (int i = 1; i <= a_len; i++)
	{
		dp[i & 1][0] = i;
		for (int j = 1; j <= b_len; j++)
		{
			if (a[i - 1] == b[j - 1])
				dp[i & 1][j] = mymin(mymin(dp[i & 1][j - 1], dp[i - 1 & 1][j]) + 1, dp[i - 1 & 1][j - 1]);
			else dp[i & 1][j] = mymin(mymin(dp[i & 1][j - 1], dp[i - 1 & 1][j]) + 1, dp[i - 1 & 1][j - 1] + 1);
		}
	}
	printf("%d\n", dp[a_len & 1][b_len]);
	return 0;
}
