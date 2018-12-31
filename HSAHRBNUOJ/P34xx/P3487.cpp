#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
#define MAXT 3010
using namespace std;

struct score
{
	int st, dec, t;
};

score a[MAXN];
int n, T, t, ans, c;
int dp[MAXT];

bool cmp(score a, score b)
{
	return a.dec * b.t > b.dec * a.t;
}

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &t);
		for (int i = 1; i <= n; i++) scanf("%d %d %d", &a[i].st, &a[i].dec, &a[i].t);
		sort(a + 1, a + n + 1, cmp);
		ans = 0;
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; i++)
		{
			c = a[i].st - a[i].dec * t;
			for (int j = t; j >= a[i].t; j--, c += a[i].dec)
				dp[j] = mymax(dp[j], dp[j - a[i].t] + c);
		}
		for (int i = 0; i <= t; i++) ans = mymax(ans, dp[i]);
		printf("%d\n", ans);
	}
	return 0;
}
