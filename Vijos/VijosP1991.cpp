#include<cstdio>
#define MAXN 10010
using namespace std;

int n, a[MAXN], dp[MAXN][MAXN], sum;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
		dp[i][i] = a[i];
	}
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= n - i; j++)
			dp[j][i + j] = mymax(a[j] - dp[j + 1][i + j], a[i + j] - dp[j][i + j - 1]);
	printf("%d\n", (sum + dp[1][n]) >> 1);
	return 0;
}
