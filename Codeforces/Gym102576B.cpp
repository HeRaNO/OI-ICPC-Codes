#include <bits/stdc++.h>
#define MAXN 2000005
using namespace std;
#define ll long long

int T, n, a[MAXN], b[MAXN], l[MAXN];
ll dp[MAXN];
long long ans;

int main(int argc, char const *argv[])
{
	scanf("%d", &T);
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		memset(b, 0, sizeof(b));
		ans = 0;
		scanf("%d", &n);
		int mx = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]), mx = max(mx, a[i]), b[a[i]]++;
		int w = 0;
		for (w = 0;; w++)
			if ((1 << w) > mx)
				break;
		for (int i = 0; i <= mx; ++i)
			dp[i] = b[i];
		for (int i = 0; i <= w; ++i)
		{
			for (int j = 1; j <= mx; ++j)
			{
				if (j & (1 << i))
					dp[j] += dp[j ^ (1 << i)];
			}
		}
		// for (int i = 0; i <= mx; ++i)
		//     printf("%lld\n", dp[i]);
		for (int i = 0; i < n; ++i)
			ans += dp[a[i]];
		printf("%lld\n", ans);
	}
	// system("pause");
	return 0;
}
