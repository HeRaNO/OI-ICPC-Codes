#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 5001
using namespace std;

int n;
char c;
char a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", a + 1);
	for (int i = 1; i <= n; i++)
		b[n - i + 1] = a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = mymax(dp[i - 1][j], dp[i][j - 1]);
		}
	printf("%d\n", n - dp[n][n]);
	return 0;
}