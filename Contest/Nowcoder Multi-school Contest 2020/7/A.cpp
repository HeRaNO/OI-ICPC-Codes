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
#define vecfirst (*vec.begin())
#define veclast (*vec.rbegin())
#define vecall(v) (v).begin(), (v).end()
#define vecupsort(v) (sort((v).begin(), (v).end()))
#define vecdownsort(v, type) (sort(vecall(v), greater<type>()))
#define veccmpsort(v, cmp) (sort(vecall(v), cmp))
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353LL;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
	system("pause");
#endif
}
const int delta = 250;
int n, r;
int vis[15][40];
int dp[10][500][500];

void solve()
{
	scanf("%d%d", &n, &r);
	if (n % 2 == 0)
		return printf("%d\n", n * n * r * r), void();
	if (vis[n][r] != -1)
		return printf("%d\n", vis[n][r]), void();
	int ans = 0;
	memarray(dp, 0);
	for (int i = 0; i <= n; ++i)
		for (int j = delta - n * r; j <= delta + n * r; ++j)
			for (int k = delta - n * r; k <= delta + n * r; ++k)
				dp[i][j][k] = -1;
	dp[0][delta][delta] = 0;
	for (int x = -r; x <= r; ++x)
		for (int y = -r; y <= r; ++y)
			if (x * x + y * y <= r * r)
				dp[1][x + delta][y + delta] = 0;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = -r; j <= r; ++j)
		{
			int k = sqrt(r * r - j * j);
			for (int x = delta - (i - 1) * r; x <= delta + (i - 1) * r; ++x)
				for (int y = delta - (i - 1) * r; y <= delta + (i - 1) * r; ++y)
				{
					if (dp[i - 1][x][y] == -1)
						continue;
					int xx = x - delta, yy = y - delta;
					dp[i][x + j][y + k] = max(dp[i][x + j][y + k], dp[i - 1][x][y] + (i - 1) * (j * j + k * k) - 2 * (j * xx + k * yy) + (xx * xx + yy * yy + dp[i - 1][x][y]) / (i - 1));
					dp[i][x + j][y - k] = max(dp[i][x + j][y - k], dp[i - 1][x][y] + (i - 1) * (j * j + k * k) - 2 * (j * xx - k * yy) + (xx * xx + yy * yy + dp[i - 1][x][y]) / (i - 1));
				}
		}
	}
	for (int x = delta - n * r; x <= delta + n * r; ++x)
		for (int y = delta - n * r; y <= delta + n * r; ++y)
			ans = max(ans, dp[n][x][y]);
	printf("%d\n", vis[n][r] = ans);
}

int main()
{
	TIME__START = clock();
	memarray(vis, -1);
	int Test = 1;
	scanf("%d", &Test);
	while (Test--)
		solve();
	TIME__END = clock();
	program_end();
	return 0;
}