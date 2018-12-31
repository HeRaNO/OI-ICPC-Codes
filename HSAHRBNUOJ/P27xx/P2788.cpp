#include <cstdio>
#include <algorithm>
#define MAXN 1010
using namespace std;

const int MOD = 1e7 + 7;
int n, m, ans;
int dp[MAXN], a[MAXN], pre[MAXN];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	//freopen("gift.in","r",stdin);freopen("gift.out","w",stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, cmp);
	for (int i = n; i; i--) pre[i] = pre[i + 1] + a[i];
	dp[0] = 1;
	if (pre[1] <= m) ans++;
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >= a[i]; j--) dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
		for (int j = m - a[i] + 1; j <= m - a[i + 1]; j++) if (j - pre[i + 1] >= 0) ans = (ans + dp[j - pre[i + 1]]) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}
