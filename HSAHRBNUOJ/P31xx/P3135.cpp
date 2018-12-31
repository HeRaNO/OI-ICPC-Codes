#include <cstdio>
#define MAXN 3010
using namespace std;

int dp[MAXN], a[MAXN];
int n, m;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 0; i <= n; i++) dp[i] = (n + m) * a[0];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n - i; j++)
			dp[i + j] = mymax(dp[i + j], dp[j] + a[i] - a[0]);
	printf("%d\n", dp[n]);
	return 0;
}
