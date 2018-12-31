#include <cstdio>
#include <cstring>
#define MAXN 2016
using namespace std;

char a[MAXN];
char b[MAXN];
int dp[MAXN][MAXN];
int a_len, b_len;
int k;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int myabs(int a)
{
	return a > 0 ? a : -a;
}

int main()
{
	//freopen("blast.in","r",stdin);freopen("blast.out","w",stdout);
	scanf("%s", a);
	scanf("%s", b);
	scanf("%d", &k);
	a_len = strlen(a);
	b_len = strlen(b);
	dp[0][0] = 0;
	for (int i = 1; i <= a_len; i++)
		dp[i][0] = i * k;
	for (int i = 1; i <= b_len; i++)
		dp[0][i] = i * k;
	for (int i = 1; i <= a_len; i++)
		for (int j = 1; j <= b_len; j++)
			dp[i][j] = mymin(mymin(dp[i][j - 1], dp[i - 1][j]) + k, dp[i - 1][j - 1] + myabs(a[i - 1] - b[j - 1]));
	printf("%d\n", dp[a_len][b_len]);
	return 0;
}
