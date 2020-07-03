// By Vingying
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
const int N = 10050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
int n, k, d;
ll C[10050][105];
void initC()
{
	C[0][0] = 1;
	for (int i = 1; i <= 10000; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j <= 100; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
}
ll dp[20][N];

void solve()
{
	memarray(dp, 0);
	scanf("%d%d%d", &n, &k, &d);
	dp[0][0] = 1;
	for (int bit = 0; bit < 15; ++bit)
	{
		for (int j = 0; j * st(bit) <= n && j <= k; j += (d + 1))
		{
			for (int w = n - (k << 1); w >= j * st(bit); --w)
			{
				dp[bit + 1][w] += (dp[bit][w - j * st(bit)] * C[k][j]) % mod;
				dp[bit + 1][w] %= mod;
			}
		}
	}
	ll ans = C[n][k<<1];
	for (int w = 0; w <= n - (k << 1); ++w)
	{
		ll tmp = dp[15][w] * C[n - w - k][k] % mod;
		ans = (ans - tmp + mod) % mod;
	}
	cout << ans << '\n';
}

int main()
{
	TIME_START = clock();
	initC();
	int Test = 1;
	cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	// program_end();
	return 0;
}
