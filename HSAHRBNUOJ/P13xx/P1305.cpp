#include <cstdio>
#define MAXN 1010
using namespace std;

int a[MAXN];
int n;
int dp[MAXN];
int ans;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	//freopen("seqgame.in","r",stdin);freopen("seqgame.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > i) continue;
		dp[i] = 1;
		for (int j = 1; j <= i; j++)
			if (dp[j] + 1 > dp[i] && a[i] - a[j] <= i - j && a[i] > a[j])
				dp[i] = dp[j] + 1;
		ans = mymax(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}
