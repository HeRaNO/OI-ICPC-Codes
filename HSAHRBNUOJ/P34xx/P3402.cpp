#include <cstdio>
#define MAXN 25
using namespace std;

double dp[1 << 20], p[MAXN], cnt;
int n;
long long x, ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf %lld", &p[i], &x);
		ans += x;
	}
	printf("%lld\n", ans);
	for (int i = (1 << n) - 2; ~i; i--)
	{
		cnt = 0.0;
		for (int j = 0; j < n; j++)
			if (!(i & (1 << j)))
			{
				cnt += p[j + 1];
				dp[i] += p[j + 1] * dp[(i | (1 << j))];
			}
		dp[i] = (dp[i] + 1) / cnt;
	}
	printf("%.3lf\n", dp[0]);
	return 0;
}
