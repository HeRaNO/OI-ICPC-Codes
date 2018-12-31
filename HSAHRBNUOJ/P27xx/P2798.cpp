#include <cstdio>
#define MAXN 24
#define MOD 5462617
using namespace std;

int n, k;
int dp[1 << MAXN], a[1 << MAXN], no[3];

__attribute__((__optimize__("O2"))) inline int lowbit(int x)
{
	return x & (-x);
}

__attribute__((__optimize__("O2"))) int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[1 << (i - 1)]);
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) scanf("%d", &no[i]);
	dp[0] = 1;
	for (int i = 1; i < (1 << n); i++)
	{
		int len = 0, j, now;
		j = i;
		now = lowbit(j);
		while (j)
		{
			dp[i] = (dp[i ^ now] + dp[i]) % MOD;
			len += a[now];
			j ^= now;
			now = lowbit(j);
		}
		if (len == no[1] || len == no[2]) dp[i] = 0;
	}
	printf("%d\n", dp[(1 << n) - 1]);
	return 0;
}
