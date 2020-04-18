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
using namespace std;
const int N = 150;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
int n;
int k;
int a[N];
ll dp[N][N];
set<int> s;

void solve()
{
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 1; i <= k; ++i)
		scanf("%d", &a[i]);
	memarray(dp, 0);
	s.clear();
	for (int i = 1; i <= n; ++i)
		s.insert(i);
	int mx = 0;
	for (int i = 1; i <= k; ++i)
	{
		if (mx < a[i])
			mx = a[i];
		else if (a[i] != *s.begin())
		{
			puts("0");
			return;
		}
		s.erase(a[i]);
	}
	dp[k][mx] = 1;
	for (int j = 0; j <= n; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int u = j + 1; u <= n; ++u)
				dp[i + 1][u] += dp[i][j], dp[i + 1][u] %= mod;
			if (j > i)
				dp[i + 1][j] += dp[i][j], dp[i + 1][j] %= mod;
		}
	}
	printf("%lld\n", dp[n][n]);
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	int kase = 0;
	cin >> Test;
	while (Test--)
		printf("Case #%d: ", ++kase), solve();
	TIME_END = clock();
	program_end();
	return 0;
}