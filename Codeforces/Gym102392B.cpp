#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define mem(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
int n, s1, s2;
int mx;
ll dp[1050][1050];
struct entities
{
	int x, y;
	ll t, r;
	bool operator<(const entities &X) const
	{
		return x < X.x;
	}
} a[550];

void solve()
{
	scanf("%d%d%d", &n, &s1, &s2);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%lld%d%lld", &a[i].x, &a[i].t, &a[i].y, &a[i].r);
		mx = max(mx, a[i].x);
	}
	sort(a + 1, a + n + 1);
	mem(dp, 0x3f);
	ll ans = dp[0][0], las = dp[0][0];
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = s1 + s2; j >= 0; --j)
		{
			for (int k = mx + s1; k >= 0; --k)
			{
				int v1 = min(s1 + s2, j + a[i].x);
				int v2 = min(s1 + s2, j + a[i].y);
				dp[v2][k] = min(dp[v2][k], dp[j][k] + a[i].r);
				if (k < s1 && k + a[i].x < 1000)
					dp[v1][k + a[i].x] = min(dp[v1][k + a[i].x], dp[j][k] + a[i].t);
			}
		}
	}
	for (int i = s1; i <= mx + s1; ++i)
		ans = min(ans, dp[s1 + s2][i]);
	if (ans == las)
		ans = -1;
	printf("%lld\n", ans);
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	// cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}