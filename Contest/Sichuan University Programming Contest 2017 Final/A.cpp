#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	// printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	// system("pause");
#endif
}
int n, m;
double dp[100050][12];

void solve()
{
	for (int i = 0; i <= m; ++i)
		for (int j = 0; j <= n; ++j)
			dp[i][j] = 0;
	double ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += ((n * 1.0) / i);
	printf("%.6lf ", ans);
	dp[0][0] = 1;
	dp[1][1] = 1;
	if (n == 0 && m > 0)
		return puts("0.000000"), void();
	if (n == 0 && m == 0)
		return puts("1.000000"), void();
	for (int i = 1; i <= m - 1; ++i)
		for (int j = 1; j <= n - 1; ++j)
		{
			if (i > 1 || j > 1)
			{
				dp[i][j] += dp[i - 1][j - 1] * ((n - j + 1.0) / n) + dp[i - 1][j] * (j * 1.0) / n;
			}
		}
	printf("%.6lf\n", dp[m - 1][n - 1] / n);
}

int main()
{
	// TIME_START = clock();
	int Test = 1;
	// cin >> Test;
	while (~scanf("%d%d", &n, &m))
		solve();
	// TIME_END = clock();
	// program_end();
	return 0;
}