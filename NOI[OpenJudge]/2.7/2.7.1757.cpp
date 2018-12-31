//Code By HeRaNO
#include <cstdio>
using namespace std;

int n, m, a, dp[1001];

int main()
{
	scanf("%d", &n);
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		for (int j = 40; j >= a; j--)
			dp[j] += dp[j - a];
	}
	printf("%d\n", dp[40]);
	return 0;
}
