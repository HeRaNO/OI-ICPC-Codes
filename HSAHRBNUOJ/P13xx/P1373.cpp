#include <cstdio>
#include <cstring>
#define MAXN 5010
using namespace std;

int c1, c2, c3, n, m;
int ans = 2147483647;
int dp[MAXN][MAXN];
char s[MAXN], t[MAXN];
int best;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int mymin3(int a, int b, int c)
{
	return mymin(mymin(a, b), c);
}

char match(char a)
{
	if (a == 'A') return 'T';
	if (a == 'G') return 'C';
	if (a == 'C') return 'G';
	if (a == 'T') return 'A';
}

int main()
{
	scanf("%d %d %d\n", &c1, &c2, &c3);
	scanf("%s", s);
	scanf("%s", t);
	n = strlen(s);
	m = strlen(t);
	for (int i = 1; i <= m; i++)
		dp[i][0] = i * c3;
	for (int i = 1; i <= n; i++)
		dp[0][i] = c2;
	for (int i = 1; i <= m; i++)
	{
		best = dp[i][0];
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j] + c3;
			int k = 1;
			while (k <= j && k <= i && s[j - k] == t[i - k])
			{
				dp[i][j] = mymin(dp[i][j], dp[i - k][j - k] + c1);
				k++;
			}
			k = 1;
			while (k <= j && k <= i && s[j - k] == match(t[i - k]))
			{
				dp[i][j] = mymin(dp[i][j], dp[i - k][j - k] + c1);
				k++;
			}
			dp[i][j] = mymin(dp[i][j], best + c2);
			best = mymin(best, dp[i][j]);
		}
	}
	for (int i = 0; i <= n; i++)
		ans = mymin(ans, dp[m][i]);
	printf("%d\n", ans);
	return 0;
}
